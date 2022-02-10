# List of all the board related files.
set(BOARDSRC ${CHIBIOS}/os/hal/boards/PAC5532EVK1/board.c)

# Required include directories
set(BOARDINC ${CHIBIOS}/os/hal/boards/PAC5532EVK1)

# Shared variables
list(APPEND ALLCSRC ${BOARDSRC})
list(APPEND ALLINC ${BOARDINC})
