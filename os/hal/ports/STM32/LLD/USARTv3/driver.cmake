if (USE_SMART_BUILD)
#    ifneq ($(findstring HAL_USE_SERIAL TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3/hal_serial_lld.c
#    endif()
#    ifneq ($(findstring HAL_USE_SIO TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3/hal_sio_lld.c
#    endif()
#    ifneq ($(findstring HAL_USE_UART TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3/hal_uart_lld.c
#    endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3/hal_serial_lld.c)
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3/hal_sio_lld.c)
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3/hal_uart_lld.c)
endif()

list(APPEND PLATFORMINC
        ${CHIBIOS}/os/hal/ports/STM32/LLD/USART
        ${CHIBIOS}/os/hal/ports/STM32/LLD/USARTv3)
