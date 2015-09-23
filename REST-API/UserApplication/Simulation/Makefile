#############################################################
######    Begin of Makefile
#############################################################

SCADE=C:\ita\ces-65\scade\SCADE\.

SHELL=cmd.exe

C_FLAGS = -O2 -pedantic

all: Main.exe Main.dll 

win32/Main.o: Main.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main.c" -o "win32\Main.o"	
	ar -r Main.a "win32\Main.o"

win32/kcg_types.o: kcg_types.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "kcg_types.c" -o "win32\kcg_types.o"	
	ar -r Main.a "win32\kcg_types.o"

win32/kcg_consts.o: kcg_consts.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "kcg_consts.c" -o "win32\kcg_consts.o"	
	ar -r Main.a "win32\kcg_consts.o"

win32/consts.o: ../../Custom/consts.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "..\..\Custom\consts.c" -o "win32\consts.o"

win32/rest_api.o: ../../Custom/rest_api.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "..\..\Custom\rest_api.c" -o "win32\rest_api.o"

win32/Main_UA_1.o: Main_UA_1.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main_UA_1.c" -o "win32\Main_UA_1.o"

win32/A661Cosim.o: ../../../scade/SCADE/lib/A661Cosim.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "..\..\..\scade\SCADE\lib\A661Cosim.c" -o "win32\A661Cosim.o"

win32/Main_cosim.o: Main_cosim.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main_cosim.c" -o "win32\Main_cosim.o"

win32/Main_type.o: Main_type.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main_type.c" -o "win32\Main_type.o"

win32/Main_mapping.o: Main_mapping.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main_mapping.c" -o "win32\Main_mapping.o"

win32/Main_interface.o: Main_interface.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main_interface.c" -o "win32\Main_interface.o"

win32/SmuProxy.o: C:/ita/ces-65/scade/SCADE/lib/SmuProxy.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "C:\ita\ces-65\scade\SCADE\lib\SmuProxy.c" -o "win32\SmuProxy.o"

Main.dll: win32/Main.o win32/kcg_types.o win32/kcg_consts.o win32/consts.o win32/rest_api.o win32/Main_UA_1.o win32/A661Cosim.o win32/Main_cosim.o win32/Main_type.o win32/Main_mapping.o win32/Main_interface.o win32/SmuProxy.o SmuExport.def 
	dllwrap --driver-name=gcc  "win32\consts.o" "win32\rest_api.o" "win32\Main_UA_1.o" "win32\A661Cosim.o" "win32\Main_cosim.o" "win32\Main_type.o" "win32\Main_mapping.o" "win32\Main_interface.o" "win32\SmuProxy.o" "Main.a" --def "SmuExport.def" -lm -lwsock32 --dllname "Main.dll" 

SmuExport.def: C:/ita/ces-65/scade/SCADE/lib/SmuExport.def
	copy "C:\ita\ces-65\scade\SCADE\lib\SmuExport.def" "SmuExport.def"

win32/Main_dll.o: Main_dll.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "Main_dll.c" -o "win32\Main_dll.o"

win32/SmuMainWindows.o: C:/ita/ces-65/scade/SCADE/lib/SmuMainWindows.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\scade\SCADE\include" -I"..\..\..\scade\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "C:\ita\ces-65\scade\SCADE\lib\SmuMainWindows.c" -o "win32\SmuMainWindows.o"

Main.exe: win32/Main_dll.o win32/SmuMainWindows.o 
	gcc "win32\Main_dll.o" "win32\SmuMainWindows.o" -lm -lwsock32 -o "Main.exe" 

Main_cosim.c: Main_UA_1.h


#############################################################
######    End of Makefile
#############################################################
