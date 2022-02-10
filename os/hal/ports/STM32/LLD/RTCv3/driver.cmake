if (USE_SMART_BUILD)
    #ifneq ($(findstring HAL_USE_RTC TRUE,$(HALCONF)),)
    #list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/RTCv3/hal_rtc_lld.c
    #endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/RTCv3/hal_rtc_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/RTCv3)
