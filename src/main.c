///
/// \file 				main.c
/// \author 			Geoffrey Hunter (www.mbedded.ninja) <gbmhunter@gmail.com>
/// \edited             n/a
/// \created			2017-04-15
/// \last-modified		2018-03-19
/// \brief 				Contains the main entry point to the state machine example.
/// \details
///		See README.md in root dir for more info.

#include <stdio.h>
#include <stdbool.h>

#include "StateMachine.h"

int main() {
    printf("main() called.\r\n");

    // Create new state machine object
    stateMachine_t stateMachine;

    StateMachine_Init(&stateMachine);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Push button to start flasher
    printf("Button pushed.\r\n");
    StateMachine_RunIteration(&stateMachine, EV_BUTTON_PUSHED);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Timeout
    printf("Timeout.\r\n");
    StateMachine_RunIteration(&stateMachine, EV_TIME_OUT);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Timeout
    printf("Timeout.\r\n");
    StateMachine_RunIteration(&stateMachine, EV_TIME_OUT);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Timeout
    printf("Timeout.\r\n");
    StateMachine_RunIteration(&stateMachine, EV_TIME_OUT);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Push button again to stop flasher
    printf("Button pushed.\r\n");
    StateMachine_RunIteration(&stateMachine, EV_BUTTON_PUSHED);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    return 0;
}