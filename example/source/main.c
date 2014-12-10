#include <3ds.h>
#include <string.h>

#include "textstuff.h"
#include "brewboard.h"

int main() {
    // Initialize services
    srvInit();
    aptInit();
    hidInit(NULL);
    gfxInit();
    //gfxSet3D(true); // uncomment if using stereoscopic 3D
    
    char* a = "";

    // Main loop
    while (aptMainLoop() && strcmp(a, "q") != 0)
    {
        gspWaitForVBlank();
        hidScanInput();

        // Your code goes here

        u32 kDown = hidKeysDown();
        if (kDown & KEY_START)
            break; // break in order to return to hbmenu

        a = bbHandleKeyboardBlocking("");
        
        u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
        memset(fb, 0, 240*400*3);
        tsDrawWord(GFX_TOP, GFX_LEFT, a, 40, 50, 255, 255, 255);

        // Flush and swap framebuffers
        gfxFlushBuffers();
        gfxSwapBuffers();
    }

    // Exit services
    gfxExit();
    hidExit();
    aptExit();
    srvExit();
    return 0;
}
