@echo off 
echo Объединение и переименование файлов
copy A.txt + A.txt C.txt 
type C.txt 
pause 
ren A.txt FINA.txt 
ren A.txt FINB.txt 
echo Задание выполнено
pause