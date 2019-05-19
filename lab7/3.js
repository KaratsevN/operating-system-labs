var sh = WScript.CreateObject("WScript.Shell");
var pop;
pop = sh.Popup("—оздать на рабочем столе €рлык дл€ запуска сценари€ из задани€ 2?",0,"?",36);
if(pop == 6)
{
	var path1 = sh.CurrentDirectory + "\\2.js";
	var path2 = sh.SpecialFolders("Desktop") + "\\2a.lnk";
	var path3 = sh.SpecialFolders("Desktop") + "\\2b.lnk";
	var cjob = sh.Exec("cscript " + path2 + " > " + sh.SpecialFolders("Desktop") + "\\2a.txt");
	var link;
	link = sh.CreateShortcut(path2);
	link.TargetPath = path1;
	link.Arguments = "/1";
	link.Save();
	link = sh.CreateShortcut(path3);
	link.TargetPath = path1;
	link.Arguments = "/2";
	link.Save();
}