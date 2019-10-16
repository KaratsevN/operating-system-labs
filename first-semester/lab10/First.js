/***********************************************************/
/* Имя: TextFile.js */
/* Язык: JScript */
/* Описание: Работа с текстовым файлом (запись и чтение
информации)*/
/***********************************************************/
var FSO,F,s, fo, drive; //Объявляем переменные
var ForReading = 1; //Инициализируем константы
//Создаем объект FileSystemObject
FSO=WScript.CreateObject("Scripting.FileSystemObject");
fo = FSO.GetFolder("C:\\Users\\nekit\\Documents\\git\\operating-system-labs\\first-semester\\lab10");
//Создаем на диске С: текстовый файл TestFile.txt
F= fo.CreateTextFile("testfile.txt", true);
var myObject, drive;
        myObject = new ActiveXObject("Scripting.FileSystemObject");
        drive = myObject.GetDrive("c:\\")

F.WriteLine("File System: " + drive.FileSystem);
F.WriteLine("Avalible Space: " + drive.FreeSpace);
F.WriteLine("Is Ready: " + drive.IsReady);
F.WriteLine("Path: " + drive.Path);
F.WriteLine("Root Folder: " + drive.RootFolder);
F.WriteLine("Serial Number: " + drive.SerialNumber);
F.WriteLine("Share Name: " + drive.ShareName);
F.WriteLine("Total Size: " + drive.TotalSize);
F.WriteLine("Volume Name: " + drive.VolumeName);

F.WriteBlankLines(1);

//Закрываем файл
F.Close();
//Открываем файл для чтения
/*
F=FSO.OpenTextFile("С:WTestFile.txt", ForReading);
//Пропускаем в файле две первые строки
F.SkipLine();
F.SkipLine();
s="Третья строка из файла С:WTestFile.txt:\n";
//Считываем из файла третью, строку
s+=F.ReadLine();
//Выводим информацию на экран
WScript.Echo(s);
*/
/********* Конец *******************************************/
/*
Свойства объекта Drive. Сам объект Drive создается
с помощью метода GetDrive объекта
FileSystemObject
*/