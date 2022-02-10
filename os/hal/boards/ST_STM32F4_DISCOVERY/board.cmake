# List of all the board related files.
set(BOARDSRC ${CHIBIOS}/os/hal/boards/ST_STM32F4_DISCOVERY/board.c)

# Required include directories
set(BOARDINC ${CHIBIOS}/os/hal/boards/ST_STM32F4_DISCOVERY)

# Shared variables
list(APPEND ALLCSRC ${BOARDSRC})
list(APPEND ALLINC ${BOARDINC})
