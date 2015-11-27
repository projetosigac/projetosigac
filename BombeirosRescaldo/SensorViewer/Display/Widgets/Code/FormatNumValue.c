/*+ FILE DESCRIPTION -------------------------------------------------------
 FILENAME		  : EditBoxNumeric_FormatNumValue.c
 DESCRIPTION	   : EditBoxNumeric Widget implementation: SCADE Suite imported code  
 VERSION		   : $Revision: 10477 $
 MODIFICATION DATE : $Date: 2013-04-08 11:08:42 +0200 (Mon, 08 Apr 2013) $
 COPYRIGHT (C)	 : 2008-2011 by Esterel Technologies. All Rights Reserved.
 UNAUTHORIZED ACCESS, USE, REPRODUCTION OR DISTRIBUTION IS PROHIBITED.
---------------------------------------------------------------------------- +*/

#include "wid_kcg_types.h"
#include <math.h>
#include "stdio.h"

#define _MIN_FLOAT_VALUE_AT_ONE 0.00000011920928955078125	   /* 2^-23: minimum value for a float near 1.0 */

#ifdef _BHVR_KCG_TYPES_H_
/*if called from a scade display behaviour, everything will be prefixed by BHVR_*/
#define array_char_255 BHVR_array_char_255
#define kcg_copy_array_char_255 BHVR_kcg_copy_array_char_255
#endif

void RemoveCharAtEnd_NumKeypad(array_char_255 *in_string,array_char_255 *out_string){
	int ii;
	
	kcg_copy_array_char_255(out_string,in_string);
	for(ii=1;ii<255;ii++){
		if( (*out_string)[ii]==0){
			(*out_string)[ii-1]=0;
			return;
		}
	}
	*out_string[255-1]=0;
	return;
}

void AddCharAtEnd_NumKeypad(array_char_255 *in_string,kcg_char character,array_char_255 *out_string){
	int ii;
	
	kcg_copy_array_char_255(out_string,in_string);
	for(ii=0;ii<255-1;ii++){
		if( (*out_string)[ii]==0){
			(*out_string)[ii]=character;
			(*out_string)[ii+1]=0;
			return;
		}
	}
	/*we always leave a 0 at position end*/
	return;
}

kcg_char SetCharacterCase(kcg_char c, kcg_bool caps_lock){
	if(caps_lock){
		/*to upper case*/
		if(c>='a' && c<= 'z') return c+ ('A'-'a');
		else return c;
	}else {
		/*to lower case*/
		if(c>='A' && c<= 'Z') return c- ('A'-'a');
		else return c;
	}
}

kcg_real Float_of_string_Strings(array_char_255 *string){
	float v;
	sscanf(*string,"%e",&v);
	return (kcg_real) v;
}

void FormatNumValue_Strings(
	kcg_real InValue,
	kcg_bool LeadingZeros, 
	kcg_int DisplaySign, 
	kcg_int NbDigitsIntPart, 
	kcg_int NbDigitsFractionalPart, 
	array_char_255 *OutString)
{
	kcg_int IndexInOutString, ii, DigitsInTruncPart, HiddenNumbers;
	kcg_int NbZeros;
	double MultiplierForDecPart;
	unsigned long int Trunc, Dec, tmp;
	
	/* index in the output string */
	IndexInOutString = 0;
	
	/* Determine the sign */
	if (InValue >= 0.0F && DisplaySign == 0) {
		(*OutString)[IndexInOutString] = '+';
		IndexInOutString++;
	}
	if(InValue < 0.0F && DisplaySign != 1) {
		(*OutString)[IndexInOutString] = '-';
		IndexInOutString++;
	}
	if (InValue < 0.0F)
		InValue = - InValue;
	
	/* Extract truncated  part of the Value */
	Trunc = (unsigned long int) floor(InValue);

	/* Compute MultiplierForDecPart, which is equal to 10^NbDigitsFractionalPart */
	MultiplierForDecPart = pow(10.0, (double) NbDigitsFractionalPart);

	/* Extract decimal part of the Value */
	Dec = (unsigned long int) floor((InValue-(double) Trunc) * MultiplierForDecPart + 0.5F);
	
	/* assert false */
	if (Dec >= MultiplierForDecPart) {
		Dec -= MultiplierForDecPart;
		Trunc += 1.0F;
	}

	/* count the number of digits in truncated part */
	DigitsInTruncPart = 0;
	tmp = Trunc;
	while (tmp > 0) {
		tmp /= 10;
		DigitsInTruncPart += 1;
	}
	if (DigitsInTruncPart == 0)
		DigitsInTruncPart = 1;

	/* Verify if some numbers must be hidden (because NbDigitsIntPart is too small) */
	if (NbDigitsIntPart < DigitsInTruncPart) {
		HiddenNumbers = DigitsInTruncPart - NbDigitsIntPart;
	}
	else {
		HiddenNumbers = 0;
	}

	if(NbDigitsIntPart > DigitsInTruncPart) NbZeros= NbDigitsIntPart - DigitsInTruncPart; else NbZeros=0;

	/* Fill leading zeros */
	if (LeadingZeros == kcg_true) {
		for(ii=0;ii<NbZeros;ii++) {
			(*OutString)[IndexInOutString] = '0';
			IndexInOutString++;
		}
	}
	
	/* Fill trunc part */
	if(DigitsInTruncPart>NbDigitsIntPart){ /* number is trunked*/
		unsigned long int quot;
		unsigned char rem;
		quot=Trunc;
		for(ii=0;ii<NbDigitsIntPart;ii++){
			rem=quot%10;
			quot=quot/10;
			(*OutString)[IndexInOutString+NbDigitsIntPart-ii-1]= '0'+rem;

		}
		IndexInOutString+=NbDigitsIntPart;
	}else{/*all digits are printed*/
		unsigned long int quot;
		unsigned char rem;
		quot=Trunc;
		for(ii=0;ii<DigitsInTruncPart;ii++){
			rem=quot%10;
			quot=quot/10;
			(*OutString)[IndexInOutString+DigitsInTruncPart-ii-1]= '0'+rem;

		}
		IndexInOutString+=DigitsInTruncPart;
	}
	

	if (NbDigitsFractionalPart > 0) {
		(*OutString)[IndexInOutString] = '.';
		IndexInOutString++;
	}
	
	/* Fill decimal part */
	{
		unsigned long int quot;
		unsigned char rem;
		quot=Dec;
		for(ii=0;ii<NbDigitsFractionalPart;ii++) {
			rem=quot % 10;
			quot=quot/10;
			(*OutString)[IndexInOutString+NbDigitsFractionalPart-ii-1] = '0'+rem;
		}
		IndexInOutString+=NbDigitsFractionalPart;
	}
	
	(*OutString)[IndexInOutString] = '\0';
}
	
