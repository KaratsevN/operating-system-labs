var shellObj = WScript.CreateObject("WScript.Shell");
var arguments;
arguments = WScript.Arguments;
if (arguments.Count() == 0) {
	WScript.Echo("��� ��������� ��������� ������. �������������� ��������: /?");
} else
if(arguments(0) == "/?") {
	WScript.Echo("��������� ��������� ������:\n/1  - ������� ����� � ���������� ���� ��������� ���������� ���������.\n/2  - ������ ���� ����������� �����.\n/? - �������.");
} else if(arguments(0) == "/1") {
	WScript.Echo("��������� ���������:");
	var info = shellObj.Environment("System");
	finalInfo = new Enumerator(info);
	while(!finalInfo.atEnd()){
		WScript.Echo(finalInfo.item());
		finalInfo.moveNext();
	}
} else if(arguments(0) == "/2") {
	specialFolders = shellObj.SpecialFolders;
	WScript.Echo("����������� �����:");
	for(var i = 0; i < specialFolders.Count(); i++)
	WScript.Echo(specialFolders(i));
} else  {
	WScript.Echo("����� �������� �������� ��������� ������. �������������� ��������: /?");
}