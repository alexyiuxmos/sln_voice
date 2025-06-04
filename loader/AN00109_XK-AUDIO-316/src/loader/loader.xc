// Copyright (c) 2016, XMOS Ltd, All rights reserved
#include <xs1.h>
#include <platform.h>

//port SPI_MOSI  =   XS1_PORT_1D;  // e.g., XS1_PORT_1D
//port  SPI_MISO =   XS1_PORT_1A;  // e.g., XS1_PORT_1A
//port SPI_CLK =    XS1_PORT_1C;    // e.g., XS1_PORT_1C
//port SPI_SS   =   XS1_PORT_1B;     // e.g., XS1_PORT_1B


#if 0
#if defined(__XS2A__)
/* Note range 0x7FFC8 - 0x7FFFF guarenteed to be untouched by tools */
#warning Building xCORE-200 compatible loader
#define FLAG_ADDRESS 0x7ffcc
#else
/* Note range 0xFFFC8 - 0xFFFFF guarenteed to be untouched by tools */
#warning Building xcore.ai compatible loader
#define FLAG_ADDRESS 0xfffcc
#endif

/* Store Flag to fixed address */
void SetRoleSwitchFlag(unsigned x)
{
    asm volatile("stw %0, %1[0]" :: "r"(x), "r"(FLAG_ADDRESS));
}

/* Load flag from fixed address */
unsigned GetRoleSwitchFlag()
{
    unsigned x;
    asm volatile("ldw %0, %1[0]" : "=r"(x) : "r"(FLAG_ADDRESS));
    return x;
}


void delay_cycles(int count) {
    for (int i = 0; i < count; i++) {
        asm volatile (""); // Prevent compiler removal.
    }
}
#endif
/* Port for button on xk-audio-316 board. */
in port p_button = XS1_PORT_8A; //XS1_PORT_8D;//XS1_PORT_4E;
out port p_leds = XS1_PORT_4E;

/* Enum for representing button state. */
enum button_val
{
    BUTTON_UP,
    BUTTON_DOWN
};
/* Store the button position. */
int buttonPosition;
/* Enum for representing the potential interest in the image. */
enum interest
{
    NOT_INTERESTED = 0,
    INTERESTED = 1
};

/* Store the version of the image in memory that will potentially be booted. */
int candidateImageVersion = -1;
/* Store the address of the image in memory that will potentially be booted. */
unsigned candidateImageAddress;
void init(void)
{

    p_leds <: 0x0;
    delay_milliseconds(10);
    unsigned int buttonVal;

    /* Read state of button */
//    p_button :> buttonVal;
    p_button :> void;
    delay_milliseconds(1);
    p_button :> buttonVal;
    //buttonVal = buttonVal >> 2;
//    delay_milliseconds(1);
//    p_button :> buttonVal;
    
    /* Button is up. */
    //if ((buttonVal & 4) == 4) {
    if (buttonVal > 0) {
        buttonPosition = BUTTON_UP;
        p_leds <: 0x8;
    }
    /* Button is down. */
    else {
        buttonPosition = BUTTON_DOWN;
        p_leds <: 0x4;
    }
    delay_milliseconds(10);

}
int checkCandidateImageVersion(int imageVersion)
{
/* If the button is up and imageVersion is even and imageVersion is higher */
/* than the last candidateImageVersion then this is a potential version */
/* for booting. */
    if ((buttonPosition == BUTTON_UP) && ((imageVersion % 2) == 0) /*&& (imageVersion > candidateImageVersion)*/) {
        return INTERESTED;
    } 
/* If the button is down and imageVersion is odd and imageVersion is higher */
/* than the last candidateImageVersion then this is a potential version */
/* for booting. */
    else if ((buttonPosition == BUTTON_DOWN) && ((imageVersion % 2) != 0) /*&& (imageVersion > candidateImageVersion)*/) {
        return INTERESTED;
    }
/* Not a potential firmware image in all other cases. */
    return NOT_INTERESTED;
}
void recordCandidateImage(int imageVersion, unsigned imageAddress)
{
/* Save the imageVersion that we are interested in. */
    candidateImageVersion = imageVersion;
/* Save the imageAddress of the imageVersion that we are interested in. */
    candidateImageAddress = imageAddress;
}
unsigned reportSelectedImage(void)
{
/* Return the candidateImageAddress of the image that we are interested in. */
    return candidateImageAddress;
}

