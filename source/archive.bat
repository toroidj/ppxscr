@echo off
set RETAIL=1
rem *** set value ***
set arcname=ppxscr22.zip
set readme=PPXSCR.TXT
set srcname=ppxscrsr.7z
set exename=PPXSCR

rem *** main ***
del /q *.zip 2> NUL
del /q *.map 2> NUL

del /q *.obj 2> NUL
del /q *.res 2> NUL
rem C++ Builder �ō쐬
call mbc6 -DRELEASE
call m64 -DRELEASE
call marm64 -DRELEASE

tfilesign sp %exename%.DLL %exename%.DLL
tfilesign sp %exename%64.DLL %exename%64.DLL
tfilesign sp %exename%64A.DLL %exename%64A.DLL

rem *** Source Archive ***
if %RETAIL%==0 goto :skipsource

for %%i in (*) do CT %readme% %%i
ppb /c %%u/7-zip32.dll,a %srcname% -hide -mx=9 MAKE* GNUmake* *.BAT *.C *.CPP *.H *.HPJ *.pl *.RC *.RH *.ICO *.BPR *.BPF *.IDL *.TLB *.CFG *.DEF vs2015\ppxscr.vcxproj vs2015\ppxscr.sln
CT %readme% %srcname%
:skipsource

for %%i in (*.exe) do CT %readme% %%i
for %%i in (*.dll) do CT %readme% %%i
for /R %%i in (*.sln) do CT %readme% %%i
for /R %%i in (*.vc*) do CT %readme% %%i
for %%i in (sample*.*) do CT %readme% %%i
ppb /c %%u/7-ZIP32.DLL,a -tzip -hide -mx=7 %arcname% %readme% PPXSCR*.dll sample*.* %srcname%
tfilesign s %arcname% %arcname%
CT %readme% %arcname%
del /q %srcname% 2> NUL
