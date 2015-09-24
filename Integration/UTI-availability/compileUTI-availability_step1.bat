@SET PATH=C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/bin;%PATH%
@echo off
cd .
call uaadaptor.exe -n "C:\Program Files (x86)\Esterel Technologies\Esterel SCADE 6.4.2\SCADE Display\config\Workspace\environments\UAPageCreator\A661Norm\a661.xml"  -k "..\..\UA\UTI-availability\KCG\kcg_trace.xml" -d "..\..\DF\DF_US08.sgfx" "..\..\UA\UTI-availability\UTI-availability.sdy" -outdir "..\..\UA\UTI-availability\KCG"
pause