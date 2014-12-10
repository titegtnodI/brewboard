/* 
 * File:   brewboard.h
 * Author: titegtnodI
 *
 * Created on December 9, 2014, 9:49 PM
 */

#ifndef BREWBOARD_H
#define	BREWBOARD_H

#ifdef	__cplusplus
extern "C" {
#endif

void bbDisplayText(char* text);
char* bbHandleKeyboard();
char* bbHandleKeyboardBlocking(char* text);

#ifdef	__cplusplus
}
#endif

#endif	/* BREWBOARD_H */

