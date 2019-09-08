@ECHO OFF
ECHO copy and del file
ECHO Это файл text1.txt>text1.txt
@mkdir DIR1
@cd DIR1
@mkdir DIR2
@cd DIR2
ECHO >textnew.txt
@cd ..
@cd ..
copy text1.txt DIR1/DIR2/textnew.txt

ECHO file has been copy and delete
pause