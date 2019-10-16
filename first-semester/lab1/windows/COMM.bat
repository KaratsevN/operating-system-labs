@echo off 
echo Копирование и удаление файла
md D:\СББ-701\DIR1\DIR2 
copy D:\СББ-701\TEXT1.txt D:\СББ-701\dir1\dir2\TEXTNEW.txt 
del TEXT1.txt 
echo Файл скопирован и удален
pause