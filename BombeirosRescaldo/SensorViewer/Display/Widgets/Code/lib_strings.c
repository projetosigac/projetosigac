/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : liba661widgets_String.c
 DESCRIPTION       : Widget Library SCADE Suite imported code: String package
 VERSION           : $Revision: 12692 $
 MODIFICATION DATE : $Date: 2013-12-11 15:29:08 +0100 (Wed, 11 Dec 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wid_kcg_types.h"
#include "wid_kcg_consts.h"
#include "lib_unicode.h"
#include "sgl.h"
#include "string.h"

#ifdef _BHVR_KCG_TYPES_H_
/*if called from a scade display behaviour, everything will be prefixed by BHVR_*/
#define array_char_255 BHVR_array_char_255
#define kcg_copy_array_char_255 BHVR_kcg_copy_array_char_255

#define KEY_BACKSPACE_Pointer BHVR_KEY_BACKSPACE_Pointer
#define CRLF_Strings BHVR_CRLF_Strings
#define CR_Strings BHVR_CR_Strings
#define LF_Strings BHVR_LF_Strings
#define LeftKey BHVR_LeftKey
#define DelKey BHVR_DelKey
#define RightKey BHVR_RightKey
#define DownKey BHVR_DownKey
#define UpKey BHVR_UpKey
#define HomeKey BHVR_HomeKey
#define EndKey BHVR_EndKey
#endif


/* Strings::Edit */
extern void Edit_Strings(
	/* Strings::Edit::NumericMode */kcg_bool NumericMode,
	/* Strings::Edit::Text */array_char_255 *Text,
	/* Strings::Edit::Keyboard_Code */kcg_int Keyboard_Code,
	/* Strings::Edit::CurrentIndex */kcg_int CurrentIndex,
	/* Strings::Edit::MaxNbChar */kcg_int MaxNbChar,
	/* Strings::Edit::NewIndex */kcg_int *NewIndex,
	/* Strings::Edit::OutText */array_char_255 *OutText,
	/* Strings::Edit::TextModified */kcg_bool *TextModified)
{
	kcg_int ii;
	

	*TextModified = kcg_false;
	
	/* Compute index if not done yet */
	if(CurrentIndex == -1) {
		for(ii=0;ii<MaxNbChar;ii++) {
			if((*Text)[ii] == '\0')
				break;
		}
		CurrentIndex = ii;
	}

	if(Keyboard_Code == KEY_BACKSPACE_Pointer ) {
		if (CurrentIndex > 0) {
			
			/*special case if current char is an end of line*/
			int remove_how_many=1;
			if(DEFAULT_EOL_Strings==CRLF_Strings && CurrentIndex>=2 && (*Text)[CurrentIndex-2]==13) remove_how_many=2;
			
			/*check if current char is an escape sequence*/
			if(isPreviousEscaped((unsigned char *)Text,CurrentIndex)){
				remove_how_many=6;
			}
			
			CurrentIndex-=remove_how_many;
			for (ii = CurrentIndex; ii < MaxNbChar-remove_how_many; ii++) {
				(*OutText)[ii] = (*Text)[ii + remove_how_many];
			}
			for(ii=MaxNbChar-remove_how_many-1;ii<MaxNbChar;ii++){
				(*OutText)[ii]=0;
			}
			for(ii=0;ii<CurrentIndex;ii++) {
				(*OutText)[ii] = (*Text)[ii];
			}
			*TextModified = kcg_true;
		}
	}else if (Keyboard_Code == DelKey ) {
		if (CurrentIndex+1 < MaxNbChar) {
			/*special case if next is an end of line*/
			int remove_how_many=1;
			if (
				DEFAULT_EOL_Strings==CRLF_Strings && 
				(*Text)[CurrentIndex]==13 &&
				CurrentIndex+2<MaxNbChar &&
				(*Text)[CurrentIndex+1]==10
			) {
				remove_how_many=2;
			}
			
			/*check if current char is an escape sequence*/
			if(isEscaped((unsigned char *)Text,CurrentIndex)){
				remove_how_many=6;
			}
			
			for (ii = CurrentIndex; ii < MaxNbChar-remove_how_many; ii++) {
				(*OutText)[ii] = (*Text)[ii + remove_how_many];
			}
			for(ii=MaxNbChar-remove_how_many-1;ii<MaxNbChar;ii++){
				(*OutText)[ii]=0;
			}
			for(ii=0;ii<CurrentIndex;ii++) {
				(*OutText)[ii] = (*Text)[ii];
			}
			*TextModified = kcg_true;
		}
	}else if(Keyboard_Code==13) {
		int insert_how_many=1;
		if(DEFAULT_EOL_Strings==CRLF_Strings) insert_how_many=2;
		
		if (CurrentIndex < MaxNbChar - insert_how_many) {
			for(ii=0;ii<CurrentIndex;ii++) {
				(*OutText)[ii] = (*Text)[ii];
			}
			for (ii = MaxNbChar - 1; ii >= CurrentIndex+insert_how_many; ii--) {
				(*OutText)[ii] = (*Text)[ii - insert_how_many];
			}
			switch(DEFAULT_EOL_Strings){
				case CR_Strings:(*OutText)[CurrentIndex] = (kcg_char) 13;break;
				case LF_Strings:(*OutText)[CurrentIndex] = (kcg_char) 10;break;
				case CRLF_Strings:
					(*OutText)[CurrentIndex] = (kcg_char) 13;
					CurrentIndex++;
					(*OutText)[CurrentIndex] = (kcg_char) 10;
					break;
				default:(*OutText)[CurrentIndex] = (kcg_char) 13;break;
			}
			CurrentIndex++;
			*TextModified = kcg_true;
		}
	}else if(Keyboard_Code==LeftKey){
		CurrentIndex = getPreviousIndex((unsigned char *)Text,CurrentIndex);
		if(CurrentIndex<0) CurrentIndex=0;
	}else if(Keyboard_Code==RightKey){
		CurrentIndex = getNextIndex((unsigned char *)Text,CurrentIndex);
		if(CurrentIndex>MaxNbChar-1) CurrentIndex = MaxNbChar-1;
	}else if(Keyboard_Code==DownKey){/*Case of a multiline box*/
		/*look for next line*/
		switch(DEFAULT_EOL_Strings){
			case CRLF_Strings:
				for(ii=CurrentIndex;ii<MaxNbChar;ii++){
					if((*Text)[ii]==13){
						CurrentIndex=ii+2;
						break;
					}
				}
				break;
			case CR_Strings:
				for(ii=CurrentIndex;ii<MaxNbChar;ii++){
					if((*Text)[ii]==13){
						CurrentIndex=ii+1;
						break;
					}
				}
				break;
			case LF_Strings:
				for(ii=CurrentIndex;ii<MaxNbChar;ii++){
					if((*Text)[ii]==10){
						CurrentIndex=ii+1;
						break;
					}
				}
				break;
			default:break;
				/*no newline management*/
		}
	}else if(Keyboard_Code==UpKey){/*Case of a multiline box*/
		/*look for next line*/
		switch(DEFAULT_EOL_Strings){
			case CRLF_Strings:
				for(ii=CurrentIndex;ii>0;ii--){
					if((*Text)[ii]==10){
						CurrentIndex=ii-1;
						break;
					}
				}
				break;
			case CR_Strings:
				for(ii=CurrentIndex;ii>0;ii--){
					if((*Text)[ii]==13){
						CurrentIndex=ii;
						break;
					}
				}
				break;
			case LF_Strings:
				for(ii=CurrentIndex;ii>0;ii--){
					if((*Text)[ii]==10){
						CurrentIndex=ii;
						break;
					}
				}
				break;
			default:break;
				/*no newline management*/
		}
	}else if(Keyboard_Code==HomeKey){
		CurrentIndex=0;
	}else if(Keyboard_Code==EndKey){
		for(ii=0;ii<MaxNbChar;ii++){
			if((*Text)[ii]=='\0'){
				CurrentIndex=ii;
				break;
			}
		}
	}else if((Keyboard_Code > 31) && (Keyboard_Code < 255)) /*1 byte character*/{
		if(CurrentIndex < MaxNbChar - 1) {
			for(ii=0;ii<CurrentIndex;ii++) {
				(*OutText)[ii] = (*Text)[ii];
			}
			for (ii = MaxNbChar - 1; ii >= CurrentIndex+1; ii--) {
				(*OutText)[ii] = (*Text)[ii - 1];
			}
			(*OutText)[CurrentIndex] = (kcg_char)Keyboard_Code;
			CurrentIndex++;
			*TextModified = kcg_true;
		}
	}else if(Keyboard_Code == 9 || Keyboard_Code == 27){
		/*Tab and Esc key: managed by scade suite or ignored*/
	}else{
		/*non ascii key strokes (assume it's in the range [256, 65535]*/
		
		
		if(CurrentIndex < MaxNbChar - 6) {
			for(ii=0;ii<CurrentIndex;ii++) {
				(*OutText)[ii] = (*Text)[ii];
			}
			for(ii= MaxNbChar - 1; ii >= CurrentIndex+6; ii--) {
				(*OutText)[ii] = (*Text)[ii - 6];
			}
			
			/*encode to \uXXXX format*/
			SGLlong nextIndex=CurrentIndex;
			setCharAt( &((*OutText)[0]), CurrentIndex, &nextIndex, Keyboard_Code);
			CurrentIndex = nextIndex;
			
			*TextModified = kcg_true;
		}
	}
	*NewIndex = CurrentIndex;
}

extern void StringIsEmpty(kcg_char *s,kcg_bool*result){
	*result = (s[0]==0);
}

static SGLbyte wordSep[20]=" ";
extern void SetWordWrap(SGLbyte Separators[20], SGLlong Number){
	strncpy (wordSep, Separators, 20U);
	sglSetWordsSeparators(wordSep, Number);
}

const kcg_char CR_char_Strings=13;
const kcg_char LF_char_Strings=10;
const kcg_char NUL_char_Strings=0;
const kcg_char BackSpace_char_Strings=8;
const kcg_char Escape_char_Strings=27;
