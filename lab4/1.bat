@echo off

:Menu
echo Menu:
echo 1) displays the computer name;
echo 2) displays full TCP / IP configuration for all adapters;
echo 3) displays the contents of the client's DNS mapping cache;
echo 4) clears the DNS cache;
echo 0) exit.

set /p k="Enter the required character: "
if %k%==1 goto Name
if %k%==2 goto Config
if %k%==3 goto DNS_Out
if %k%==4 goto FlushDns
if %k%==0 goto Exit
goto Menu

:Name

hostname

pause
goto Menu

:Config

ipconfig /all

pause
goto Menu

:DNS_Out

ipconfig /displaydns

pause
goto Menu

:FlushDns

ipconfig /flushdns

pause
goto Menu

:Exit
pause