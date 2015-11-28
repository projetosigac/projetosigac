/* 
 * File containing functions for handling real time 
 * processing.
 * 
 * File:   realtime.h
 * Author: Vinicius Souza
 *
 * Created on October 28, 2015, 11:09 PM
 */

#ifndef REALTIME_H
#define	REALTIME_H

#ifdef	__cplusplus
extern "C" {
#endif

    void loopInTimeWindow(unsigned long duration, void (*f)(void));
    unsigned long timeInSeconds(void);

#ifdef	__cplusplus
}
#endif

#endif	/* REALTIME_H */

