#ifndef _XRAYCOUNTS_MACRO_H_
#define _XRAYCOUNTS_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file XRayCounts_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "XRayCounts.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_XRayCounts SAO_CTX_inC_XRayCounts;
    outC_XRayCounts SAO_CTX_outC_XRayCounts;
} WU_XRayCounts;
#define WU_CTX_TYPE_XRayCounts WU_XRayCounts
#define WU_CTX_TYPE_XRayCounts_SIZE sizeof(WU_XRayCounts)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_XRayCounts() 

#define DECLARE_EXT_SENSORS_XRayCounts(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_XRayCounts_availableInput(context) context.SAO_CTX_inC_XRayCounts.availableInput  /* XRayCounts/availableInput */
#define VAR_XRayCounts_availableInput VARC_XRayCounts_availableInput(CTX_XRayCounts)

#define VARC_XRayCounts_occupiedInput(context) context.SAO_CTX_inC_XRayCounts.occupiedInput  /* XRayCounts/occupiedInput */
#define VAR_XRayCounts_occupiedInput VARC_XRayCounts_occupiedInput(CTX_XRayCounts)

#define VARC_XRayCounts_totalInput(context) context.SAO_CTX_inC_XRayCounts.totalInput  /* XRayCounts/totalInput */
#define VAR_XRayCounts_totalInput VARC_XRayCounts_totalInput(CTX_XRayCounts)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_XRayCounts_EmitToCDS(context) context.SAO_CTX_outC_XRayCounts.EmitToCDS  /* XRayCounts/EmitToCDS */
#define VAR_XRayCounts_EmitToCDS VARC_XRayCounts_EmitToCDS(CTX_XRayCounts)

#define VARC_XRayCounts_LayerVisible(context) context.SAO_CTX_outC_XRayCounts.LayerVisible  /* XRayCounts/LayerVisible */
#define VAR_XRayCounts_LayerVisible VARC_XRayCounts_LayerVisible(CTX_XRayCounts)

#define VARC_XRayCounts_availableOutput(context) context.SAO_CTX_outC_XRayCounts.availableOutput  /* XRayCounts/availableOutput */
#define VAR_XRayCounts_availableOutput VARC_XRayCounts_availableOutput(CTX_XRayCounts)

#define VARC_XRayCounts_occupiedOutput(context) context.SAO_CTX_outC_XRayCounts.occupiedOutput  /* XRayCounts/occupiedOutput */
#define VAR_XRayCounts_occupiedOutput VARC_XRayCounts_occupiedOutput(CTX_XRayCounts)

#define VARC_XRayCounts_totalOutput(context) context.SAO_CTX_outC_XRayCounts.totalOutput  /* XRayCounts/totalOutput */
#define VAR_XRayCounts_totalOutput VARC_XRayCounts_totalOutput(CTX_XRayCounts)


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

#define DECLAREC_CTXT_XRayCounts(context)  WU_XRayCounts context;

#define DECLARE_CTXT_XRayCounts() DECLAREC_CTXT_XRayCounts(CTX_XRayCounts)

#define DECLAREC_EXT_CTXT_XRayCounts(MODE , context) MODE WU_XRayCounts context;

#define DECLARE_EXT_CTXT_XRayCounts(MODE) DECLAREC_EXT_CTXT_XRayCounts(MODE , CTX_XRayCounts)

#define INITC_XRayCounts(context) XRayCounts_reset(&context.SAO_CTX_outC_XRayCounts)
#define INIT_XRayCounts() INITC_XRayCounts(CTX_XRayCounts)

#define PERFORMC_XRayCounts(context) 	XRayCounts( \
		&context.SAO_CTX_inC_XRayCounts /* input context */,\
		&context.SAO_CTX_outC_XRayCounts /* output/memories context */\
	)

#define PERFORM_XRayCounts() PERFORMC_XRayCounts(CTX_XRayCounts)

/*$************** SCADE Macro wrapper *********************
** End of file XRayCounts_macro.h
***********************************************************$*/

#endif /* _XRAYCOUNTS_MACRO_H_ */
