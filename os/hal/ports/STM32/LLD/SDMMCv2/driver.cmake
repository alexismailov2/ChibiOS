if (USE_SMART_BUILD)
    #ifneq ($(findstring HAL_USE_SDC TRUE,$(HALCONF)),)
    #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/SDMMCv2/hal_sdc_lld.c
    #endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/SDMMCv2/hal_sdc_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/SDMMCv2)
