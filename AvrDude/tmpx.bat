@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -V -p 32MX150F128D -c stk500v2 -P COM3 -V -U flash:w:"C:\+Allegro\PIC32Core\BLE_01\dist\default\production\BLE_01.production.hex":i
pause