if (USE_SMART_BUILD)
#ifneq ($(findstring HAL_USE_CRY TRUE,$(HALCONF)),)
#list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/CRYPv1/hal_crypto_lld.c
#endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/CRYPv1/hal_crypto_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/CRYPv1)