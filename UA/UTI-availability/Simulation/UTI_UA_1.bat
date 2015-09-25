@cd "C:/Users/thais/projetosigac/UA/UTI-availability/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/uaadaptor.exe"  -d "C:\Users\thais\projetosigac\DF\DF_US08.sgfx" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/thais/projetosigac/UA/UTI-availability/Simulation" -k "C:/Users/thais/projetosigac/UA/UTI-availability/Simulation/kcg_trace.xml" -o "UTI_UA_1" -node UTI  "C:\Users\thais\projetosigac\UA\UTI-availability\UTI-availability.sdy"
@IF ERRORLEVEL 1 GOTO failed
@move "UTI_UA_1.log" "UTI_UA_1_uaadaptor.log"
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE Display/../SCADE A661/bin/dfgen.exe" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/thais/projetosigac/UA/UTI-availability/Simulation" -o "UTI_UA_1"  "C:\Users\thais\projetosigac\DF\DF_US08.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "UTI_UA_1.log" "UTI_UA_1_dfgen.log"
"C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE Display\bin\ScadeDisplayConsole.exe" batch generateA661ServerConf "C:\Users\thais\projetosigac\DF\DF_US08.sgfx" "C:/Users/thais/projetosigac/UA/UTI-availability/Simulation/UTI_UA_1_conf.xml"
@exit 0
:failed
@exit 1
