if(USE_SMART_BUILD)
#    ifneq ($(findstring HAL_USE_WDG TRUE,$(HALCONF)),)
#        list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/xWDGv1/hal_wdg_lld.c
#    endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/STM32/LLD/xWDGv1/hal_wdg_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/STM32/LLD/xWDGv1)