# List of the ChibiOS generic STM32F4xx startup and CMSIS files.
set(STARTUPSRC
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/crt1.c)

set(STARTUPASM
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/crt0_v7m.S
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/vectors.S)

set(STARTUPINC
        ${CHIBIOS}/os/common/portability/GCC
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC
        ${CHIBIOS}/os/common/startup/ARMCMx/devices/STM32F4xx
        ${CHIBIOS}/os/common/ext/ARM/CMSIS/Core/Include
        ${CHIBIOS}/os/common/ext/ST/STM32F4xx)

set(STARTUPLD
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/ld)

# Shared variables
list(APPEND ALLXASMSRC ${STARTUPASM})
list(APPEND ALLCSRC ${STARTUPSRC})
list(APPEND ALLINC ${STARTUPINC})
