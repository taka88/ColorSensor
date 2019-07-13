/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC18F14K22
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
#include "mcc_generated_files/mcc.h"
#include <xc.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "skI2Clib.h"
#include "skS11059-02DT.h"
#include "skI2CLCDlib.h"

//void Color_Init();
void writeCommand_Color();
uint8_t read_Color();


//#define Color_ADD 0x54


    char moji[] = "Hello, PIC World";
    char moji2[] = "Wak-tech";
    extern uint16_t c[4]={};

/*
                         Main application
 */



void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
     LATBbits.LATB7 = 0;
    InitI2C_Master(0);
    LCD_Init_ST7032i(0,50,1,16);
     LATBbits.LATB7 = 1;
    char buf[16];
    while(1){
        LATBbits.LATB7 = ~LATBbits.LATB7;
        LCD_Clear() ;
        __delay_ms(100);
        LCD_SetCursor(0,0); //2—ñ–Ú‚ÖˆÚ“®
        __delay_ms(100);
        LCD_Puts(moji);
        __delay_ms(1000);
        LCD_SetCursor(0,1); //2—ñ–Ú‚ÖˆÚ“®
        __delay_ms(40);
        LCD_Puts(moji2);
        __delay_ms(1000);
        LCD_Command(0x01); //‰æ–Ê‚ðƒNƒŠƒA
        __delay_ms(200);
        
        Color();
        
        while(1){
            Color_Read();
            if(c[0]>=0x0300){
                IO_RB7_SetHigh();
                IO_RC7_SetLow();
            }
            else if(c[2]>=0x0300){
                IO_RC7_SetHigh();
                IO_RB7_SetLow();
            }
            else{
                IO_RB7_SetLow();
                IO_RC7_SetLow();
            }
        }
        
      }
}
/**
 End of File
*/