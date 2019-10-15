@echo off
set /p a="Input full way of file: "
IF EXIST %a% (
attrib +s %a%
) else (
echo File not found
)
pause