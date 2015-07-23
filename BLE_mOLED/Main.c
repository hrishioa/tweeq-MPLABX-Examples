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

    COMM1_Tx_Str("HELLO \n");

    mOLED_Print_Str(0, 0, "HELLO");

    mOLED_Refresh();

    while(1)
    {
        LED_HIGH;
        Delayms(500);
        LED_LOW;
        Delayms(500);
    }

    return (EXIT_SUCCESS);
}
//#=================================================================================================
//#=================================================================================================
