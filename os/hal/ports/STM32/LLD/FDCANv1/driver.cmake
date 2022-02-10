if (USE_SMART_BUILD)
#ifneq ($(findstring HAL_USE_CAN TRUE,$(HALCONF)),)
#list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/FDCANv1/hal_can_lld.c
#endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/FDCANv1/hal_can_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/FDCANv1)