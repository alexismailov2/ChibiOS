# List of the ChibiOS/RT ARMv7M generic port files.
set(PORTSRC ${CHIBIOS}/os/common/ports/ARMv7-M/chcore.c)

set(PORTASM ${CHIBIOS}/os/common/ports/ARMv7-M/compilers/GCC/chcoreasm.S)

set(PORTINC
    ${CHIBIOS}/os/common/portability/GCC
    ${CHIBIOS}/os/common/ports/ARM-common
    ${CHIBIOS}/os/common/ports/ARMv7-M)

# Shared variables
list(APPEND ALLXASMSRC ${PORTASM})
list(APPEND ALLCSRC ${PORTSRC})
list(APPEND ALLINC ${PORTINC})
