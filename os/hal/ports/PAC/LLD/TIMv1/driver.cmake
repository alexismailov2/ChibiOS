if (USE_SMART_BUILD)
#    ifneq ($(findstring HAL_USE_GPT TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/TIMv1/hal_gpt_lld.c
#    endif()
#    ifneq ($(findstring HAL_USE_ICU TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/TIMv1/hal_icu_lld.c
#    endif()
#    ifneq ($(findstring HAL_USE_PWM TRUE,$(HALCONF)),)
#    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/STM32/LLD/TIMv1/hal_pwm_lld.c
#    endif()
else()
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/PAC/LLD/TIMv1/hal_gpt_lld.c)
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/PAC/LLD/TIMv1/hal_icu_lld.c)
    list(APPEND PLATFORMSRC ${CHIBIOS}/os/hal/ports/PAC/LLD/TIMv1/hal_pwm_lld.c)
endif()

list(APPEND PLATFORMINC ${CHIBIOS}/os/hal/ports/PAC/LLD/TIMv1)
