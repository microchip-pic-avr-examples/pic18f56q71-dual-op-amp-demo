 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
 */

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
 */
#include "mcc_generated_files/system/system.h"

#include "application.h"

#define clrscr() printf("\e[1;1H\e[2J")

/*
                         Main application
 */

void main(void) {
    // Initialize the device
    SYSTEM_Initialize();
  

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    clrscr();

    IntroSplashMessage();

    GetOpamp1Config();
    GetOpamp2Config();

    while (1) {
        if (sw0_GetValue() == 0) {


            while (1) {
                if (sw0_GetValue() == 0) {


                    GetOpamp1Config();
                    GetOpamp2Config();
                    init_flag = 0;

                }

                switch (opa1_config) {
                    case EXTERNAL1:
                        if (init_flag == 0) {
                            Blink1LED(opa1_config);
                            OPA1_DC();
                            init_flag = 1;
                            Stage_flag = 1;
                        }



                    case UNITY_GAIN1:
                        if (init_flag == 0) {
                            Blink1LED(opa1_config);
                            OPA1_Unity();
                            init_flag = 1;
                            Stage_flag = 1;
                        }


                    case NON_INVERTING1:
                        if (init_flag == 0) {
                            Blink1LED(opa1_config);
                            OPA1_NonInvert();
                            init_flag = 1;
                            Stage_flag = 1;
                        }



                    case INVERTING1:
                        if (init_flag == 0) {
                            Blink1LED(opa1_config);
                            OPA1_Invert();
                            init_flag = 1;
                            Stage_flag = 1;
                        }

                }

                switch (opa2_config) {
                    case EXTERNAL2:
                        if (Stage_flag == 1) {
                            Blink2LED(opa2_config);
                            OPA2_DC();
                            Stage_flag = 0;
                        }
                        //SLEEP();
                        break;

                    case UNITY_GAIN2:
                        if (Stage_flag == 1) {
                            Blink2LED(opa2_config);
                            OPA2_Unity();
                            Stage_flag = 0;
                        }
                        //SLEEP();
                        break;

                    case NON_INVERTING2:
                        if (Stage_flag == 1) {
                            Blink2LED(opa2_config);
                            OPA2_NonInvert();
                            Stage_flag = 0;
                        }

                        //SLEEP();
                        break;

                    case INVERTING2:
                        if (Stage_flag == 1) {
                            Blink2LED(opa2_config);
                            OPA2_Invert();
                            Stage_flag = 0;
                        }
                        //SLEEP();
                        break;

                    default:
                        printf("OPA2 Configuration Input Error! \r\n");
                        break;
                }
            }

        } else {
            NOP();
        }
    }
}