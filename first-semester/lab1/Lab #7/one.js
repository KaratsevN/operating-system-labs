var sh = WScript.CreateObject("WScript.Shell");
var arg;
arg = WScript.Arguments;
if (arg.Count() == 0) 
{
	sh.LogEvent(1,"��� ��������� ��������� ������");
	WScript.Echo("��� ��������� ��������� ������");
}
else
if(arg(0) == "/?")
{
	WScript.Echo("��������� ��������� ������:");
	WScript.Echo("/1  - ��������� ���� �����, ��������� � ����������");
	WScript.Echo("/2  - ������� �� ����� ���� � ������������ ����� ������� ���������, ��� ����������� �������� � ������ WSH");
	WScript.Echo("/? - �������");
}
else
if(arg(0) == "/2")
{
	WScript.Echo("���� � ������������ ����� ������� ���������:");
	WScript.Echo(WScript.FullName);
	WScript.Echo(" ");
	WScript.Echo("��� ����������� ��������:");
	WScript.Echo(WScript.ScriptName);
	WScript.Echo(" ");
	WScript.Echo("������ WSH:");
	WScript.Echo(WScript.Version);
}
else
if(arg(0) == "/1")
{
	var a = 0, b = 0;
	WScript.Echo("������� ������ �����:");
	a = WScript.StdIn.ReadLine();
	WScript.Echo("������� ������ �����:");
	b = WScript.StdIn.ReadLine();
	if (a > b) WScript.Echo(a,">",b);
	else if (a < b) WScript.Echo(a,"<",b);
	else WScript.Echo(a,"=",b);
}
else 
{
	sh.LogEvent(1,"����� �������� �������� ��������� ������");
	WScript.Echo("����� �������� �������� ��������� ������");
}