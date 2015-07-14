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
int g, Rx1, Rx2;
//#=================================================================================================
//#=================================================================================================
int main( void ) {
    Tweeq_Init();

    _TRISB5 = 1;
    U2RXRbits.U2RXR = 1; //
    RPB10Rbits.RPB10R = 2; //
    //U2BRG = (SYS_FREQ/17/(9600));
    UARTSetDataRate(UART2, SYS_FREQ, 9600);
    U2MODE = UART_EN;
    U2STA = (UART_RX_ENABLE | UART_TX_ENABLE);


    Delayms(2000);

    g = 0;
    while(1)
    {
        Rx1 = COMM1_Rx();
        if (Rx1 >= 0)
        {
            COMM2_Tx(Rx1);
        }

        Rx2 = COMM2_Rx();
        if (Rx2 >= 0)
        {
            COMM1_Tx(Rx2);

            if (Rx2 == 0x48)
            {
                LED_LOW;
            }
            if (Rx2 == 0x4C)
            {
                LED_HIGH;
            }
        }
    }

    return (EXIT_SUCCESS);
}
//#=================================================================================================
//#=================================================================================================
