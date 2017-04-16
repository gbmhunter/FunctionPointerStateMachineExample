
#include <stdio.h>
#include <stdbool.h>

#include "StateMachine.h"

bool buttonPushed = false;

int main() {
    printf("main() called.\r\n");

    stateMachine_t stateMachine;

    StateMachine_Init(&stateMachine);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Run first iteration
    StateMachine_Run(&stateMachine);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    // Let's pretend a button was pushed
    buttonPushed = true;
    printf("Button pushed.\r\n");
    StateMachine_Run(&stateMachine);
    printf("State is now %s.\r\n", StateMachine_GetStateName(stateMachine.currState));

    return 0;
}