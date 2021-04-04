cd %userprofile%\source\repos\DI3ProjetMatrice\DI3ProjetMatrice\Debug
del "DI3ProjetMatrice.exe"
cl /W4 /EHsc ../source/DI3ProjetMatrice.cpp ../source/CException.cpp ../source/CFichier.cpp ../source/CMatrice.cpp ../source/CMatriceDouble.cpp ../source/CMatriceCaractere.cpp ../source/CMatriceEntier.cpp /link > DI3ProjetMatrice.tlog/log.txt
cd DI3ProjetMatrice.tlog
cls
REM ***************** COMPILATION *****************
type log.txt
REM *** Le contenu des logs de compilation est a : Debug/DI3ProjetMatrice.tlog/DI3ProjetMatrice.tlog ***
cd ../
REM ******************* CONSOLE *******************
DI3ProjetMatrice.exe
