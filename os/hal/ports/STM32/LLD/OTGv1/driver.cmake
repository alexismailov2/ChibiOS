if (USE_SMART_BUILD)
    #ifneq ($(findstring HAL_USE_USB TRUE,$(HALCONF)),)
    #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/OTGv1/hal_usb_lld.c)
    #endif()
else()
    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/OTGv1/hal_usb_lld.c)
endif()

list(APPEND PLATFORMINC  ${CHIBIOS}/os/hal/ports/STM32/LLD/OTGv1)
