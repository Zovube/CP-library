@echo off

del xxx.out
for /L %%i in (0, 1, 5) do (
	my_stack.exe 
	stl_stack.exe
)
