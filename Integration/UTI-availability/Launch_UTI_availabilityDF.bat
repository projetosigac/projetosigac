@SET PATH=C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE A661/bin;%PATH%
@echo off
cd .
start A661Server.exe "..\..\DF\DF_US08DF\server_conf.xml" "..\..\DF\DF_US08DF\DF_US08.bin"
