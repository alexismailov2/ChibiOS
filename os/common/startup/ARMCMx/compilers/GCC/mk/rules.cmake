# ARM Cortex-Mx common makefile scripts and rules.

##############################################################################
# Processing options coming from the upper Makefile.
#

# Compiler options
set(OPT ${USE_OPT})
set(COPT ${USE_COPT})
set(CPPOPT ${USE_CPPOPT})

# Garbage collection
if (USE_LINK_GC)
    set(OPT "${OPT} -ffunction-sections -fdata-sections -fno-common")
    set(LDOPT ",--gc-sections")
else()
    #LDOPT :=
endif()

# Linker extra options
if (NOT USE_LDOPT STREQUAL "")
    set(LDOPT "${LDOPT},${USE_LDOPT}")
endif()

# Link time optimizations
if (USE_LTO)
    set(OPT "${OPT} -flto")
endif()

# FPU options default (Cortex-M4 and Cortex-M7 single precision).
if (USE_FPU_OPT STREQUAL "")
    set(USE_FPU_OPT "-mfloat-abi=${USE_FPU} -mfpu=fpv4-sp-d16")
endif()

# FPU-related options
if (USE_FPU STREQUAL "")
    set(USE_FPU "no")
endif()

if (NOT USE_FPU STREQUAL "no")
    set(OPT "${OPT} ${USE_FPU_OPT}")
    set(DDEFS "${DDEFS} -DCORTEX_USE_FPU=TRUE")
    set(DADEFS "${DADEFS} -DCORTEX_USE_FPU=TRUE")
else()
    set(DDEFS "${DDEFS} -DCORTEX_USE_FPU=FALSE")
    set(DADEFS "${DADEFS} -DCORTEX_USE_FPU=FALSE")
endif()

# Process stack size
if (USE_PROCESS_STACKSIZE STREQUAL "")
    set(LDOPT "${LDOPT},--defsym=__process_stack_size__=0x400")
else()
    set(LDOPT "${LDOPT},--defsym=__process_stack_size__=${USE_PROCESS_STACKSIZE}")
endif()

# Exceptions stack size
if (USE_EXCEPTIONS_STACKSIZE STREQUAL "")
    set(LDOPT "${LDOPT},--defsym=__main_stack_size__=0x400")
else()
    set(LDOPT "${LDOPT},--defsym=__main_stack_size__=${USE_EXCEPTIONS_STACKSIZE}")
endif()

# Output directory and files
if (BUILDDIR STREQUAL "")
    set(BUILDDIR "build")
endif()
if (BUILDDIR STREQUAL ".")
    set(BUILDDIR "build")
endif()

# Dependencies directory
if (DEPDIR STREQUAL "")
    set(DEPDIR ".dep")
endif()
if (DEPDIR STREQUAL ".")
    set(DEPDIR ".dep")
endif()

# Macros
set(DEFS ${DDEFS} ${UDEFS})
set(ADEFS ${DADEFS} ${UADEFS})

# Libs
set(LIBS ${DLIBS} ${ULIBS})

# Various settings
set(MCFLAGS  "-mcpu=${MCU} -mthumb")
set(ODFLAGS  "-x --syms")
set(ASFLAGS  "${MCFLAGS} ${OPT} ${ADEFS}") # -Wa,-amhls=$(LSTDIR)/$(notdir $(<:.s=.lst))
set(ASXFLAGS "${MCFLAGS} ${OPT} ${ADEFS}") # -Wa,-amhls=$(LSTDIR)/$(notdir $(<:.S=.lst))
set(CFLAGS   "${MCFLAGS} ${OPT} ${COPT} ${CWARN} ${DEFS}") # -Wa,-alms=$(LSTDIR)/$(notdir $(<:.c=.lst))
set(CPPFLAGS "${MCFLAGS} ${OPT} ${CPPOPT} ${CPPWARN} ${DEFS}") # -Wa,-alms=$(LSTDIR)/$(notdir $(<:.cpp=.lst))
set(LDFLAGS  "${MCFLAGS} ${OPT} -nostartfiles ${LLIBDIR} -Wl,-Map=${BUILDDIR}/${PROJECT}.map,--cref,--no-warn-mismatch,--library-path=${STARTUPLD},--script=${LDSCRIPT}${LDOPT}")
