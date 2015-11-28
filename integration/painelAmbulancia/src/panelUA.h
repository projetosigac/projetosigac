/* 
 * Glue-code for the SCADE operator of the ambulance panel.
 * 
 * File:   panelUA.h
 * Author: Vinicius Souza
 *
 * Created on October 27, 2015, 8:28 PM
 */

#ifndef PANELUA_H
#define	PANELUA_H

#include "utils.h"
#include "alertaOcorrencia.h"
#include "kcg_types.h"


#ifdef	__cplusplus
extern "C" {
#endif

	/**
	 * Execute the AlertaOcorrencia operator.
	 *
	 * @param input the input for the operator.
	 * @param output the output of the operator.
	 */
    void executeAlertaOcorrenciaUA(inC_alertaOcorrencia* input, outC_alertaOcorrencia* output);

    void clearInputs(inC_alertaOcorrencia* input);

    void clearOutput(outC_alertaOcorrencia* output);

#ifdef	__cplusplus
}
#endif

#endif	/* PANELUA_H */

