if (USE_SMART_BUILD)
#ifneq ($(findstring HAL_USE_ADC TRUE,$(HALCONF)),)
#list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/ADCv2/hal_adc_lld.c
#endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/ADCv2/hal_adc_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/ADCv2)
