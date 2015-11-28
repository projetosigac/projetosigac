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

#include "ua.h"
#include "display.h"


#ifdef	__cplusplus
extern "C" {
#endif

	/**
	 * Connect to the A661 display server.
	 *
	 * This function must be called before any other data exchange.
	 */
    void connectToDisplayServer(void);

    /**
     * Release the socket connection with the A661 display server.
     *
     */
    void releaseDisplayConnection(void);
    
    /**
     * Send the output of the operator to the A661 display server.
     *
     * @param operatorOut the output of the AlertaOcorrencia operator.
     */
    void sendAlertaOcorrencia(outC_alertaOcorrencia* operatorOut);

    /**
     * Receive the inputs of the AlertaOcorrencia operator filled by the A661 server.
     *
     * @param operatorInput the input for the AlertaOcorrencia operator.
     */
    void receiveAlertaOcorrencia(inC_alertaOcorrencia* operatorInput);


#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

