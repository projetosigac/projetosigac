#ifndef _UTI_MACRO_H_
#define _UTI_MACRO_H_


/*$************** SCADE Macro wrapper *********************
** Begin of file UTI_macro.h
***********************************************************$*/


/*$**********************************************************
*                        INCLUDES
***********************************************************$*/

/* includes */
#include "UTI.h"

/*$**********************************************************
*                           CONTEXT
***********************************************************$*/

typedef struct {
    inC_UTI SAO_CTX_inC_UTI;
    outC_UTI SAO_CTX_outC_UTI;
} WU_UTI;
#define WU_CTX_TYPE_UTI WU_UTI
#define WU_CTX_TYPE_UTI_SIZE sizeof(WU_UTI)

/*$**********************************************************
*                           SENSORS
***********************************************************$*/

#define DECLARE_SENSORS_UTI() 

#define DECLARE_EXT_SENSORS_UTI(MODE) 

/*$**********************************************************
*                           INPUTS
***********************************************************$*/

#define VARC_UTI_AllocateBed1(context) context.SAO_CTX_inC_UTI.AllocateBed1  /* UTI/AllocateBed1 */
#define VAR_UTI_AllocateBed1 VARC_UTI_AllocateBed1(CTX_UTI)

#define VARC_UTI_ActivateBed2(context) context.SAO_CTX_inC_UTI.ActivateBed2  /* UTI/ActivateBed2 */
#define VAR_UTI_ActivateBed2 VARC_UTI_ActivateBed2(CTX_UTI)

#define VARC_UTI_ActivateBed3(context) context.SAO_CTX_inC_UTI.ActivateBed3  /* UTI/ActivateBed3 */
#define VAR_UTI_ActivateBed3 VARC_UTI_ActivateBed3(CTX_UTI)

#define VARC_UTI_ActivateBed4(context) context.SAO_CTX_inC_UTI.ActivateBed4  /* UTI/ActivateBed4 */
#define VAR_UTI_ActivateBed4 VARC_UTI_ActivateBed4(CTX_UTI)

#define VARC_UTI_ActivateBed5(context) context.SAO_CTX_inC_UTI.ActivateBed5  /* UTI/ActivateBed5 */
#define VAR_UTI_ActivateBed5 VARC_UTI_ActivateBed5(CTX_UTI)

#define VARC_UTI_ActivateBed6(context) context.SAO_CTX_inC_UTI.ActivateBed6  /* UTI/ActivateBed6 */
#define VAR_UTI_ActivateBed6 VARC_UTI_ActivateBed6(CTX_UTI)

#define VARC_UTI_ActivateBed7(context) context.SAO_CTX_inC_UTI.ActivateBed7  /* UTI/ActivateBed7 */
#define VAR_UTI_ActivateBed7 VARC_UTI_ActivateBed7(CTX_UTI)

#define VARC_UTI_ActivateBed8(context) context.SAO_CTX_inC_UTI.ActivateBed8  /* UTI/ActivateBed8 */
#define VAR_UTI_ActivateBed8 VARC_UTI_ActivateBed8(CTX_UTI)

#define VARC_UTI_ActivateBed1(context) context.SAO_CTX_inC_UTI.ActivateBed1  /* UTI/ActivateBed1 */
#define VAR_UTI_ActivateBed1 VARC_UTI_ActivateBed1(CTX_UTI)

#define VARC_UTI_AllocateBed2(context) context.SAO_CTX_inC_UTI.AllocateBed2  /* UTI/AllocateBed2 */
#define VAR_UTI_AllocateBed2 VARC_UTI_AllocateBed2(CTX_UTI)

#define VARC_UTI_AllocateBed4(context) context.SAO_CTX_inC_UTI.AllocateBed4  /* UTI/AllocateBed4 */
#define VAR_UTI_AllocateBed4 VARC_UTI_AllocateBed4(CTX_UTI)

#define VARC_UTI_AllocateBed3(context) context.SAO_CTX_inC_UTI.AllocateBed3  /* UTI/AllocateBed3 */
#define VAR_UTI_AllocateBed3 VARC_UTI_AllocateBed3(CTX_UTI)

#define VARC_UTI_AllocateBed6(context) context.SAO_CTX_inC_UTI.AllocateBed6  /* UTI/AllocateBed6 */
#define VAR_UTI_AllocateBed6 VARC_UTI_AllocateBed6(CTX_UTI)

#define VARC_UTI_AllocateBed5(context) context.SAO_CTX_inC_UTI.AllocateBed5  /* UTI/AllocateBed5 */
#define VAR_UTI_AllocateBed5 VARC_UTI_AllocateBed5(CTX_UTI)

#define VARC_UTI_AllocateBed7(context) context.SAO_CTX_inC_UTI.AllocateBed7  /* UTI/AllocateBed7 */
#define VAR_UTI_AllocateBed7 VARC_UTI_AllocateBed7(CTX_UTI)

#define VARC_UTI_AllocateBed8(context) context.SAO_CTX_inC_UTI.AllocateBed8  /* UTI/AllocateBed8 */
#define VAR_UTI_AllocateBed8 VARC_UTI_AllocateBed8(CTX_UTI)


/*$**********************************************************
*                           OUTPUTS
***********************************************************$*/

#define VARC_UTI_ActiveBedsCount(context) context.SAO_CTX_outC_UTI.ActiveBedsCount  /* UTI/ActiveBedsCount */
#define VAR_UTI_ActiveBedsCount VARC_UTI_ActiveBedsCount(CTX_UTI)

#define VARC_UTI_AllocatedBedsCount(context) context.SAO_CTX_outC_UTI.AllocatedBedsCount  /* UTI/AllocatedBedsCount */
#define VAR_UTI_AllocatedBedsCount VARC_UTI_AllocatedBedsCount(CTX_UTI)

#define VARC_UTI_BedColor1(context) context.SAO_CTX_outC_UTI.BedColor1  /* UTI/BedColor1 */
#define VAR_UTI_BedColor1 VARC_UTI_BedColor1(CTX_UTI)

#define VARC_UTI_FreeBedsCount(context) context.SAO_CTX_outC_UTI.FreeBedsCount  /* UTI/FreeBedsCount */
#define VAR_UTI_FreeBedsCount VARC_UTI_FreeBedsCount(CTX_UTI)

#define VARC_UTI_BedColor2(context) context.SAO_CTX_outC_UTI.BedColor2  /* UTI/BedColor2 */
#define VAR_UTI_BedColor2 VARC_UTI_BedColor2(CTX_UTI)

#define VARC_UTI_BedColor3(context) context.SAO_CTX_outC_UTI.BedColor3  /* UTI/BedColor3 */
#define VAR_UTI_BedColor3 VARC_UTI_BedColor3(CTX_UTI)

#define VARC_UTI_BedColor4(context) context.SAO_CTX_outC_UTI.BedColor4  /* UTI/BedColor4 */
#define VAR_UTI_BedColor4 VARC_UTI_BedColor4(CTX_UTI)

#define VARC_UTI_BedColor5(context) context.SAO_CTX_outC_UTI.BedColor5  /* UTI/BedColor5 */
#define VAR_UTI_BedColor5 VARC_UTI_BedColor5(CTX_UTI)

#define VARC_UTI_BedColor6(context) context.SAO_CTX_outC_UTI.BedColor6  /* UTI/BedColor6 */
#define VAR_UTI_BedColor6 VARC_UTI_BedColor6(CTX_UTI)

#define VARC_UTI_BedColor7(context) context.SAO_CTX_outC_UTI.BedColor7  /* UTI/BedColor7 */
#define VAR_UTI_BedColor7 VARC_UTI_BedColor7(CTX_UTI)

#define VARC_UTI_BedColor8(context) context.SAO_CTX_outC_UTI.BedColor8  /* UTI/BedColor8 */
#define VAR_UTI_BedColor8 VARC_UTI_BedColor8(CTX_UTI)

#define VARC_UTI_EmitToCDS(context) context.SAO_CTX_outC_UTI.EmitToCDS  /* UTI/EmitToCDS */
#define VAR_UTI_EmitToCDS VARC_UTI_EmitToCDS(CTX_UTI)

#define VARC_UTI_LayerVisible(context) context.SAO_CTX_outC_UTI.LayerVisible  /* UTI/LayerVisible */
#define VAR_UTI_LayerVisible VARC_UTI_LayerVisible(CTX_UTI)


/*$**********************************************************
*                           ELEMENT ACCESS
***********************************************************$*/

#define GET_ELEMENT_AT(VARIABLE, INDEX)  (VARIABLE)[INDEX]
#define GET_STRUCTURE_FIELD(VARIABLE, FIELD) (VARIABLE).FIELD

/*$**********************************************************
*                        VARIABLES TYPES
***********************************************************$*/

#define T_AllocateBed1 kcg_bool
#define CPY_AllocateBed1(DST, SRC) DST = SRC
#define T_ActivateBed2 kcg_bool
#define CPY_ActivateBed2(DST, SRC) DST = SRC
#define T_ActivateBed3 kcg_bool
#define CPY_ActivateBed3(DST, SRC) DST = SRC
#define T_ActivateBed4 kcg_bool
#define CPY_ActivateBed4(DST, SRC) DST = SRC
#define T_ActivateBed5 kcg_bool
#define CPY_ActivateBed5(DST, SRC) DST = SRC
#define T_ActivateBed6 kcg_bool
#define CPY_ActivateBed6(DST, SRC) DST = SRC
#define T_ActivateBed7 kcg_bool
#define CPY_ActivateBed7(DST, SRC) DST = SRC
#define T_ActivateBed8 kcg_bool
#define CPY_ActivateBed8(DST, SRC) DST = SRC
#define T_ActivateBed1 kcg_bool
#define CPY_ActivateBed1(DST, SRC) DST = SRC
#define T_AllocateBed2 kcg_bool
#define CPY_AllocateBed2(DST, SRC) DST = SRC
#define T_AllocateBed4 kcg_bool
#define CPY_AllocateBed4(DST, SRC) DST = SRC
#define T_AllocateBed3 kcg_bool
#define CPY_AllocateBed3(DST, SRC) DST = SRC
#define T_AllocateBed6 kcg_bool
#define CPY_AllocateBed6(DST, SRC) DST = SRC
#define T_AllocateBed5 kcg_bool
#define CPY_AllocateBed5(DST, SRC) DST = SRC
#define T_AllocateBed7 kcg_bool
#define CPY_AllocateBed7(DST, SRC) DST = SRC
#define T_AllocateBed8 kcg_bool
#define CPY_AllocateBed8(DST, SRC) DST = SRC
#define T_ActiveBedsCount kcg_real
#define CPY_ActiveBedsCount(DST, SRC) DST = SRC
#define T_AllocatedBedsCount kcg_real
#define CPY_AllocatedBedsCount(DST, SRC) DST = SRC
#define T_BedColor1 kcg_int
#define CPY_BedColor1(DST, SRC) DST = SRC
#define T_FreeBedsCount kcg_real
#define CPY_FreeBedsCount(DST, SRC) DST = SRC
#define T_BedColor2 kcg_int
#define CPY_BedColor2(DST, SRC) DST = SRC
#define T_BedColor3 kcg_int
#define CPY_BedColor3(DST, SRC) DST = SRC
#define T_BedColor4 kcg_int
#define CPY_BedColor4(DST, SRC) DST = SRC
#define T_BedColor5 kcg_int
#define CPY_BedColor5(DST, SRC) DST = SRC
#define T_BedColor6 kcg_int
#define CPY_BedColor6(DST, SRC) DST = SRC
#define T_BedColor7 kcg_int
#define CPY_BedColor7(DST, SRC) DST = SRC
#define T_BedColor8 kcg_int
#define CPY_BedColor8(DST, SRC) DST = SRC
#define T_EmitToCDS kcg_bool
#define CPY_EmitToCDS(DST, SRC) DST = SRC
#define T_LayerVisible kcg_bool
#define CPY_LayerVisible(DST, SRC) DST = SRC


/*$**********************************************************
*                      CREATION, INIT AND PERFORM
***********************************************************$*/

#define DECLAREC_CTXT_UTI(context)  WU_UTI context;

#define DECLARE_CTXT_UTI() DECLAREC_CTXT_UTI(CTX_UTI)

#define DECLAREC_EXT_CTXT_UTI(MODE , context) MODE WU_UTI context;

#define DECLARE_EXT_CTXT_UTI(MODE) DECLAREC_EXT_CTXT_UTI(MODE , CTX_UTI)

#define INITC_UTI(context) UTI_reset(&context.SAO_CTX_outC_UTI)
#define INIT_UTI() INITC_UTI(CTX_UTI)

#define PERFORMC_UTI(context) 	UTI( \
		&context.SAO_CTX_inC_UTI /* input context */,\
		&context.SAO_CTX_outC_UTI /* output/memories context */\
	)

#define PERFORM_UTI() PERFORMC_UTI(CTX_UTI)

/*$************** SCADE Macro wrapper *********************
** End of file UTI_macro.h
***********************************************************$*/

#endif /* _UTI_MACRO_H_ */
