@echo off
:start
gen.exe
dslow.exe
dfull.exe
fc strings.ans strings.out
if errorlevel 1 goto end
goto start
:end