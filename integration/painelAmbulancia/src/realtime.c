#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "realtime.h"
#include "utils.h"

#define NANO_SEC_TO_MILLIS 1000000l
#define MILLIS_TO_MICRO	   1000l

void loopInTimeWindow(unsigned long duration, void (*f)(void)){
    unsigned long t1, t2, diff;
    struct timespec clock;
    
    while (1) {
        clock_gettime(CLOCK_REALTIME, &clock);
        t1 = clock.tv_nsec;
        
        (*f)();
        
        clock_gettime(CLOCK_REALTIME, &clock);
        t2 = clock.tv_nsec;
        diff = (t2 - t1) / NANO_SEC_TO_MILLIS;
        if (diff > duration) {
            debug("Timing: cycle delayed by %d milliseconds! \n", (int)diff);
        } else {
            unsigned long sleepTime = (duration - diff)*MILLIS_TO_MICRO;
            usleep(sleepTime);
        }
    }
}

unsigned long timeInSeconds(void) {
	struct timespec clock;
	clock_gettime(CLOCK_REALTIME, &clock);
	return clock.tv_sec;
}
