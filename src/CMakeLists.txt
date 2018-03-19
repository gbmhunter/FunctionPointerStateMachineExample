
set(HEADER_FILES
        main.h
        Led.h
        StateMachine.h)

set(SOURCE_FILES
        main.c
        Led.c
        StateMachine.c)

add_executable(FunctionPointerStateMachineExample ${SOURCE_FILES} ${HEADER_FILES})