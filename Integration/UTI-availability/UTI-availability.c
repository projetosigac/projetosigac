#include <stdio.h>
#include <stdlib.h>

#include "CommunicationInterfaces.h"
#include "OperatorInformation.h"

operator_input_type ua_inputs;
operator_output_type ua_outputs;

void receiveMessage(FRAMEWORK_MESSAGE message) {
    /*UTI_COUNTS_INPUT_INTERFACE input;

    if (message.to == UTI_COUNTS) {
        input = message.input_interface.uti_counts_input_interface;
        switch (message.from) {
        case UTI_AVAILABILITY:
            printf("Received: Message from UTI_AVAILABILITY to UTI_COUNTS \n");
            ua_inputs.availableInput = input.availableInput;
            ua_inputs.occupiedInput = input.occupiedInput;
            ua_inputs.totalInput = input.totalInput;
            break;
        }
    }*/
}

void buildMessage(FRAMEWORK_MESSAGE *message) {
    message->from = UTI_AVAILABILITY;
    switch (message->to) {
    case UTI_COUNTS:
        printf("Sent: Message from UTI_AVAILABILITY to UTI_COUNTS \n");
        UTI_COUNTS_INPUT_INTERFACE *output = &(message->input_interface.uti_counts_input_interface);
        output->availableInput = ua_outputs.FreeBedsCount;
        output->occupiedInput = ua_outputs.AllocatedBedsCount;
        output->totalInput = ua_outputs.ActiveBedsCount;
    }
}

void executeOperator() {
    UTI(&ua_inputs, &ua_outputs);
}

void clear_ua_inputs() {
    ua_receive_clear(&ua_inputs, NULL);
}

void clear_ua_outputs() {
    UTI_reset(&ua_outputs);
}

void initializeCustomLogic() {
    /* Insert your additional logic */
    /* For instance, you can initialize your RaspberryPi controller here */
}

void executeCustomLogic() {
    /* Insert your additional logic */
    /* For instance, you can execute your RaspberryPi controller here */
    /* You can use ua_outputs (which is updated before this function is called) to feed you controller */
}
