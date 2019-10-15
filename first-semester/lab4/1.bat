@ECHO OFF
:menu
Echo -------------------------------Menu-------------------------------
Echo 1. Show the conputer name;
Echo 2. Show all configurations of TCP/IP for all adapters;
Echo 3. Display the contents of the name mappings cache DNS client;
Echo 4. Purge DNS's cache;
Echo 5. Exit.
Set /p a="Input the number of operation: "
If %a% == 1 (
Hostname.exe  
goto menu
)
If %a% == 2 (
ipconfig /all 
goto menu
)
If %a% == 3 (
ipconfig /displaydns 
goto menu
)
If %a% == 4 (
ipconfig /flushdns 
goto menu
)
:exit
Pause