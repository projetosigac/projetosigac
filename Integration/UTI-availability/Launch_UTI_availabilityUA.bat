@SET PATH=C:/cygwin/bin;%PATH%
@echo off
cd .
call UTI-availability 127.0.0.1 1231 224.255.255.255 127.0.0.1 12340
pause