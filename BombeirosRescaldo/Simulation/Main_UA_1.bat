@cd "C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation"
@set OCAMLRUNPARAM=b
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/uaadaptor.exe"  -d "C:\Users\Marrcio\Copy\EstudosRemote\ITA\Cunha\SI-GAC\BombeirosRescaldo\BombeirosRescaldo.sgfx" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation" -k "C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation/kcg_trace.xml" -o "Main_UA_1" -node Main  "C:\Users\Marrcio\Copy\EstudosRemote\ITA\Cunha\SI-GAC\BombeirosRescaldo\BombeirosRescaldo.sdy"
@IF ERRORLEVEL 1 GOTO failed
@move "Main_UA_1.log" "Main_UA_1_uaadaptor.log"
"C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE Display/../SCADE A661/bin/dfgen.exe" -n "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin/../../SCADE Display/config/Workspace/environments/UAPageCreator/A661Norm/a661.xml" -outdir "C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation" -o "Main_UA_1"  "C:\Users\Marrcio\Copy\EstudosRemote\ITA\Cunha\SI-GAC\BombeirosRescaldo\BombeirosRescaldo.sgfx"
@IF ERRORLEVEL 1 GOTO failed
@move "Main_UA_1.log" "Main_UA_1_dfgen.log"
"C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE Display\bin\ScadeDisplayConsole.exe" batch generateA661ServerConf "C:\Users\Marrcio\Copy\EstudosRemote\ITA\Cunha\SI-GAC\BombeirosRescaldo\BombeirosRescaldo.sgfx" "C:/Users/Marrcio/Copy/EstudosRemote/ITA/Cunha/SI-GAC/BombeirosRescaldo/Simulation/Main_UA_1_conf.xml"
@exit 0
:failed
@exit 1
