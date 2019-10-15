var shellObj = WScript.CreateObject("WScript.Shell");
var arguments;
arguments = WScript.Arguments;
if (arguments.Count() == 0) {
	WScript.Echo("Нет аргумента командной строки. Воспользуйтесь справкой: /?");
} else
if(arguments(0) == "/?") {
	WScript.Echo("Аргументы командной строки:\n/1  - Вывести имена и содержимое всех системных переменных окружения.\n/2  - Выводе всех специальных папок.\n/? - Справка.");
} else if(arguments(0) == "/1") {
	WScript.Echo("Перменные окружения:");
	var info = shellObj.Environment("System");
	finalInfo = new Enumerator(info);
	while(!finalInfo.atEnd()){
		WScript.Echo(finalInfo.item());
		finalInfo.moveNext();
	}
} else if(arguments(0) == "/2") {
	specialFolders = shellObj.SpecialFolders;
	WScript.Echo("Специальные папки:");
	for(var i = 0; i < specialFolders.Count(); i++)
	WScript.Echo(specialFolders(i));
} else  {
	WScript.Echo("Задан неверный аргумент командной строки. Воспользуйтесь справкой: /?");
}