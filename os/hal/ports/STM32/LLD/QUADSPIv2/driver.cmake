if (USE_SMART_BUILD)
    #ifneq ($(findstring HAL_USE_WSPI TRUE,$(HALCONF)),)
    #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/QUADSPIv2/hal_wspi_lld.c
    #endif()
else()
    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/QUADSPIv2/hal_wspi_lld.c)
endif()

list(APPEND PLATFORMINC  ${CHIBIOS}/os/hal/ports/STM32/LLD/QUADSPIv2)
