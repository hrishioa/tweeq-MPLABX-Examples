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

    mOLED_Clear();
    COMM1_Tx_Str("Hi RABBIT \n");

    i2c_Init();
    MPU_SetAddr(0x68);
    MPU_Init();
    

    short Y, CPos;
    CPos = 600;
    while(1)
    {
        Y = MPU_Read_Y();
        putsUART1(" x  :   d = ");
        sprintf(OS_Str_1, "%d ", Y);
        putsUART1(( unsigned char * )OS_Str_1);
        putsUART1("> \n");

        mOLED_Clear_Array();
        mOLED_Print_Str(0, 0, "Y=");
        mOLED_Print_Str(20, 0, OS_Str_1); //display accel

        if (Y > 5000)
        {
            CPos = CPos + 20;
            if (CPos > 1180)
            {
                CPos = 1180;
            }
        }else
        if (Y < -5000)
        {
            CPos = CPos - 20;
            if (CPos < 100)
            {
                CPos = 100;
            }
        }
        mOLED_Draw_Circle(CPos/10, 16, 6);

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
