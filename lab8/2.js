/****************************************/
/*Имя: 2.js */
/*Язык: JScript */
/*Описание: 1) Сохраняет копию системного реестра;
2) Вносит в реестр следующие изменения:
а) изменяет цветовую схму для текущего пользователя
б) скрывает стрелки ярлыков
в) скрывает отображение диска A: в папке "Мой компьютер"
3) Перезагружает компьютер
4) После перезагрузки компьютера через 30 секунд восстанавливает исходные значения реестра*/
/****************************************/

arg = WScript.Arguments;
ws = WScript.CreateObject("WScript.Shell");

if (arg.Count()==0) {
	WScript.Echo("/1 - performance");
	WScript.Echo("/2 - restore");
}
else {
	if (arg(0) == "/1") {
		var regedit = ws.Exec("regedit");
		WScript.sleep(1000);
		ws.AppActivate(regedit.ProcessID);
		WScript.sleep(1000);
		ws.SendKeys("{HOME}");
		WScript.sleep(1000);
		ws.SendKeys("%");
		WScript.sleep(1000);
		ws.SendKeys("{DOWN 2}~");
		WScript.sleep(1000);
		ws.SendKeys("regedit.reg~");
		WScript.sleep(10000);
		ws.SendKeys("{ESC}");
		WScript.sleep(1000);
		regedit.Terminate();
		ws.RegWrite("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\DWM\\AccentColor","368890","REG_DWORD");
		WScript.sleep(1000);
		ws.RegWrite("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\NoDrives","4","REG_DWORD");
		
		WScript.sleep(1000);
		ws.RegWrite("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Runonce\\regimport",WScript.ScriptFullName+" /2","REG_SZ");

		WScript.sleep(1000);

		ws.RegDelete("HKEY_CLASSES_ROOT\\lnkfile\\IsShortcut");
		WScript.sleep(1000);
		//regedit.reg
		ws.Exec("shutdown -r");
	}
	else
	if (arg(0) == "/2") {
		WScript.sleep(30000);
		//ws.RegWrite("HKEY_CLASSES_ROOT\\lnkfile\\IsShortcut", "", "REG_SZ");	
		//WScript.sleep(1000);
		ws.RegWrite("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\DWM\\AccentColor","65536","REG_DWORD");

		ws.RegWrite("HKEY_CLASSES_ROOT\\lnkfile\\IsShortcut", "", "REG_SZ");	

		ws.RegWrite("HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\NoDrives","0","REG_DWORD");
		
		ws.Exec("shutdown -r");			
	}
}