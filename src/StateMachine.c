#include <stdio.h>

#include "StateMachine.h"

#include "Main.h"
#include "Led.h"


typedef struct {
    const char * name;
    void (*func)(void);
} stateFunctionRow_t;

/// @brief  Maps a state to it's state transition function, which should be called
///         when the state transitions into this state.
/// @warning    This has to stay in sync with the state_t enum!
static stateFunctionRow_t stateFunctionA[] = {
    { "ST_INIT",      &Led_Init },      // ST_INIT
    { "ST_IDLE",      &Led_Idle },      // ST_IDLE
    { "ST_LED_ON",    &Led_On },        // ST_LED_ON
    { "ST_LED_OFF",   &Led_Off },       // ST_LED_OFF
};


typedef enum {
    EV_ANY,
    EV_BUTTON_PUSHED,
    EV_TIME_OUT,
    EV_NONE
} event_t;

typedef struct {
    state_t currState;
    event_t event;
    state_t nextState;
} stateTransMatrixRow_t;

static stateTransMatrixRow_t stateTransMatrix[] = {
    //  CURR STATE // EVENT           // NEXT STATE
    { ST_INIT,     EV_ANY,               ST_IDLE    },
    { ST_IDLE,     EV_BUTTON_PUSHED,     ST_LED_ON  },
    { ST_LED_ON,   EV_TIME_OUT,          ST_LED_OFF },
    { ST_LED_ON,   EV_BUTTON_PUSHED,     ST_IDLE    },
    { ST_LED_OFF,  EV_TIME_OUT,          ST_LED_ON  },
    { ST_LED_OFF,  EV_BUTTON_PUSHED,     ST_IDLE    }
};

event_t event;

void StateMachine_Init(stateMachine_t * stateMachine) {
    printf("Initialising state machine.\r\n");
    stateMachine->currState = ST_INIT;
}

event_t StateMachine_GetEvent() {
    printf("StateMachine_GetEvent() called.\r\n");

    if(buttonPushed)
        return EV_BUTTON_PUSHED;

    // No event
    return EV_NONE;
}

void StateMachine_Run(stateMachine_t * stateMachine) {
    // Run the main state machine (handles everything else)
    event = StateMachine_GetEvent();

    for(int i = 0; i < sizeof(stateTransMatrix)/sizeof(stateTransMatrix[0]); i++) {
        if(stateTransMatrix[i].currState == stateMachine->currState) {
            if((stateTransMatrix[i].event == event) || (stateTransMatrix[i].event == EV_ANY)) {

                // Transition to the next state
                stateMachine->currState =  stateTransMatrix[i].nextState;

                // Call the function associated with transition
                (stateFunctionA[stateMachine->currState].func)();
                break;
            }
        }
    }
}

const char * StateMachine_GetStateName(state_t state) {
    return stateFunctionA[state].name;
}