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
    inC_Main SAO_CTX_inC_Main;
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

#define VARC_Main_GETSignalFromButton(context) context.SAO_CTX_inC_Main.GETSignalFromButton  /* Main/GETSignalFromButton */
#define VAR_Main_GETSignalFromButton VARC_Main_GETSignalFromButton(CTX_Main)

#define VARC_Main_RequestPath(context) context.SAO_CTX_inC_Main.RequestPath  /* Main/RequestPath */
#define VAR_Main_RequestPath VARC_Main_RequestPath(CTX_Main)

#define VARC_Main_Input3(context) context.SAO_CTX_inC_Main.Input3  /* Main/Input3 */
#define VAR_Main_Input3 VARC_Main_Input3(CTX_Main)

#define VARC_Main_Input4(context) context.SAO_CTX_inC_Main.Input4  /* Main/Input4 */
#define VAR_Main_Input4 VARC_Main_Input4(CTX_Main)

#define VARC_Main_txtID(context) context.SAO_CTX_inC_Main.txtID  /* Main/txtID */
#define VAR_Main_txtID VARC_Main_txtID(CTX_Main)

#define VARC_Main_txtIDNotify(context) context.SAO_CTX_inC_Main.txtIDNotify  /* Main/txtIDNotify */
#define VAR_Main_txtIDNotify VARC_Main_txtIDNotify(CTX_Main)

#define VARC_Main_txtIDLength(context) context.SAO_CTX_inC_Main.txtIDLength  /* Main/txtIDLength */
#define VAR_Main_txtIDLength VARC_Main_txtIDLength(CTX_Main)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_Main_ReqLayerVisible(context) context.SAO_CTX_outC_Main.ReqLayerVisible  /* Main/ReqLayerVisible */
#define VAR_Main_ReqLayerVisible VARC_Main_ReqLayerVisible(CTX_Main)

#define VARC_Main_ReqLayerActive(context) context.SAO_CTX_outC_Main.ReqLayerActive  /* Main/ReqLayerActive */
#define VAR_Main_ReqLayerActive VARC_Main_ReqLayerActive(CTX_Main)

#define VARC_Main_EmitToCDS(context) context.SAO_CTX_outC_Main.EmitToCDS  /* Main/EmitToCDS */
#define VAR_Main_EmitToCDS VARC_Main_EmitToCDS(CTX_Main)

#define VARC_Main_ResultSize(context) context.SAO_CTX_outC_Main.ResultSize  /* Main/ResultSize */
#define VAR_Main_ResultSize VARC_Main_ResultSize(CTX_Main)

#define VARC_Main_ResultName(context) context.SAO_CTX_outC_Main.ResultName  /* Main/ResultName */
#define VAR_Main_ResultName VARC_Main_ResultName(CTX_Main)

#define VARC_Main_ResultID(context) context.SAO_CTX_outC_Main.ResultID  /* Main/ResultID */
#define VAR_Main_ResultID VARC_Main_ResultID(CTX_Main)

#define VARC_Main_ResultSex(context) context.SAO_CTX_outC_Main.ResultSex  /* Main/ResultSex */
#define VAR_Main_ResultSex VARC_Main_ResultSex(CTX_Main)

#define VARC_Main_ResultState(context) context.SAO_CTX_outC_Main.ResultState  /* Main/ResultState */
#define VAR_Main_ResultState VARC_Main_ResultState(CTX_Main)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_GETSignalFromButton kcg_bool
#define CPY_GETSignalFromButton(DST, SRC) DST = SRC
#define T_RequestPath Path
#define CPY_RequestPath(DST, SRC) kcg_copy_Path(DST, SRC)
#define T_Input3 kcg_bool
#define CPY_Input3(DST, SRC) DST = SRC
#define T_Input4 kcg_bool
#define CPY_Input4(DST, SRC) DST = SRC
#define T_txtID String
#define CPY_txtID(DST, SRC) kcg_copy_String(DST, SRC)
#define T_txtIDNotify kcg_bool
#define CPY_txtIDNotify(DST, SRC) DST = SRC
#define T_txtIDLength kcg_int
#define CPY_txtIDLength(DST, SRC) DST = SRC
#define T_ReqLayerVisible kcg_bool
#define CPY_ReqLayerVisible(DST, SRC) DST = SRC
#define T_ReqLayerActive kcg_bool
#define CPY_ReqLayerActive(DST, SRC) DST = SRC
#define T_EmitToCDS kcg_bool
#define CPY_EmitToCDS(DST, SRC) DST = SRC
#define T_ResultSize kcg_int
#define CPY_ResultSize(DST, SRC) DST = SRC
#define T_ResultName String
#define CPY_ResultName(DST, SRC) kcg_copy_String(DST, SRC)
#define T_ResultID String
#define CPY_ResultID(DST, SRC) kcg_copy_String(DST, SRC)
#define T_ResultSex String
#define CPY_ResultSex(DST, SRC) kcg_copy_String(DST, SRC)
#define T_ResultState String
#define CPY_ResultState(DST, SRC) kcg_copy_String(DST, SRC)


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
		&context.SAO_CTX_inC_Main /* input context */,\
		&context.SAO_CTX_outC_Main /* output/memories context */\
	)

#define PERFORM_Main() PERFORMC_Main(CTX_Main)

/*$************** SCADE Macro wrapper *********************
** End of file Main_macro.h
***********************************************************$*/

#endif /* _MAIN_MACRO_H_ */
