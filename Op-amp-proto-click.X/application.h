/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once. 


#ifndef APPLICATION_H
#define	APPLICATION_H
#include <xc.h> 
#ifdef	__cplusplus
extern "C" {
#endif



    int init_flag = 0;
    int Stage_flag = 0;
    
    
    enum opa1_mode {
        EXTERNAL1 = 1,
        UNITY_GAIN1 = 2,
        NON_INVERTING1 = 3,
        INVERTING1 = 4
    } opa1_config;

    enum opa2_mode {
        EXTERNAL2 = 1,
        UNITY_GAIN2 = 2,
        NON_INVERTING2 = 3,
        INVERTING2 = 4
    } opa2_config;

    void IntroSplashMessage(void);
    void GetOpamp2Config(void);
    void GetOpamp1Config(void);
    void Blink1LED(int8_t cnt);
    void Blink2LED(int8_t cnt);
    void OPA1_DC(void);
    void OPA1_Unity(void);
    void OPA1_NonInvert(void);
    void OPA1_Invert(void);
    void OPA2_DC(void);
    void OPA2_Unity(void);
    void OPA2_NonInvert(void);
    void OPA2_Invert(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */
