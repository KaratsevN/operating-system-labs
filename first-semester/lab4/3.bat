@echo off

echo Search for an executable file in the task list
tasklist /fi "ImageName eq 3.exe"

pause

set /p name="Enter the PID of the task to complete: "
taskkill /pid %name%
pause