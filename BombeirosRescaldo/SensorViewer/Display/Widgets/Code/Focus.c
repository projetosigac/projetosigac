/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME		  : Focus.c
 DESCRIPTION	   : Interactivity management   
 VERSION		   : $Revision: 16381 $
 MODIFICATION DATE : $Date: 2015-02-26 16:59:00 +0100 (jeu., 26 févr. 2015) $
 COPYRIGHT (C)	 : 2014 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "sgl.h"

typedef SGLint32 WidgetId_t;
typedef enum{
	NO_OVERRIDE = 0,
	FORCE_FOCUS =1,
	FORCE_NO_FOCUS =2
} override_t;

#define NO_OVERRIDE 0
#define FORCE_FOCUS 1
#define FORCE_NO_FOCUS 2

WidgetId_t CurrentFocusedWidget = 0;
SGLbool insideContainer = 0;
override_t override = NO_OVERRIDE;

void GetId(WidgetId_t *WidgetId){
	(*WidgetId)= (WidgetId_t) WidgetId;
}

void ManageIndividualFocus (
	SGLbool RequestFocus,
	WidgetId_t WidgetId,
	SGLbool IsContainer,
	WidgetId_t NextWidgetId,
	SGLbool *HasFocus)
{
	if(override == FORCE_FOCUS){
		*HasFocus = SGL_TRUE;
		return;
	}else if (override == FORCE_NO_FOCUS){
		*HasFocus = SGL_FALSE;
		return;
	}
	
	/*keep Current focus unless the widget releases it.*/
	if (CurrentFocusedWidget == WidgetId) {
		(*HasFocus) = SGL_TRUE;
		if(NextWidgetId != 0){
			CurrentFocusedWidget = NextWidgetId;
			(*HasFocus)=SGL_FALSE;
		}else{
			if (!RequestFocus) {
				(*HasFocus) = SGL_FALSE;
				CurrentFocusedWidget = 0;
			}
			else if (IsContainer) {
				insideContainer=SGL_TRUE;
			}
		}
	}
	/*If no-one is focused, automatically grant the request.*/
	else if (CurrentFocusedWidget == 0) {
		if (RequestFocus) {
			(*HasFocus) = SGL_TRUE;
			CurrentFocusedWidget = WidgetId;
			if (IsContainer) {
				insideContainer=SGL_TRUE;
			}
		}
	}
	/*If a parent container has the focus, grant it to its children.*/
	else if (insideContainer) {
		if (RequestFocus) {
			(*HasFocus) = SGL_TRUE;
			CurrentFocusedWidget = WidgetId;
			if (!IsContainer) {
				insideContainer=SGL_FALSE;
			}
		}
	}
	else {
		(*HasFocus) = SGL_FALSE;
	}
}

void FocusOverride(SGLlong o){
	override = o;
}
void ReleaseOverride(){
	override = NO_OVERRIDE;
}

/* After going through the children of a container, reset the status for the children of another container
 * note: this cannot handle more that 1 level of containers*/
void ResetInteractivityStatus (
	WidgetId_t WidgetId)
{
	if (CurrentFocusedWidget == WidgetId) {
		insideContainer=SGL_FALSE;
	}
}

