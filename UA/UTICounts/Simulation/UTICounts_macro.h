#ifndef _UTICOUNTS_MACRO_H_
#define _UTICOUNTS_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file UTICounts_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "UTICounts.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_UTICounts SAO_CTX_inC_UTICounts;
    outC_UTICounts SAO_CTX_outC_UTICounts;
} WU_UTICounts;
#define WU_CTX_TYPE_UTICounts WU_UTICounts
#define WU_CTX_TYPE_UTICounts_SIZE sizeof(WU_UTICounts)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_UTICounts() 

#define DECLARE_EXT_SENSORS_UTICounts(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_UTICounts_availableInput(context) context.SAO_CTX_inC_UTICounts.availableInput  /* UTICounts/availableInput */
#define VAR_UTICounts_availableInput VARC_UTICounts_availableInput(CTX_UTICounts)

#define VARC_UTICounts_occupiedInput(context) context.SAO_CTX_inC_UTICounts.occupiedInput  /* UTICounts/occupiedInput */
#define VAR_UTICounts_occupiedInput VARC_UTICounts_occupiedInput(CTX_UTICounts)

#define VARC_UTICounts_totalInput(context) context.SAO_CTX_inC_UTICounts.totalInput  /* UTICounts/totalInput */
#define VAR_UTICounts_totalInput VARC_UTICounts_totalInput(CTX_UTICounts)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_UTICounts_EmitToCDS(context) context.SAO_CTX_outC_UTICounts.EmitToCDS  /* UTICounts/EmitToCDS */
#define VAR_UTICounts_EmitToCDS VARC_UTICounts_EmitToCDS(CTX_UTICounts)

#define VARC_UTICounts_LayerVisible(context) context.SAO_CTX_outC_UTICounts.LayerVisible  /* UTICounts/LayerVisible */
#define VAR_UTICounts_LayerVisible VARC_UTICounts_LayerVisible(CTX_UTICounts)

#define VARC_UTICounts_availableOutput(context) context.SAO_CTX_outC_UTICounts.availableOutput  /* UTICounts/availableOutput */
#define VAR_UTICounts_availableOutput VARC_UTICounts_availableOutput(CTX_UTICounts)

#define VARC_UTICounts_occupiedOutput(context) context.SAO_CTX_outC_UTICounts.occupiedOutput  /* UTICounts/occupiedOutput */
#define VAR_UTICounts_occupiedOutput VARC_UTICounts_occupiedOutput(CTX_UTICounts)

#define VARC_UTICounts_totalOutput(context) context.SAO_CTX_outC_UTICounts.totalOutput  /* UTICounts/totalOutput */
#define VAR_UTICounts_totalOutput VARC_UTICounts_totalOutput(CTX_UTICounts)


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

#define DECLAREC_CTXT_UTICounts(context)  WU_UTICounts context;

#define DECLARE_CTXT_UTICounts() DECLAREC_CTXT_UTICounts(CTX_UTICounts)

#define DECLAREC_EXT_CTXT_UTICounts(MODE , context) MODE WU_UTICounts context;

#define DECLARE_EXT_CTXT_UTICounts(MODE) DECLAREC_EXT_CTXT_UTICounts(MODE , CTX_UTICounts)

#define INITC_UTICounts(context) UTICounts_reset(&context.SAO_CTX_outC_UTICounts)
#define INIT_UTICounts() INITC_UTICounts(CTX_UTICounts)

#define PERFORMC_UTICounts(context) 	UTICounts( \
		&context.SAO_CTX_inC_UTICounts /* input context */,\
		&context.SAO_CTX_outC_UTICounts /* output/memories context */\
	)

#define PERFORM_UTICounts() PERFORMC_UTICounts(CTX_UTICounts)

/*$************** SCADE Macro wrapper *********************
** End of file UTICounts_macro.h
***********************************************************$*/

#endif /* _UTICOUNTS_MACRO_H_ */
