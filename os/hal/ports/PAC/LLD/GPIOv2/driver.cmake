if (USE_SMART_BUILD)
#ifneq ($(findstring HAL_USE_PAL TRUE,$(HALCONF)),)
#list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/PAC/LLD/GPIOv2/hal_pal_lld.c
#endif()
else()
    list(APPEND PLATFORMSRC  ${CHIBIOS}/os/hal/ports/PAC/LLD/GPIOv2/hal_pal_lld.c)
endif()

list(APPEND PLATFORMINC  ${CHIBIOS}/os/hal/ports/PAC/LLD/GPIOv2)