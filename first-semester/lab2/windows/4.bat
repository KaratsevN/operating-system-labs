@echo off
echo Input "Help" for getting help
:start
set /p a="Input full way of directory: "
if ERRORLEVEL 1 goto start
if %a%==help or %a%==Help goto help
set /p b="Input full way of backup directory: "
if ERRORLEVEL 1 (
md %a%-copy
set b=%a%-copy
)
:menu
echo 1. Substitution of files
echo 2. Addendum a file
echo 3. Deleting
echo 4. Help
echo Exit - any other key
set /p c="Input a number of operation: "
if %c%==1 goto one
if %c%==2 goto two
if %c%==3 goto three
if %c%==4 goto help
goto exit

:one
copy %a%\* %b%
goto menu

:two
set d=%cd%
cd %a%
for %%i in (*) do (
if not exist %b%\%%~nxi (
copy %%i %b%
)
)
cd %d%
goto menu

:three
set d=%cd%
cd %b%
for %%i in (*) do (
if not exist %a%\%%~nxi (
del %%i
)
)
cd %d%
goto menu

:help
echo 4.bat - creates a backup copy of directory.
echo 1. You have to input a way of directory correctly;
echo 2. You have to input a way of backup directory, if you don't input name
echo    of directory. It will be created at the same section;
echo 3. There are 3 operation for working with files.
goto menu

:exit
echo Done!
pause
