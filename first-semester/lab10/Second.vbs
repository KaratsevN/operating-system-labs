/***********************************************************/
/* Имя: TextFile.js */
/* Язык: JScript */
/* Описание: Работа с текстовым файлом (запись и чтение
информации)*/
/***********************************************************/

Set objShellApp = CreateObject("Shell.Application")
Set objFolder = objShellApp.NameSpace("C:\")
Set objFolderItems = objFolder.Items()
arr = array("*.tmp")
For Each element in arr
    objFolderItems.Filter 64+128, element
    For Each file in objFolderItems
        File.DeleteFile (sFile)

                        If Err.Number <> 0 Then

                                   WScript.Echo "Error deleting file: " & sFile
        If file.DeleteFile file.
        MsgBox file
    Next
Next