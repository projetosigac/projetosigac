#include "wid_kcg_consts.h"
#include "wid_kcg_imported_functions.h"
#include <string.h>

#ifdef _BHVR_KCG_TYPES_H_
/*if called from a scade display behaviour, everything will be prefixed by BHVR_*/
#define array_char_255 BHVR_array_char_255
#define kcg_copy_array_char_255 BHVR_kcg_copy_array_char_255

#define array_char_255_30 BHVR_array_char_255_30
#define kcg_copy_array_char_255_30 BHVR_kcg_copy_array_char_255_30

#endif

kcg_int char_to_KeyCode_VirtualKeyboard_(kcg_char Character){return (kcg_int) Character;}

void KeyLabels_VirtualKeyboard_(
	kcg_bool CapsLock,
	kcg_bool NumLock,
	array_char_255_30 *KeyLabels)
{
	int i;
	for(i=0;i<30;i++){
		(*KeyLabels)[i][1]=0;
	}
	if(CapsLock && !NumLock){
		(*KeyLabels)[ 0][0]='Q';
		(*KeyLabels)[ 1][0]='W';
		(*KeyLabels)[ 2][0]='E';
		(*KeyLabels)[ 3][0]='R';
		(*KeyLabels)[ 4][0]='T';
		(*KeyLabels)[ 5][0]='Y';
		(*KeyLabels)[ 6][0]='U';
		(*KeyLabels)[ 7][0]='I';
		(*KeyLabels)[ 8][0]='O';
		(*KeyLabels)[ 9][0]='P';
		(*KeyLabels)[10][0]='A';
		(*KeyLabels)[11][0]='S';
		(*KeyLabels)[12][0]='D';
		(*KeyLabels)[13][0]='F';
		(*KeyLabels)[14][0]='G';
		(*KeyLabels)[15][0]='H';
		(*KeyLabels)[16][0]='J';
		(*KeyLabels)[17][0]='K';
		(*KeyLabels)[18][0]='L';
		(*KeyLabels)[19][0]=';';
		(*KeyLabels)[20][0]='Z';
		(*KeyLabels)[21][0]='X';
		(*KeyLabels)[22][0]='C';
		(*KeyLabels)[23][0]='V';
		(*KeyLabels)[24][0]='B';
		(*KeyLabels)[25][0]='N';
		(*KeyLabels)[26][0]='M';
		(*KeyLabels)[27][0]='?';
		(*KeyLabels)[28][0]='{';
		(*KeyLabels)[29][0]='}';
	}else if(NumLock){
		
		(*KeyLabels)[ 0][0]='1';
		(*KeyLabels)[ 1][0]='2';
		(*KeyLabels)[ 2][0]='3';
		(*KeyLabels)[ 3][0]='4';
		(*KeyLabels)[ 4][0]='5';
		(*KeyLabels)[ 5][0]='6';
		(*KeyLabels)[ 6][0]='7';
		(*KeyLabels)[ 7][0]='8';
		(*KeyLabels)[ 8][0]='9';
		(*KeyLabels)[ 9][0]='0';
		(*KeyLabels)[10][0]='!';
		(*KeyLabels)[11][0]='@';
		(*KeyLabels)[12][0]='-';
		(*KeyLabels)[13][0]='_';
		(*KeyLabels)[14][0]='~';
		(*KeyLabels)[15][0]=':';
		(*KeyLabels)[16][0]='/';
		(*KeyLabels)[17][0]='\'';
		(*KeyLabels)[18][0]='\"';
		(*KeyLabels)[19][0]='\\';
		(*KeyLabels)[20][0]='=';
		(*KeyLabels)[21][0]='^';
		(*KeyLabels)[22][0]=';';
		(*KeyLabels)[23][0]='#';
		(*KeyLabels)[24][0]='%';
		(*KeyLabels)[25][0]='&';
		(*KeyLabels)[26][0]='*';
		(*KeyLabels)[27][0]='+';
		(*KeyLabels)[28][0]='[';
		(*KeyLabels)[29][0]=']';
	} else {
		(*KeyLabels)[ 0][0]='q';
		(*KeyLabels)[ 1][0]='w';
		(*KeyLabels)[ 2][0]='e';
		(*KeyLabels)[ 3][0]='r';
		(*KeyLabels)[ 4][0]='t';
		(*KeyLabels)[ 5][0]='y';
		(*KeyLabels)[ 6][0]='u';
		(*KeyLabels)[ 7][0]='i';
		(*KeyLabels)[ 8][0]='o';
		(*KeyLabels)[ 9][0]='p';
		(*KeyLabels)[10][0]='a';
		(*KeyLabels)[11][0]='s';
		(*KeyLabels)[12][0]='d';
		(*KeyLabels)[13][0]='f';
		(*KeyLabels)[14][0]='g';
		(*KeyLabels)[15][0]='h';
		(*KeyLabels)[16][0]='j';
		(*KeyLabels)[17][0]='k';
		(*KeyLabels)[18][0]='l';
		(*KeyLabels)[19][0]='.';
		(*KeyLabels)[20][0]='z';
		(*KeyLabels)[21][0]='x';
		(*KeyLabels)[22][0]='c';
		(*KeyLabels)[23][0]='v';
		(*KeyLabels)[24][0]='b';
		(*KeyLabels)[25][0]='n';
		(*KeyLabels)[26][0]='m';
		(*KeyLabels)[27][0]=',';
		(*KeyLabels)[28][0]='(';
		(*KeyLabels)[29][0]=')';
	}
}


