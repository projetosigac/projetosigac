@cd "C:/Users/thais/projetosigac/UA/UTICounts/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/uaadaptor.exe"  -d "C:\Users\thais\projetosigac\DF\UTILeitos.sgfx" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/thais/projetosigac/UA/UTICounts/Simulation" -k "C:/Users/thais/projetosigac/UA/UTICounts/Simulation/kcg_trace.xml" -o "UTICounts_UA_1" -node UTICounts  "C:\Users\thais\projetosigac\UA\UTICounts\UTICounts.sdy"
@IF ERRORLEVEL 1 GOTO failed
@move "UTICounts_UA_1.log" "UTICounts_UA_1_uaadaptor.log"
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE Display/../SCADE A661/bin/dfgen.exe" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/thais/projetosigac/UA/UTICounts/Simulation" -o "UTICounts_UA_1"  "C:\Users\thais\projetosigac\DF\UTILeitos.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "UTICounts_UA_1.log" "UTICounts_UA_1_dfgen.log"
"C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE Display\bin\ScadeDisplayConsole.exe" batch generateA661ServerConf "C:\Users\thais\projetosigac\DF\UTILeitos.sgfx" "C:/Users/thais/projetosigac/UA/UTICounts/Simulation/UTICounts_UA_1_conf.xml"
@exit 0
:failed
@exit 1
