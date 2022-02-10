if (USE_SMART_BUILD)
#ifneq ($(findstring HAL_USE_DAC TRUE,$(HALCONF)),)
#list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/DACv1/hal_dac_lld.c
#endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/DACv1/hal_dac_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/DACv1)
