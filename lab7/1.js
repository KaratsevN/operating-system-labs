var arguments;
arguments = WScript.Arguments;
if (arguments.Count() == 0) {
	WScript.Echo("��� ��������� ��������� ������. �������������� ��������: /?");
} else
if(arguments(0) == "/?") {
	WScript.Echo("��������� ��������� ������:\n/1  - ��������� ���� �����, ��������� � ����������\n/2  - ������� �� ����� ���� � ������������ ����� ������� ���������, ��� ����������� �������� � ������ WSH\n/? - �������");
} else if(arguments(0) == "/1") {
	
	var a = 0, b = 0;
	WScript.Echo("������� ������ �����:");
	a = WScript.StdIn.ReadLine();
	WScript.Echo("������� ������ �����:");
	b = WScript.StdIn.ReadLine();
	if (a > b)
		WScript.Echo(a,">",b);
	else if
		(a < b) WScript.Echo(a,"<",b);
	else
		WScript.Echo(a,"=",b);
} else if(arguments(0) == "/2") {
	WScript.Echo("���� � ������������ ����� ������� ���������:\n" + WScript.FullName);
	WScript.Echo("��� ����������� ��������:\n" + WScript.ScriptName);
	WScript.Echo("������ WSH:\n" + WScript.Version);
} else  {
	WScript.Echo("����� �������� �������� ��������� ������. �������������� ��������: /?");
}