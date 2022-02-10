# List of the ChibiOS generic STM32F4xx startup and CMSIS files.
set(STARTUPSRC
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/crt1.c)

file(GLOB PAC55XX_DRIVERS ${CHIBIOS}/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/*.c)

set(STARTUPASM
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/crt0_v7m.S
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/vectors.S)

set(STARTUPINC
        ${CHIBIOS}/os/common/portability/GCC
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC
        ${CHIBIOS}/os/common/startup/ARMCMx/devices/PAC55xx
        ${CHIBIOS}/os/common/ext/ARM/CMSIS/Core/Include
        ${CHIBIOS}/os/common/ext/PAC/PAC55xx)

set(STARTUPLD
        ${CHIBIOS}/os/common/startup/ARMCMx/compilers/GCC/ld)

# Shared variables
list(APPEND ALLXASMSRC ${STARTUPASM})
list(APPEND ALLCSRC ${STARTUPSRC} ${PAC55XX_DRIVERS})
list(APPEND ALLINC ${STARTUPINC})
