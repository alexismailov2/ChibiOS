# List of the ChibiOS generic pac55xx startup and CMSIS files.
STARTUPSRC = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt1.c

PAC55XX_DRIVERS = $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_adc.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_can.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_gpio.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_socbridge.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_system.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_tile_socbridge.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_timer.c \
                  $(CHIBIOS)/os/common/ext/PAC/PAC55xx/pac55xx_sdk/driver/pac5xxx_driver_uart.c

STARTUPASM = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/crt0_v7m.S \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/vectors.S

STARTUPINC = $(CHIBIOS)/os/common/portability/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC \
             $(CHIBIOS)/os/common/startup/ARMCMx/devices/PAC55xx \
             $(CHIBIOS)/os/common/ext/ARM/CMSIS/Core/Include \
             $(CHIBIOS)/os/common/ext/PAC/PAC55xx

STARTUPLD  = $(CHIBIOS)/os/common/startup/ARMCMx/compilers/GCC/ld

# Shared variables
ALLXASMSRC += $(STARTUPASM)
ALLCSRC    += $(STARTUPSRC) $(PAC55XX_DRIVERS)
ALLINC     += $(STARTUPINC)