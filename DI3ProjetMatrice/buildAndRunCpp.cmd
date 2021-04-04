cd %userprofile%\source\repos\DI3ProjetMatrice\DI3ProjetMatrice\Debug
del "DI3ProjetMatrice.exe"
cl /W4 /EHsc ../source/DI3ProjetMatrice.cpp ../source/C* ../source/Test.cpp /link > DI3ProjetMatrice.tlog/log.txt
cd DI3ProjetMatrice.tlog
cls
REM ***************** COMPILATION *****************
type log.txt
REM *** Le contenu des logs de compilation est a : Debug/DI3ProjetMatrice.tlog/DI3ProjetMatrice.tlog ***
cd ../
REM ******************* CONSOLE *******************
DI3ProjetMatrice.exe
