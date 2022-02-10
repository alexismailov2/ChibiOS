# Required platform files.
PLATFORMSRC := $(CHIBIOS)/os/hal/ports/common/ARMCMx/nvic.c \
               $(CHIBIOS)/os/hal/ports/PAC/PAC55xx/hal_lld.c  \
               $(CHIBIOS)/os/hal/ports/PAC/PAC55xx/hal_efl_lld.c

# Required include directories.
PLATFORMINC := $(CHIBIOS)/os/hal/ports/common/ARMCMx \
               $(CHIBIOS)/os/hal/ports/PAC/PAC55xx

# Optional platform files.
ifeq ($(USE_SMART_BUILD),yes)

# Configuration files directory
ifeq ($(HALCONFDIR),)
  ifeq ($(CONFDIR),)
    HALCONFDIR = .
  else
    HALCONFDIR := $(CONFDIR)
  endif
endif

HALCONF := $(strip $(shell cat $(HALCONFDIR)/halconf.h | egrep -e "\#define"))

else
endif

# Drivers compatible with the platform.
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/ADCv2/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/CANv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/CRYPv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/DACv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/DMAv2/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/EXTIv1/driver.mk
include $(CHIBIOS)/os/hal/ports/PAC/LLD/GPIOv2/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/I2Cv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/MACv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/OTGv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/QUADSPIv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/RTCv2/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/SPIv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/SDIOv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/SYSTICKv1/driver.mk
include $(CHIBIOS)/os/hal/ports/PAC/LLD/TIMv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/USARTv1/driver.mk
#include $(CHIBIOS)/os/hal/ports/PAC/LLD/xWDGv1/driver.mk

# Shared variables
ALLCSRC += $(PLATFORMSRC)
ALLINC  += $(PLATFORMINC)

