#ifndef COMMUNICATIONINTERFACES_H
#define COMMUNICATIONINTERFACES_H

#include "kcg_types.h"
#include "kcg_consts.h"

#define UTI_AVAILABILITY 1
#define UTI_COUNTS 2

typedef struct {
    kcg_real availableInput;
    kcg_real occupiedInput;
    kcg_real totalInput;
} UTI_COUNTS_INPUT_INTERFACE;

typedef union {
	UTI_COUNTS_INPUT_INTERFACE uti_counts_input_interface;
} INPUT_INTERFACE;

typedef struct {
	int to, from;
    INPUT_INTERFACE input_interface;
} FRAMEWORK_MESSAGE;

#define MSG_SIZE 2048

#endif