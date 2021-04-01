cd %userprofile%\source\repos\DI3ProjetMatrice\DI3ProjetMatrice\Debug
cls
REM ***************** COMPILATION *****************
cl /W4 /EHsc "../source/DI3ProjetMatrice.cpp" /link
REM **************** CONSOLE **********************
"DI3ProjetMatrice.exe"
