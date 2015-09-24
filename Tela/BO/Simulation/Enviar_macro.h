#ifndef _ENVIAR_MACRO_H_
#define _ENVIAR_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file Enviar_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "Enviar.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_Enviar SAO_CTX_inC_Enviar;
    outC_Enviar SAO_CTX_outC_Enviar;
} WU_Enviar;
#define WU_CTX_TYPE_Enviar WU_Enviar
#define WU_CTX_TYPE_Enviar_SIZE sizeof(WU_Enviar)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_Enviar() 

#define DECLARE_EXT_SENSORS_Enviar(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_Enviar_enviar(context) context.SAO_CTX_inC_Enviar.enviar  /* Enviar/enviar */
#define VAR_Enviar_enviar VARC_Enviar_enviar(CTX_Enviar)

#define VARC_Enviar_sinal_completo(context) context.SAO_CTX_inC_Enviar.sinal_completo  /* Enviar/sinal_completo */
#define VAR_Enviar_sinal_completo VARC_Enviar_sinal_completo(CTX_Enviar)

#define VARC_Enviar_rg(context) context.SAO_CTX_inC_Enviar.rg  /* Enviar/rg */
#define VAR_Enviar_rg VARC_Enviar_rg(CTX_Enviar)

#define VARC_Enviar_hora_fim_atend(context) context.SAO_CTX_inC_Enviar.hora_fim_atend  /* Enviar/hora_fim_atend */
#define VAR_Enviar_hora_fim_atend VARC_Enviar_hora_fim_atend(CTX_Enviar)

#define VARC_Enviar_hora_ini_atend(context) context.SAO_CTX_inC_Enviar.hora_ini_atend  /* Enviar/hora_ini_atend */
#define VAR_Enviar_hora_ini_atend VARC_Enviar_hora_ini_atend(CTX_Enviar)

#define VARC_Enviar_dt_fim_atend(context) context.SAO_CTX_inC_Enviar.dt_fim_atend  /* Enviar/dt_fim_atend */
#define VAR_Enviar_dt_fim_atend VARC_Enviar_dt_fim_atend(CTX_Enviar)

#define VARC_Enviar_dt_ini_atend(context) context.SAO_CTX_inC_Enviar.dt_ini_atend  /* Enviar/dt_ini_atend */
#define VAR_Enviar_dt_ini_atend VARC_Enviar_dt_ini_atend(CTX_Enviar)

#define VARC_Enviar_hora_fato(context) context.SAO_CTX_inC_Enviar.hora_fato  /* Enviar/hora_fato */
#define VAR_Enviar_hora_fato VARC_Enviar_hora_fato(CTX_Enviar)

#define VARC_Enviar_dt_fato(context) context.SAO_CTX_inC_Enviar.dt_fato  /* Enviar/dt_fato */
#define VAR_Enviar_dt_fato VARC_Enviar_dt_fato(CTX_Enviar)

#define VARC_Enviar_description(context) context.SAO_CTX_inC_Enviar.description  /* Enviar/description */
#define VAR_Enviar_description VARC_Enviar_description(CTX_Enviar)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_Enviar_BO_saida(context) context.SAO_CTX_outC_Enviar.BO_saida  /* Enviar/BO_saida */
#define VAR_Enviar_BO_saida VARC_Enviar_BO_saida(CTX_Enviar)

#define VARC_Enviar_saida_pronta(context) context.SAO_CTX_outC_Enviar.saida_pronta  /* Enviar/saida_pronta */
#define VAR_Enviar_saida_pronta VARC_Enviar_saida_pronta(CTX_Enviar)

#define VARC_Enviar_Layer1Visible(context) context.SAO_CTX_outC_Enviar.Layer1Visible  /* Enviar/Layer1Visible */
#define VAR_Enviar_Layer1Visible VARC_Enviar_Layer1Visible(CTX_Enviar)

#define VARC_Enviar_Layer1Active(context) context.SAO_CTX_outC_Enviar.Layer1Active  /* Enviar/Layer1Active */
#define VAR_Enviar_Layer1Active VARC_Enviar_Layer1Active(CTX_Enviar)

#define VARC_Enviar_Emit2CDS(context) context.SAO_CTX_outC_Enviar.Emit2CDS  /* Enviar/Emit2CDS */
#define VAR_Enviar_Emit2CDS VARC_Enviar_Emit2CDS(CTX_Enviar)

#define VARC_Enviar_TextBtnEnviar(context) context.SAO_CTX_outC_Enviar.TextBtnEnviar  /* Enviar/TextBtnEnviar */
#define VAR_Enviar_TextBtnEnviar VARC_Enviar_TextBtnEnviar(CTX_Enviar)

#define VARC_Enviar_StringSize(context) context.SAO_CTX_outC_Enviar.StringSize  /* Enviar/StringSize */
#define VAR_Enviar_StringSize VARC_Enviar_StringSize(CTX_Enviar)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_enviar kcg_bool
#define CPY_enviar(DST, SRC) DST = SRC
#define T_sinal_completo kcg_bool
#define CPY_sinal_completo(DST, SRC) DST = SRC
#define T_rg String
#define CPY_rg(DST, SRC) kcg_copy_String(DST, SRC)
#define T_hora_fim_atend String
#define CPY_hora_fim_atend(DST, SRC) kcg_copy_String(DST, SRC)
#define T_hora_ini_atend String
#define CPY_hora_ini_atend(DST, SRC) kcg_copy_String(DST, SRC)
#define T_dt_fim_atend String
#define CPY_dt_fim_atend(DST, SRC) kcg_copy_String(DST, SRC)
#define T_dt_ini_atend String
#define CPY_dt_ini_atend(DST, SRC) kcg_copy_String(DST, SRC)
#define T_hora_fato String
#define CPY_hora_fato(DST, SRC) kcg_copy_String(DST, SRC)
#define T_dt_fato String
#define CPY_dt_fato(DST, SRC) kcg_copy_String(DST, SRC)
#define T_description BigText
#define CPY_description(DST, SRC) kcg_copy_BigText(DST, SRC)
#define T_BO_saida Boletim
#define CPY_BO_saida(DST, SRC) kcg_copy_Boletim(DST, SRC)
#define T_saida_pronta kcg_bool
#define CPY_saida_pronta(DST, SRC) DST = SRC
#define T_Layer1Visible kcg_bool
#define CPY_Layer1Visible(DST, SRC) DST = SRC
#define T_Layer1Active kcg_bool
#define CPY_Layer1Active(DST, SRC) DST = SRC
#define T_Emit2CDS kcg_bool
#define CPY_Emit2CDS(DST, SRC) DST = SRC
#define T_TextBtnEnviar Name
#define CPY_TextBtnEnviar(DST, SRC) kcg_copy_Name(DST, SRC)
#define T_StringSize kcg_int
#define CPY_StringSize(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_Enviar(context)  WU_Enviar context;

#define DECLARE_CTXT_Enviar() DECLAREC_CTXT_Enviar(CTX_Enviar)

#define DECLAREC_EXT_CTXT_Enviar(MODE , context) MODE WU_Enviar context;

#define DECLARE_EXT_CTXT_Enviar(MODE) DECLAREC_EXT_CTXT_Enviar(MODE , CTX_Enviar)

#define INITC_Enviar(context) Enviar_reset(&context.SAO_CTX_outC_Enviar)
#define INIT_Enviar() INITC_Enviar(CTX_Enviar)

#define PERFORMC_Enviar(context) 	Enviar( \
		&context.SAO_CTX_inC_Enviar /* input context */,\
		&context.SAO_CTX_outC_Enviar /* output/memories context */\
	)

#define PERFORM_Enviar() PERFORMC_Enviar(CTX_Enviar)

/*$************** SCADE Macro wrapper *********************
** End of file Enviar_macro.h
***********************************************************$*/

#endif /* _ENVIAR_MACRO_H_ */
