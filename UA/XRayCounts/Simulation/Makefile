#############################################################
######    Begin of Makefile
#############################################################

SCADE=C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\.

SHELL=cmd.exe

C_FLAGS = -O2 -pedantic

all: XRayCounts.exe XRayCounts.dll 

win32/XRayCounts.o: XRayCounts.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts.c" -o "win32\XRayCounts.o"	
	ar -r XRayCounts.a "win32\XRayCounts.o"

win32/kcg_types.o: kcg_types.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "kcg_types.c" -o "win32\kcg_types.o"	
	ar -r XRayCounts.a "win32\kcg_types.o"

win32/kcg_consts.o: kcg_consts.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "kcg_consts.c" -o "win32\kcg_consts.o"	
	ar -r XRayCounts.a "win32\kcg_consts.o"

win32/XRayCounts_UA_1.o: XRayCounts_UA_1.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts_UA_1.c" -o "win32\XRayCounts_UA_1.o"

win32/A661Cosim.o: ../../../../../../Program\ Files\ (x86)/Esterel\ Technologies/Esterel\ SCADE\ 6.4.2/SCADE/lib/A661Cosim.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\lib\A661Cosim.c" -o "win32\A661Cosim.o"

win32/XRayCounts_cosim.o: XRayCounts_cosim.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts_cosim.c" -o "win32\XRayCounts_cosim.o"

win32/XRayCounts_type.o: XRayCounts_type.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts_type.c" -o "win32\XRayCounts_type.o"

win32/XRayCounts_mapping.o: XRayCounts_mapping.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts_mapping.c" -o "win32\XRayCounts_mapping.o"

win32/XRayCounts_interface.o: XRayCounts_interface.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts_interface.c" -o "win32\XRayCounts_interface.o"

win32/SmuProxy.o: C:/Program\ Files\ (x86)/Esterel\ Technologies/Esterel\ SCADE\ 6.4.2/SCADE/lib/SmuProxy.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\lib\SmuProxy.c" -o "win32\SmuProxy.o"

XRayCounts.dll: win32/XRayCounts.o win32/kcg_types.o win32/kcg_consts.o win32/XRayCounts_UA_1.o win32/A661Cosim.o win32/XRayCounts_cosim.o win32/XRayCounts_type.o win32/XRayCounts_mapping.o win32/XRayCounts_interface.o win32/SmuProxy.o SmuExport.def 
	dllwrap --driver-name=gcc  "win32\XRayCounts_UA_1.o" "win32\A661Cosim.o" "win32\XRayCounts_cosim.o" "win32\XRayCounts_type.o" "win32\XRayCounts_mapping.o" "win32\XRayCounts_interface.o" "win32\SmuProxy.o" "XRayCounts.a" --def "SmuExport.def" -lm -lwsock32 --dllname "XRayCounts.dll" 

SmuExport.def: C:/Program\ Files\ (x86)/Esterel\ Technologies/Esterel\ SCADE\ 6.4.2/SCADE/lib/SmuExport.def
	copy "C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\lib\SmuExport.def" "SmuExport.def"

win32/XRayCounts_dll.o: XRayCounts_dll.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "XRayCounts_dll.c" -o "win32\XRayCounts_dll.o"

win32/SmuMainWindows.o: C:/Program\ Files\ (x86)/Esterel\ Technologies/Esterel\ SCADE\ 6.4.2/SCADE/lib/SmuMainWindows.c
	gcc -I"." -I"$(SCADE)" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\include" -I"..\..\..\..\..\..\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\libraries\libmathext" $(C_FLAGS) -DBUILD_DLL -DEXTENDED_SIM -DSIM -DWIN32 -D_CONSOLE -D_MBCS -c "C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE\lib\SmuMainWindows.c" -o "win32\SmuMainWindows.o"

XRayCounts.exe: win32/XRayCounts_dll.o win32/SmuMainWindows.o 
	gcc "win32\XRayCounts_dll.o" "win32\SmuMainWindows.o" -lm -lwsock32 -o "XRayCounts.exe" 

XRayCounts_cosim.c: XRayCounts_UA_1.h


#############################################################
######    End of Makefile
#############################################################
