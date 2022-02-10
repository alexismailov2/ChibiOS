if (USE_SMART_BUILD)
    #ifneq ($(findstring HAL_USE_MAC TRUE,$(HALCONF)),)
    #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/MACv1/hal_mac_lld.c)
    #endif()
else()
    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/MACv1/hal_mac_lld.c)
endif()

list(APPEND PLATFORMINC  ${CHIBIOS}/os/hal/ports/STM32/LLD/MACv1)
