/* 
 */
#define _SUPPRESS_PLIB_WARNING 1
#include <p32xxxx.h>
#include <plib.h>
#include "HMain.h"
//config
#pragma config FPLLMUL = MUL_20, FPLLIDIV = DIV_2, FPLLODIV = DIV_2
#pragma config POSCMOD = HS, FNOSC = PRIPLL, FPBDIV = DIV_1
#pragma config FWDTEN = OFF
#pragma config FSOSCEN = OFF
#pragma config WDTPS = PS4
#pragma config CP=OFF, BWP=OFF
#pragma config FCKSM = CSDCMD
#pragma config ICESEL   = ICS_PGx1      // ICE/ICD Comm Channel Select
#pragma config JTAGEN = OFF
//USB
#pragma config FUSBIDIO = OFF
#pragma config FVBUSONIO = OFF

unsigned char OS_Str_1[64];

//#=================================================================================================
//#=================================================================================================
int __attribute__((section("XCodeMain"))) main( void ) {
    Tweeq_Init();

    mOLED_Init();
    mOLED_Clear();

    i2c_Init();
    MPU_SetAddr(0x68);
    MPU_Init();
    
    short Y, CPos;
    CPos = 600;
    while(1)
    {        
        Y = MPU_Read_Y();
        sprintf(OS_Str_1, "%d ", Y);

        mOLED_Clear_Array();

        mOLED_Print_Str(0, 0, "TweeQ");
        mOLED_Print_Str(0, 1, "Y=");
        mOLED_Print_Str(20, 1, OS_Str_1); //display accel

        mOLED_Refresh(); //dont forget to refresh

        LED_HIGH;
        Delayms(25);
        LED_LOW;
        Delayms(25);
    }

    return (EXIT_SUCCESS);
}
//#=================================================================================================
//#=================================================================================================
