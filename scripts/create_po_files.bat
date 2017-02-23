@echo OFF
create_po_files.exe "..\src" "..\locale_catalog" "demo"

cd ..\locale_catalog
if NOT EXIST .\pt_BR\LC_MESSAGES (
    mkdir .\pt_BR\LC_MESSAGES
    echo f | xcopy /f /y demo.pot .\pt_BR\LC_MESSAGES\demo.po
    cd pt_BR\LC_MESSAGES
    call demo.po
    echo f | xcopy /f /y demo.mo ..\..\..\locale\pt_BR\LC_MESSAGES\demo.mo
    goto :end
)

cd .\pt_BR\LC_MESSAGES
set VAR=
for /f %%i in ('msgattrib --untranslated demo.po') do set VAR=%%i
if NOT ("%VAR%")==("") (
    msgmerge -o demo.po demo.po ..\..\demo.pot
    call demo.po
)

echo f | xcopy demo.mo ..\..\..\locale\pt_BR\LC_MESSAGES\demo.mo /D /E /C /Q /H /R /Y /K

:end
cd ..\..\