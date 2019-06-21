@echo off
set MATLAB=E:\Applications\Matlab
"%MATLAB%\bin\win64\gmake" -f PWM_emulator.mk  ISPROTECTINGMODEL=NOTPROTECTING
