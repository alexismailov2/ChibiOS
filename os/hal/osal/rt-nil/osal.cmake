# OSAL files.
list(APPEND OSALSRC ${CHIBIOS}/os/hal/osal/rt-nil/osal.c)

# Required include directories
list(APPEND OSALINC ${CHIBIOS}/os/hal/osal/rt-nil)

# Shared variables
list(APPEND ALLCSRC ${OSALSRC})
list(APPEND ALLINC ${OSALINC})