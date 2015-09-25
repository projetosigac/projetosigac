#ifndef _SURGERYCOUNTS_MACRO_H_
#define _SURGERYCOUNTS_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file SurgeryCounts_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "SurgeryCounts.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_SurgeryCounts SAO_CTX_inC_SurgeryCounts;
    outC_SurgeryCounts SAO_CTX_outC_SurgeryCounts;
} WU_SurgeryCounts;
#define WU_CTX_TYPE_SurgeryCounts WU_SurgeryCounts
#define WU_CTX_TYPE_SurgeryCounts_SIZE sizeof(WU_SurgeryCounts)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_SurgeryCounts() 

#define DECLARE_EXT_SENSORS_SurgeryCounts(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_SurgeryCounts_availableInput(context) context.SAO_CTX_inC_SurgeryCounts.availableInput  /* SurgeryCounts/availableInput */
#define VAR_SurgeryCounts_availableInput VARC_SurgeryCounts_availableInput(CTX_SurgeryCounts)

#define VARC_SurgeryCounts_occupiedInput(context) context.SAO_CTX_inC_SurgeryCounts.occupiedInput  /* SurgeryCounts/occupiedInput */
#define VAR_SurgeryCounts_occupiedInput VARC_SurgeryCounts_occupiedInput(CTX_SurgeryCounts)

#define VARC_SurgeryCounts_totalInput(context) context.SAO_CTX_inC_SurgeryCounts.totalInput  /* SurgeryCounts/totalInput */
#define VAR_SurgeryCounts_totalInput VARC_SurgeryCounts_totalInput(CTX_SurgeryCounts)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_SurgeryCounts_EmitToCDS(context) context.SAO_CTX_outC_SurgeryCounts.EmitToCDS  /* SurgeryCounts/EmitToCDS */
#define VAR_SurgeryCounts_EmitToCDS VARC_SurgeryCounts_EmitToCDS(CTX_SurgeryCounts)

#define VARC_SurgeryCounts_LayerVisible(context) context.SAO_CTX_outC_SurgeryCounts.LayerVisible  /* SurgeryCounts/LayerVisible */
#define VAR_SurgeryCounts_LayerVisible VARC_SurgeryCounts_LayerVisible(CTX_SurgeryCounts)

#define VARC_SurgeryCounts_availableOutput(context) context.SAO_CTX_outC_SurgeryCounts.availableOutput  /* SurgeryCounts/availableOutput */
#define VAR_SurgeryCounts_availableOutput VARC_SurgeryCounts_availableOutput(CTX_SurgeryCounts)

#define VARC_SurgeryCounts_occupiedOutput(context) context.SAO_CTX_outC_SurgeryCounts.occupiedOutput  /* SurgeryCounts/occupiedOutput */
#define VAR_SurgeryCounts_occupiedOutput VARC_SurgeryCounts_occupiedOutput(CTX_SurgeryCounts)

#define VARC_SurgeryCounts_totalOutput(context) context.SAO_CTX_outC_SurgeryCounts.totalOutput  /* SurgeryCounts/totalOutput */
#define VAR_SurgeryCounts_totalOutput VARC_SurgeryCounts_totalOutput(CTX_SurgeryCounts)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_availableInput kcg_real
#define CPY_availableInput(DST, SRC) DST = SRC
#define T_occupiedInput kcg_real
#define CPY_occupiedInput(DST, SRC) DST = SRC
#define T_totalInput kcg_real
#define CPY_totalInput(DST, SRC) DST = SRC
#define T_EmitToCDS kcg_bool
#define CPY_EmitToCDS(DST, SRC) DST = SRC
#define T_LayerVisible kcg_bool
#define CPY_LayerVisible(DST, SRC) DST = SRC
#define T_availableOutput kcg_real
#define CPY_availableOutput(DST, SRC) DST = SRC
#define T_occupiedOutput kcg_real
#define CPY_occupiedOutput(DST, SRC) DST = SRC
#define T_totalOutput kcg_real
#define CPY_totalOutput(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_SurgeryCounts(context)  WU_SurgeryCounts context;

#define DECLARE_CTXT_SurgeryCounts() DECLAREC_CTXT_SurgeryCounts(CTX_SurgeryCounts)

#define DECLAREC_EXT_CTXT_SurgeryCounts(MODE , context) MODE WU_SurgeryCounts context;

#define DECLARE_EXT_CTXT_SurgeryCounts(MODE) DECLAREC_EXT_CTXT_SurgeryCounts(MODE , CTX_SurgeryCounts)

#define INITC_SurgeryCounts(context) SurgeryCounts_reset(&context.SAO_CTX_outC_SurgeryCounts)
#define INIT_SurgeryCounts() INITC_SurgeryCounts(CTX_SurgeryCounts)

#define PERFORMC_SurgeryCounts(context) 	SurgeryCounts( \
		&context.SAO_CTX_inC_SurgeryCounts /* input context */,\
		&context.SAO_CTX_outC_SurgeryCounts /* output/memories context */\
	)

#define PERFORM_SurgeryCounts() PERFORMC_SurgeryCounts(CTX_SurgeryCounts)

/*$************** SCADE Macro wrapper *********************
** End of file SurgeryCounts_macro.h
***********************************************************$*/

#endif /* _SURGERYCOUNTS_MACRO_H_ */
