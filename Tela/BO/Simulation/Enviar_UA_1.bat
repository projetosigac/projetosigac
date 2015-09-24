@cd "C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/uaadaptor.exe"  -d "C:\Users\Goku\Desktop\scade\BO\BO\BO.sgfx" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation" -k "C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation/kcg_trace.xml" -o "Enviar_UA_1" -node Enviar  "C:\Users\Goku\Desktop\scade\BO\BO\BO\BO.sdy"
@IF ERRORLEVEL 1 GOTO failed
@move "Enviar_UA_1.log" "Enviar_UA_1_uaadaptor.log"
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE Display/../SCADE A661/bin/dfgen.exe" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation" -o "Enviar_UA_1"  "C:\Users\Goku\Desktop\scade\BO\BO\BO.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "Enviar_UA_1.log" "Enviar_UA_1_dfgen.log"
"C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE Display\bin\ScadeDisplayConsole.exe" batch generateA661ServerConf "C:\Users\Goku\Desktop\scade\BO\BO\BO.sgfx" "C:/Users/Goku/Desktop/scade/BO/BO/BO/Simulation/Enviar_UA_1_conf.xml"
@exit 0
:failed
@exit 1
