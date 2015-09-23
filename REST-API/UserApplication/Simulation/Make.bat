@SET PATH=C:/ita/ces-65/scade/SCADE/../contrib/Msys/mingw/bin;%PATH%
@SET INCLUDE=C:/ita/ces-65/scade/SCADE/../contrib/Msys/mingw/include
@SET LIB=C:/ita/ces-65/scade/SCADE/../contrib/Msys/mingw/lib
@IF "-B"=="%1" SET ARG=%1
@mingw32-make.exe %ARG%
