/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : CursorBehavior.c
 DESCRIPTION       : Cursor Widget implementation: 
					 SCADE Display Cursor imported function  
 VERSION           : $Revision: 12692 $
 MODIFICATION DATE : $Date: 2013-12-11 15:29:08 +0100 (Wed, 11 Dec 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "sgl.h"
#include "stdio.h"
#include "string.h"
#include "lib_unicode.h"

void CursorBehavior(SGLbool EnableCursorPosComputation,
					SGLbool EnableLineSizeComputation,
					SGLfloat AreaSizeX, 
					SGLfloat AreaSizeY, 
					SGLbyte String[255], 
					SGLlong CharIndex, 
					SGLlong FontId, 
					SGLfloat ClickedPositionX,
					SGLfloat ClickedPositionY,
					SGLbyte NewClick,
					SGLlong HorizontalAlignment, 
					SGLfloat (*CursorPosX), 
					SGLfloat (*CursorPosY),
					SGLbool (*LineFull),
					SGLfloat (*LineSizeY),
					SGLlong (*NbLines),
					SGLfloat (*CharSize),
					SGLlong (*NewIndexAfterClick))
{
	SGLlong LineClicked,LineNumber;
	SGLulong charId;
	SGLlong indexInString;
	SGLfloat Distance,TextLength,ClickedPosition,LineSizeX;
	
	if (EnableCursorPosComputation || EnableLineSizeComputation) {
		
		/*Find max Char Height and Vertical Advance*/
		*CharSize = 0.0;
		*LineSizeY = 0.0;
		indexInString = 0;
		do{
			charId= getCharId(String,indexInString,&indexInString);
			if(charId==0) break;
			
			if(sglGetFontValue((SGLulong)FontId,(SGLulong)(charId),SGL_CHAR_HEIGHT) > *CharSize) {
				*CharSize = sglGetFontValue((SGLulong)FontId,(SGLulong)(charId),SGL_CHAR_HEIGHT);
			}
			if(sglGetFontValue((SGLulong)FontId,(SGLulong)(charId),SGL_VERTICAL_ADVANCE) > *LineSizeY) {
				*LineSizeY = sglGetFontValue((SGLulong)FontId,(SGLulong)(charId),SGL_VERTICAL_ADVANCE);
			}
		} while(charId!=0);
		*LineSizeY  = *LineSizeY  + *CharSize;
		
		/*count number of displayed lines (including both CRLF and automatic line feeds*/
		TextLength = 0.0;
		*NbLines=1;
		LineNumber = 0;
		indexInString=0;
		do{
			charId = getCharId(String,indexInString,&indexInString);
			TextLength += sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			if (TextLength > AreaSizeX || charId==13) {
				(*NbLines)+=1;
				TextLength = sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			}
		} while(charId!=0);
	}
	
	if (EnableCursorPosComputation && NewClick) {
		/* The user has clicked on the EditBox: the cursor must be set on the clicked position */
		/* First find the line number */
		LineClicked = (SGLlong)((1.0 - ClickedPositionY) * AreaSizeY / (*LineSizeY)) + 1;
		
		/* Find the length of the text on the considered line */
		TextLength = 0.0;
		*NbLines=1;
		LineNumber = 0;


		indexInString=0;
		do{
			charId = getCharId(String,indexInString,&indexInString);
			if(charId==0) break;
			
			TextLength += sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			
			if (TextLength > AreaSizeX) {
				LineNumber++;
				(*NbLines)+=1;
				if(LineNumber == LineClicked) {
					TextLength -= sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
					break;
				}
				else{
					TextLength = sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
				}
			}else if(charId==13){
				LineNumber++;
				(*NbLines)+=1;
				if(LineNumber == LineClicked) {
					TextLength -= sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
					break;
				}
				else{
					TextLength = 0.0;
				}
			}
		} while(charId!=0);
		
		/* Compute the clicked position relative to alignment */
		
		/* Default case, HorizontalAlignment==0 , Align left */
		ClickedPosition = ClickedPositionX * AreaSizeX;
		
		if(HorizontalAlignment == 1) { /* Align center */
			ClickedPosition = ClickedPositionX * AreaSizeX - (AreaSizeX - TextLength)/2.0;
		}
		if(HorizontalAlignment == 2) { /* Align right */
			ClickedPosition = ClickedPositionX * AreaSizeX - AreaSizeX + TextLength;
		}

		/*Go around the whole string again. When going through the correct line, stop when the distance is to the right of the mouse pointer.*/
		Distance = 0.0;
		indexInString = 0;
		do {
			charId = getCharId(String,indexInString,NULL);
			if(
				(
					(Distance > ClickedPosition || charId==13)
					&& LineClicked <= 1
				) || charId == 0
			){
				*NewIndexAfterClick = indexInString;
				CharIndex = indexInString;
				break;
			}
			
			Distance += sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			if(Distance > AreaSizeX && LineClicked > 1) {
				LineClicked--;
				Distance = sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			}else if(charId==13 && LineClicked > 1) {
				LineClicked--;
				Distance = 0.0;
			}
			
			indexInString = getNextIndex(String,indexInString);
		} while(charId !=0);

		/*If the pointer is less than 1/3rd of the first character, set it at the beginning of the string.*/
		if (CharIndex == 1 && ClickedPosition < Distance / 3.0) {
			CharIndex = 0;
			*NewIndexAfterClick = 0;
		}
	}
	
	if (EnableCursorPosComputation) {
		*CursorPosX = 0.0;
		*CursorPosY = - (*LineSizeY);
		
		if(CharIndex > 255 || CharIndex == -1)
			CharIndex = 255;

		indexInString = 0;
		while (indexInString <CharIndex) {
			charId = getCharId(String,indexInString,&indexInString);
			
			if(charId == 0)
				break;
			else {
				
				if (*CursorPosX + sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE) > AreaSizeX) {
					/* New line needed to fit character*/
					*CursorPosX = sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
					*CursorPosY = *CursorPosY - (*LineSizeY);
				}else if(charId==13){
					/*Begin new line*/
					*CursorPosX = 0.0;
					*CursorPosY = *CursorPosY - (*LineSizeY);
				}else{
					*CursorPosX += sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
				}
			}
		}

		/* compute Line size (useful for text edit box, to stop edit at end of line) */
		LineSizeX = 0.0;
		*LineFull = 0/*false*/;
		indexInString = 0;
		do {
			SGLlong nextIndex = 0;
			SGLulong charIdNext = 0;
			
			charId = getCharId(String,indexInString,&nextIndex);
			charIdNext = getCharId(String,nextIndex,NULL);
			
			if(LineSizeX > AreaSizeX - sglGetFontValue((SGLulong)FontId,charIdNext,SGL_HORIZONTAL_ADVANCE)) {
				*LineFull = 1/*true*/;
				break;
			}

			if(charId == 0) break;

			LineSizeX += sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);

			indexInString = getNextIndex(String,indexInString);
		} while (charId != 0);
		
		/* adjust cursor position wrt alignment */
		TextLength = 0.0;
		indexInString = 0;
		do{
			charId = getCharId(String,indexInString,NULL);
			
			TextLength += sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			if(
				(
					(TextLength > AreaSizeX || charId==13)
					&& indexInString > CharIndex
				)
				|| charId == 0
			){
				TextLength -= sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
				break;
			}
			if (TextLength > AreaSizeX) {
				TextLength = sglGetFontValue((SGLulong)FontId,charId,SGL_HORIZONTAL_ADVANCE);
			}else if (charId==13) {
				TextLength = 0.0;
			}

			indexInString = getNextIndex(String,indexInString);
		} while (charId!=0);
		if(HorizontalAlignment == 1) { /* Align center */
			*CursorPosX = *CursorPosX + (AreaSizeX - TextLength)/2.0;
		}
		if(HorizontalAlignment == 2) { /* Align right */
			*CursorPosX = *CursorPosX + AreaSizeX - TextLength;
		}
	}
}

void GetFontSizeY(SGLlong FontId,SGLfloat *fontSize){
	*fontSize = sglGetFontValue((SGLulong)FontId,(SGLulong)'A',SGL_CHAR_HEIGHT);
}

void GetFontSize_Strings(SGLlong FontId,SGLfloat *fontSizeX, SGLfloat *fontSizeY){
	
	*fontSizeX = sglGetFontValue((SGLulong)FontId,(SGLulong)'0',SGL_HORIZONTAL_ADVANCE);
	*fontSizeY = sglGetFontValue((SGLulong)FontId,(SGLulong)'0',SGL_CHAR_HEIGHT);
}
