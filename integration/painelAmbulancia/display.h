/* 
 * File with functions for interacting with the display API.
 * 
 * File:   display.h
 * Author: Vinicius Souza
 *
 * Created on October 27, 2015, 8:41 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

    void connectToDisplayServer(void);
    void releaseDisplayConnection(void);
    
    void readPanelSignals(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

