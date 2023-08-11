#include <xc.h>
#include "application.h"
#include "mcc_generated_files/system/system.h"

void IntroSplashMessage(void) {
    printf("PIC18F56Q71 Curiosity Nano OPA Click Demo \r\n");
    printf("Select OPA mode of operation using pins for 1:RC6 & RC1, 2:RC3 & RC4\r\n");
    printf("Press SW0 after selecting mode of operation to reconfigure OPA module. \r\n");
    printf("Please refer to included readme.md for more information. \r\n");
    printf("-------------------------------------------------------------------\r\n");
}


void GetOpamp1Config(void) {
    opa1_config = ((PORTCbits.RC6 << 1)+(PORTCbits.RC1)) + 1;
}

void GetOpamp2Config(void) {
    opa2_config = ((PORTCbits.RC3 << 1)+(PORTCbits.RC4)) + 1;
}

void Blink1LED(int8_t cnt) {
    for (int i = cnt; i > 0; i--) {
        LATCbits.LATC5 = 0;
        __delay_ms(250);
        LATCbits.LATC5 = 1;
        __delay_ms(250);
    }
}

void Blink2LED(int8_t cnt) {
    for (int i = cnt; i > 0; i--) {
        LATCbits.LATC2 = 0;
        __delay_ms(250);
        LATCbits.LATC2 = 1;
        __delay_ms(250);
    }
}

void OPA1_DC(void)
{   
    printf("\e[1;1H\e[2J");
    printf("OPA1 Configuration: Direct Connection to External Pins \r\n");
    printf("OPA1OUT = RA1 | OPA1IN+ = RA5 | OPA1IN- = RA2 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;
    
    OPA1CON1 = 0x0;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA1IN0-; 
    
    OPA1CON2 = 0x22;//NCH OPA1IN-; PCH OPA1IN+; 
    
    OPA1CON3 = 0x2;//FMS No Connection; INTOE Disabled; PSS OPA1IN2+; 
    
    OPA1CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA1HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA1ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA1CON0 = 0x80;//EN Enabled; CPON Disabled; UG OPAIN- pin; 
    
}

void OPA1_Unity(void)
{
    printf("\e[1;1H\e[2J");
    printf("OPA Configuration: Unity Gain Buffer \r\n");
    printf("OPA1OUT = RA1 | OPA1IN+ = RA5 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;
    
    OPA1CON1 = 0x0;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA1IN0-; 
    
    OPA1CON2 = 0x2;//NCH No Connection; PCH OPA1IN+; 
    
    OPA1CON3 = 0x2;//FMS No Connection; INTOE Disabled; PSS OPA1IN2+; 
    
    OPA1CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA1HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA1ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA1CON0 = 0x88;//EN Enabled; CPON Disabled; UG OPA Output; 
    
}

void OPA1_NonInvert(void)
{
    printf("\e[1;1H\e[2J");
    printf("OPA Configuration: Non-Inverting Programmable Gain Amplifier \r\n");
    printf("OPA1OUT = RA1 | OPA1IN+ = RA5 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;

    OPA1CON1 = 0x5F;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Enabled; NSS Vss; 
   
    OPA1CON2 = 0x12;//NCH GSEL; PCH OPA1IN+; 
    
    OPA1CON3 = 0x82;//FMS OPA1OUT; INTOE Disabled; PSS OPA1IN2+; 
    
    OPA1CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA1HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA1ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA1CON0 = 0x80;//EN Enabled; CPON Disabled; UG OPAIN- pin; 
    
}

void OPA1_Invert(void)
{
    printf("\e[1;1H\e[2J");
    printf("OPA Configuration: Inverting Programmable Gain Amplifier \r\n");
    printf("OPA1OUT = RA1 | OPA1IN- = RA2 \r\n\r\n");
    OPA1CON0bits.EN = 0; // Disable OPA Module;

    OPA1CON1 = 0x58;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Enabled; NSS OPA1IN0-; 
    
    OPA1CON2 = 0x13;//NCH GSEL; PCH Vdd/2; 
    
    OPA1CON3 = 0x80;//FMS OPA1OUT; INTOE Disabled; PSS OPA1IN0+; 
    
    OPA1CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
   
    OPA1HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA1ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA1CON0 = 0x80;//EN Enabled; CPON Disabled; UG OPAIN- pin; 
    
}

void OPA2_DC(void)
{
    printf("OPA2 Configuration: Direct Connection to External Pins \r\n");
    printf("OPA2OUT = RB1 | OPA2IN+ = RB2 | OPA2IN- = RB3 \r\n\r\n");
    OPA2CON0bits.EN = 0; // Disable OPA Module;


    OPA2CON1 = 0x2;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA2IN3-; 
    
    OPA2CON2 = 0x22;//NCH OPA2IN-; PCH OPA2IN+; 
    
    OPA2CON3 = 0x3;//FMS No Connection; INTOE Disabled; PSS OPA2IN2+; 
    
    OPA2CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA2HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA2ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA2CON0 = 0x80;//EN Enabled; CPON Disabled; UG OPAIN- pin; 
}

void OPA2_Unity(void)
{
    printf("OPA2 Configuration: Unity Gain Buffer \r\n");
    printf("OPA2OUT = RB1 | OPA2IN+ = RB2 \r\n\r\n");
    OPA2CON0bits.EN = 0; // Disable OPA Module;

    OPA2CON1 = 0x0;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Disabled; NSS OPA2IN0-; 
    
    OPA2CON2 = 0x2;//NCH No Connection; PCH OPA2IN+; 
    
    OPA2CON3 = 0x3;//FMS No Connection; INTOE Disabled; PSS OPA2IN2+; 
    
    OPA2CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA2HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA2ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA2CON0 = 0x88;//EN Enabled; CPON Disabled; UG OPA Output; 
}

void OPA2_NonInvert(void)
{
    printf("OPA2 Configuration: Non-Inverting Programmable Gain Amplifier \r\n");
    printf("OPA2OUT = RB1 | OPA2IN+ = RB2 \r\n\r\n");
    OPA2CON0bits.EN = 0; // Disable OPA Module;

    OPA2CON1 = 0x5F;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Enabled; NSS Vss; 
    
    OPA2CON2 = 0x12;//NCH GSEL; PCH OPA2IN+; 
    
    OPA2CON3 = 0x83;//FMS OPA2OUT; INTOE Disabled; PSS OPA2IN2+; 
    
    OPA2CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA2HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA2ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA2CON0 = 0x80;//EN Enabled; CPON Disabled; UG OPAIN- pin; 
}

void OPA2_Invert(void)
{
    printf("OPA2 Configuration: Inverting Programmable Gain Amplifier \r\n");
    printf("OPA2OUT = RB1 | OPA2IN- = RB3 \r\n\r\n");
    OPA2CON0bits.EN = 0; // Disable OPA Module;

    OPA2CON1 = 0x5A;//GSEL R1 = 15R and R2 = 1R, R2/R1 = 0.07; RESON Enabled; NSS OPA2IN3-; 
   
    OPA2CON2 = 0x13;//NCH GSEL; PCH Vdd/2; 
   
    OPA2CON3 = 0x80;//FMS OPA2OUT; INTOE Disabled; PSS OPA2IN0+; 
    
    OPA2CON4 = 0x0;//PTRES No reset; OFCST Calibration complete; OFCSEL Factory calibrated value in OPAxOFFSET; 
    
    OPA2HWC = 0x0;//OREN Disabled; HWCH Basic OPA configuration with user defined feedback; ORPOL Non Inverted; HWCL Basic OPA configuration with user defined feedback; 
    
    OPA2ORS = 0x0;//ORS OPAxORPPS; 
    
    OPA2CON0 = 0x80;//EN Enabled; CPON Disabled; UG OPAIN- pin; 
}

