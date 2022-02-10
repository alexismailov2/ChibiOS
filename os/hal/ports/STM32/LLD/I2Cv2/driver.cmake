if (USE_HAL_I2C_FALLBACK)
    # Fallback SW driver.
    if (USE_SMART_BUILD)
        #ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
        #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/lib/fallback/I2C/hal_i2c_lld.c
        #endif()
    else()
        list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/lib/fallback/I2C/hal_i2c_lld.c)
    endif()

    list(APPEND PLATFORMINC  ${CHIBIOS}/os/hal/lib/fallback/I2C)
else()
    # Default HW driver.
    if (USE_SMART_BUILD)
        #ifneq ($(findstring HAL_USE_I2C TRUE,$(HALCONF)),)
        #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/I2Cv2/hal_i2c_lld.c
        #endif()
    else()
        list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/I2Cv2/hal_i2c_lld.c)
    endif()
    list(APPEND PLATFORMINC  ${CHIBIOS}/os/hal/ports/STM32/LLD/I2Cv2)
endif()
