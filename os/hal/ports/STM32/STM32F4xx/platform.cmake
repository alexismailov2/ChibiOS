# Required platform files.
set(PLATFORMSRC
        ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c
        ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx/stm32_isr.c
        ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx/hal_lld.c
        ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx/hal_efl_lld.c)

# Required include directories.
set(PLATFORMINC
        ${CHIBIOS}/os/hal/ports/common/ARMCMx
        ${CHIBIOS}/os/hal/ports/STM32/STM32F4xx)

# Optional platform files.
if(USE_SMART_BUILD)
#    # Configuration files directory
#    if ($(HALCONFDIR),)
#        if ($(CONFDIR),)
#            HALCONFDIR = .
#        else()
#            HALCONFDIR := $(CONFDIR)
#        endif()
#    endif()
#    HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))
else()
endif()

if(0)
# Drivers compatible with the platform.
include(${CHIBIOS}/os/hal/ports/STM32/LLD/ADCv2/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/CANv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/CRYPv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/DACv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/DMAv2/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/EXTIv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/GPIOv2/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/I2Cv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/MACv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/OTGv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/QUADSPIv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/RTCv2/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/SPIv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/SDIOv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/SYSTICKv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/TIMv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv1/driver.cmake)
include(${CHIBIOS}/os/hal/ports/STM32/LLD/xWDGv1/driver.cmake)
else()
set(LLD_STM32F4xx_LIST
        ${CHIBIOS}/os/hal/ports/STM32/LLD/ADCv2
        ${CHIBIOS}/os/hal/ports/STM32/LLD/CANv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/CRYPv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/DACv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/DMAv2
        ${CHIBIOS}/os/hal/ports/STM32/LLD/EXTIv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/GPIOv2
        ${CHIBIOS}/os/hal/ports/STM32/LLD/I2Cv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/MACv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/OTGv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/QUADSPIv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/RTCv2
        ${CHIBIOS}/os/hal/ports/STM32/LLD/SPIv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/SDIOv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/SYSTICKv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/TIMv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/xWDGv1
        ${CHIBIOS}/os/hal/ports/STM32/LLD/USART)

foreach(LLD_ITEM IN LISTS LLD_STM32F4xx_LIST)
message(STATUS "LLD_ITEM=${LLD_ITEM}")
file(GLOB LLD_ITEM_SRC ${LLD_ITEM}/*.c)
list(APPEND PLATFORMSRC ${LLD_ITEM_SRC})
endforeach()

endif()

# Shared variables
list(APPEND ALLCSRC ${PLATFORMSRC})
list(APPEND ALLINC ${PLATFORMINC} ${LLD_STM32F4xx_LIST})
