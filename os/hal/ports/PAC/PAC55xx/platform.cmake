# Required platform files.
set(PLATFORMSRC
        ${CHIBIOS}/os/hal/ports/common/ARMCMx/nvic.c
        #${CHIBIOS}/os/hal/ports/PAC/PAC55xx/pac_isr.c
        ${CHIBIOS}/os/hal/ports/PAC/PAC55xx/hal_lld.c
        #${CHIBIOS}/os/hal/ports/PAC/PAC55xx/hal_efl_lld.c
        )

# Required include directories.
set(PLATFORMINC
        ${CHIBIOS}/os/hal/ports/common/ARMCMx
        ${CHIBIOS}/os/hal/ports/PAC/PAC55xx)

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

if (0)
    # Drivers compatible with the platform.
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/ADCv2/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/CANv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/CRYPv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/DACv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/DMAv2/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/EXTIv1/driver.cmake)
    include(${CHIBIOS}/os/hal/ports/PAC/LLD/GPIOv2/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/I2Cv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/MACv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/OTGv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/QUADSPIv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/RTCv2/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/SPIv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/SDIOv1/driver.cmake)
    include(${CHIBIOS}/os/hal/ports/PAC/LLD/SYSTICKv1/driver.cmake)
    include(${CHIBIOS}/os/hal/ports/PAC/LLD/TIMv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/USARTv1/driver.cmake)
    #include(${CHIBIOS}/os/hal/ports/PAC/LLD/xWDGv1/driver.cmake)
else()
    set(LLD_PAC55xx_LIST
            ${CHIBIOS}/os/hal/ports/PAC/LLD/GPIOv2
            ${CHIBIOS}/os/hal/ports/PAC/LLD/SYSTICKv1
            ${CHIBIOS}/os/hal/ports/PAC/LLD/TIMv1)

    foreach(LLD_ITEM IN LISTS LLD_PAC55xx_LIST)
        message(STATUS "LLD_ITEM=${LLD_ITEM}")
        file(GLOB LLD_ITEM_SRC ${LLD_ITEM}/*.c)
        list(APPEND PLATFORMSRC ${LLD_ITEM_SRC})
    endforeach()
endif()

# Shared variables
list(APPEND ALLCSRC ${PLATFORMSRC})
list(APPEND ALLINC ${PLATFORMINC} ${LLD_PAC55xx_LIST})
