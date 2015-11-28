/* 
 * File containing functions for obtaining the configuration of 
 * the environment, such as the location of the remote servers.
 * 
 * File:   config.h
 * Author: Vinicius Souza
 *
 * Created on October 26, 2015, 10:45 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

extern char centralHost[30];
extern int centralPort;

extern char displayHost[30];
extern int displayPort;

void readConfig(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

