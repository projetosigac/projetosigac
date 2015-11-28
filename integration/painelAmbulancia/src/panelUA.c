/* 
 * File:   panelUA.c
 * Author: Vinicius Souza
 *
 * Created on October 27, 2015, 8:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "ua.h"
#include "panelUA.h"

void clearInputs(inC_alertaOcorrencia* input) {
	ua_receive_clear(input, NULL);
}

void clearOutput(outC_alertaOcorrencia* output) {
	alertaOcorrencia_reset(output);
}

void executeAlertaOcorrenciaUA(inC_alertaOcorrencia* input,
		outC_alertaOcorrencia* output) {
	alertaOcorrencia(input, output);	
}

