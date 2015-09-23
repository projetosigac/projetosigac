@cd "C:/ita/ces-65/REST-API/UserApplication/Simulation"
@set OCAMLRUNPARAM=b
"C:/ita/ces-65/scade/SCADE/bin/uaadaptor.exe"  -d "C:\ita\ces-65\REST-API\DefinitionFile\REST-API.sgfx" -n "C:/ita/ces-65/scade/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/ita/ces-65/REST-API/UserApplication/Simulation" -k "C:/ita/ces-65/REST-API/UserApplication/Simulation/kcg_trace.xml" -o "Main_UA_1" -node Main  "C:\ita\ces-65\REST-API\UserApplication\REST-API.sdy"
@IF ERRORLEVEL 1 GOTO failed
@move "Main_UA_1.log" "Main_UA_1_uaadaptor.log"
"C:/ita/ces-65/scade/SCADE Display/../SCADE A661/bin/dfgen.exe" -n "C:/ita/ces-65/scade/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/ita/ces-65/REST-API/UserApplication/Simulation" -o "Main_UA_1"  "C:\ita\ces-65\REST-API\DefinitionFile\REST-API.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "Main_UA_1.log" "Main_UA_1_dfgen.log"
"C:\ita\ces-65\scade\SCADE Display\bin\ScadeDisplayConsole.exe" batch generateA661ServerConf "C:\ita\ces-65\REST-API\DefinitionFile\REST-API.sgfx" "C:/ita/ces-65/REST-API/UserApplication/Simulation/Main_UA_1_conf.xml"
@exit 0
:failed
@exit 1
