var arguments;
arguments = WScript.Arguments;
if (arguments.Count() == 0) {
	WScript.Echo("Нет аргумента командной строки. Воспользуйтесь справкой: /?");
} else
if(arguments(0) == "/?") {
	WScript.Echo("Аргументы командной строки:\n/1  - Сравнение двух чисел, введенных с клавиатуры\n/2  - Выводит на экран путь к исполняемому файлу сервера сценариев, имя запущенного сценария и версию WSH\n/? - Справка");
} else if(arguments(0) == "/1") {
	
	var a = 0, b = 0;
	WScript.Echo("Введите первое число:");
	a = WScript.StdIn.ReadLine();
	WScript.Echo("Введите второе число:");
	b = WScript.StdIn.ReadLine();
	if (a > b)
		WScript.Echo(a,">",b);
	else if
		(a < b) WScript.Echo(a,"<",b);
	else
		WScript.Echo(a,"=",b);
} else if(arguments(0) == "/2") {
	WScript.Echo("Путь к исполняемому файлу сервера сценариев:\n" + WScript.FullName);
	WScript.Echo("Имя запущенного сценария:\n" + WScript.ScriptName);
	WScript.Echo("Версия WSH:\n" + WScript.Version);
} else  {
	WScript.Echo("Задан неверный аргумент командной строки. Воспользуйтесь справкой: /?");
}