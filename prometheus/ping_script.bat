@echo off
:loop
ping -n 1 google.com >> ".\ping_results.txt"
timeout /t 30 /nobreak > nul
goto loop
