:: This script counts all entries of a certain character in a given folder. Character is represented with its code.

@echo off
copy nul result > nul
for %%i in (%~2\*) do (
    copy nul temp > nul && for /l %%s in (1,1,%%~zi) do echo:>>temp) && fc /b %%i temp | find ": %~1" >> result
find /c ":" < result
del temp result
