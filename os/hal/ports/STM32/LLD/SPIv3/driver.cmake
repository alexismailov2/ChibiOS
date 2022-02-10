if (USE_SMART_BUILD)
#    ifneq ($(findstring HAL_USE_SPI TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/SPIv3/hal_spi_lld.c
#    endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/SPIv3/hal_spi_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/SPIv3)
