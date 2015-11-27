/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME          : liba661widgets_String.c
 DESCRIPTION       : Widget Library SCADE Suite imported code: String package
 VERSION           : $Revision: 12692 $
 MODIFICATION DATE : $Date: 2013-12-11 15:29:08 +0100 (Wed, 11 Dec 2013) $
 COPYRIGHT (C)     : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "sgl.h"
#include "stdio.h"

#define SIZE 255
#define IS_CRLF 1

SGLbyte isHexa(SGLbyte c){
	return ((c>='0' && c<='9') || (c>='a' && c<='f') || (c>='A' && c<='F'));
}

SGLbyte isEscaped(SGLbyte *s,SGLlong index){
	if (index < SIZE-5 &&
			s[index]=='\\' &&
			s[index+1]=='u' &&
			isHexa(s[index+2]) &&
			isHexa(s[index+3]) &&
			isHexa(s[index+4]) &&
			isHexa(s[index+5])
	)
		return 1;
	return 0;
}

SGLbyte isPreviousEscaped(SGLbyte *s,SGLlong index){
	if (index >=6 &&
			s[index-6]=='\\' &&
			s[index-5]=='u' &&
			isHexa(s[index-4]) &&
			isHexa(s[index-3]) &&
			isHexa(s[index-2]) &&
			isHexa(s[index-1])
	)
		return 1;
	return 0;
}

static SGLbyte getHexValue(SGLbyte c){
	if(c>='0' && c<='9'){
		return c-'0';
	}
	if(c>='a' && c<='f'){
		return c-'a'+ 0xA;
	}
	if(c>='A' && c<='F'){
		return c-'A'+0xA;
	}
	return 0;/*TBD*/
}

static SGLbyte encodeHexValue(SGLbyte c){
	if(c<=9){
		return c+'0';
	}
	if(c>= 0xA && c<= 0xF){
		return c- 0xA + 'A';
	}
	return '0';/*TBD*/
}

SGLulong getCharId(SGLbyte *s, SGLlong index, SGLlong *nextIndex){
	SGLulong charID=0;
	SGLlong increment=0;
	
	if (index < SIZE-5 &&
			s[index]=='\\' && 
			s[index+1]=='u' &&
			isHexa(s[index+2]) &&
			isHexa(s[index+3]) &&
			isHexa(s[index+4]) &&
			isHexa(s[index+5])
	) {
		/*escape sequence*/
		charID = (getHexValue(s[index+2]) << 12) ^
				 (getHexValue(s[index+3]) <<  8) ^
				 (getHexValue(s[index+4]) <<  4) ^
				 (getHexValue(s[index+5]));
		increment=6;
	} else if (IS_CRLF && index < SIZE-1 && s[index]==13){
		charID=13;
		increment=2;
	} else if(index < SIZE){
		charID=s[index];
		increment=1;
	} else {
		charID=0;
		increment=1;
	}
	if(nextIndex!=NULL){
		*nextIndex=index+increment;
	}
	
	return charID;
}

void setCharAt(SGLbyte *s, SGLlong index, SGLlong *nextIndex, SGLlong charID){
	SGLlong increment=0;
	
	if (index < SIZE-5 && charID > 255){/*encode escape sequence*/
		s[index]='\\';
		s[index+1]='u';
		
		s[index+5]= encodeHexValue (charID % 0x10);
		charID /= 0x10;
		s[index+4]= encodeHexValue (charID % 0x10);
		charID /= 0x10;
		s[index+3]= encodeHexValue (charID % 0x10);
		charID /= 0x10;
		s[index+2]= encodeHexValue (charID % 0x10);
		charID /= 0x10;
		
		increment=6;
	} else if (IS_CRLF && index < SIZE-1 && charID==13){
		s[index]=10;
		s[index+1]=13;
		increment=2;
	} else if(index < SIZE){
		s[index]=charID;
		increment=1;
	} else {/*no room to insert*/
		increment=0;
	}
	if(nextIndex!=NULL){
		*nextIndex=index+increment;
	}
}

SGLlong getNextIndex(SGLbyte *s, SGLlong index){
	if (index < SIZE-5 &&
			s[index]=='\\' && 
			s[index+1]=='u' &&
			isHexa(s[index+2]) &&
			isHexa(s[index+3]) &&
			isHexa(s[index+4]) &&
			isHexa(s[index+5])
	) {
		return index+6;
	} else if (IS_CRLF && index < SIZE-1 && s[index]==13){
		return index+2;
	} else {
		return index+1;
	}
}

SGLlong getPreviousIndex(SGLbyte *s, SGLlong index){
	if (index > 6 &&
			s[index-6]=='\\' && 
			s[index-5]=='u' &&
			isHexa(s[index-4]) &&
			isHexa(s[index-3]) &&
			isHexa(s[index-2]) &&
			isHexa(s[index-1])
	) {
		return index-6;
	} else if (IS_CRLF && index >2 && s[index-2]==13){
		return index-2;
	} else {
		return index-1;
	}
}
