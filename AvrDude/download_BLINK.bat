@echo off
color f0
title AvrDude GUI Command Window
@echo.
@echo. trying to connect to device...
avrdude -p 32MX150F128D -c stk500v2 -P COM3 -V -U flash:w:"D:\+Dev\+tweeq\BLE_BLINK\dist\default\production\BLE_BLINK.production.hex":i
pause