/* 
 * File containing utility functions.
 * 
 * File:   utils.h
 * Author: Vinicius Souza
 *
 * Created on October 26, 2015, 11:12 PM
 */

#ifndef UTILS_H
#define	UTILS_H

#define log_error(str)     fprintf(stderr, str);
#define log(str)           fprintf(stdin, str);

#ifdef  DEBUG   
#define debug printf
#else
#define debug
#endif

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef enum { false, true } bool;    


char* trim(char *str);


#ifdef	__cplusplus
}
#endif

#endif	/* UTILS_H */

