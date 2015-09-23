#ifndef _MAIN_MACRO_H_
#define _MAIN_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file Main_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "Main.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    outC_Main SAO_CTX_outC_Main;
} WU_Main;
#define WU_CTX_TYPE_Main WU_Main
#define WU_CTX_TYPE_Main_SIZE sizeof(WU_Main)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_Main() 

#define DECLARE_EXT_SENSORS_Main(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_Main_ReqLayerVisible(context) context.SAO_CTX_outC_Main.ReqLayerVisible  /* Main/ReqLayerVisible */
#define VAR_Main_ReqLayerVisible VARC_Main_ReqLayerVisible(CTX_Main)

#define VARC_Main_ReqLayerActive(context) context.SAO_CTX_outC_Main.ReqLayerActive  /* Main/ReqLayerActive */
#define VAR_Main_ReqLayerActive VARC_Main_ReqLayerActive(CTX_Main)

#define VARC_Main_EmitToCDS(context) context.SAO_CTX_outC_Main.EmitToCDS  /* Main/EmitToCDS */
#define VAR_Main_EmitToCDS VARC_Main_EmitToCDS(CTX_Main)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_ReqLayerVisible kcg_bool
#define CPY_ReqLayerVisible(DST, SRC) DST = SRC
#define T_ReqLayerActive kcg_bool
#define CPY_ReqLayerActive(DST, SRC) DST = SRC
#define T_EmitToCDS kcg_bool
#define CPY_EmitToCDS(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_Main(context)  WU_Main context;

#define DECLARE_CTXT_Main() DECLAREC_CTXT_Main(CTX_Main)

#define DECLAREC_EXT_CTXT_Main(MODE , context) MODE WU_Main context;

#define DECLARE_EXT_CTXT_Main(MODE) DECLAREC_EXT_CTXT_Main(MODE , CTX_Main)

#define INITC_Main(context) Main_reset(&context.SAO_CTX_outC_Main)
#define INIT_Main() INITC_Main(CTX_Main)

#define PERFORMC_Main(context) 	Main( \
		&context.SAO_CTX_outC_Main /* output/memories context */\
	)

#define PERFORM_Main() PERFORMC_Main(CTX_Main)

/*$************** SCADE Macro wrapper *********************
** End of file Main_macro.h
***********************************************************$*/

#endif /* _MAIN_MACRO_H_ */
