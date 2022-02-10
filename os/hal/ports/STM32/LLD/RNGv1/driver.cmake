if (USE_SMART_BUILD)
    #ifneq ($(findstring HAL_USE_TRNG TRUE,$(HALCONF)),)
    #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/RNGv1/hal_trng_lld.c
    #endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/RNGv1/hal_trng_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/RNGv1)
