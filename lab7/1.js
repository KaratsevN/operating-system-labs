/****************************************/
/*Имя: 1.js */
/*Язык: JScript */
/*Описание: */
/****************************************/

var ws = WScript.CreateObject("WScript.Shell");
var ok = ws.Popup("Run the calculator?",0,"Unchuris_08",1);
if(ok == 1) {
	ws.LogEvent(0,"The user agreed to start the calculator");
	calc = ws.Exec("calc");
	WScript.Sleep(700);
	ws.AppActivate(calc.ProcessID);
	ws.SendKeys("3{+}");
	WScript.Sleep(700);
	ws.SendKeys("2");
	WScript.Sleep(700);
	ws.SendKeys("~");
	WScript.Sleep(1000);
	ws.SendKeys("^c");
	WScript.Sleep(1000);
	ws.AppActivate(calc.ProcessID);
	ws.SendKeys("%{F4}");

	ok = ws.Popup("Run a notepad?",0,"Unchuris_08",1);
	if(ok == 1) {
		ws.LogEvent(0,"The user agreed to start the notebook");
		npad = ws.Exec("notepad");
		ws.AppActivate(npad.ProcessID);
		WScript.Sleep(500);
		ws.SendKeys("Result of calculations~");	
		WScript.Sleep(500);
		ws.SendKeys("3{+}2=");
		WScript.Sleep(500);
		ws.SendKeys("^v~");
		WScript.Sleep(500);
		ws.SendKeys("End~");
		WScript.Sleep(1000);

		ok = ws.Popup("Save a text file?",0,"Unchuris_08",1);
		if(ok == 1) {
			ws.LogEvent(0,"The user agreed to save the text file");
			ws.SendKeys("^s");
			WScript.Sleep(500);
			ws.SendKeys("1.txt");
			WScript.Sleep(1000);
			ws.SendKeys("~");
			WScript.Sleep(1000);
			ws.AppActivate(npad.ProcessID);
			ws.SendKeys("%{F4}");
		}
		else ws.LogEvent(0,"The user did not agree to save the text file");	
	}
	else ws.LogEvent(0,"The user did not agree to start notepad");	
}
else ws.LogEvent(0,"The user did not agree to start the calculator");