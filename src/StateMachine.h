#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

typedef enum {
    ST_INIT,
    ST_IDLE,
    ST_LED_ON,
    ST_LED_OFF
} state_t;

typedef struct {
    state_t currState;
} stateMachine_t;

void StateMachine_Init(stateMachine_t * stateMachine);
void StateMachine_RunIteration(stateMachine_t *stateMachine);
const char * StateMachine_GetStateName(state_t state);

#endif