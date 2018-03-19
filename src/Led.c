///
/// \file 				Led.c
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-04-15
/// \last-modified		2018-03-19
/// \brief 				Contains the Led module.
/// \details
///		See README.md in root dir for more info.

#include <stdio.h>

void Led_Init() {
    printf("Led_Init() called.\r\n");
}

void Led_On() {
    printf("LED turned on.\r\n");
}

void Led_Off() {
    printf("LED turned off.\r\n");
}

void Led_Idle() {
    printf("LED in idle state.\r\n");
}