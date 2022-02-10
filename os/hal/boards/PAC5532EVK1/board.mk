# List of all the board related files.
BOARDSRC = $(CHIBIOS)/os/hal/boards/PAC5532EVK1/board.c

# Required include directories
BOARDINC = $(CHIBIOS)/os/hal/boards/PAC5532EVK1

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
