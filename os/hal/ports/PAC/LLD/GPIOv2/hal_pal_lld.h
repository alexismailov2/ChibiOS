/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    PAC/GPIOv2/pal_lld.h
 * @brief   PAC55xx GPIO low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef _PAL_LLD_H_
#define _PAL_LLD_H_

#if HAL_USE_PAL || defined(__DOXYGEN__)

#include "pac55xx_sdk/peripheral/pac5xxx_gpio.h"

/*===========================================================================*/
/* Unsupported modes and specific modes                                      */
/*===========================================================================*/

#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN

/**
 * @name    PAC-specific I/O mode flags
 * @{
 */
//#define PAL_PAC_MODE_MASK             (3U << 0U)
//#define PAL_PAC_MODE_INPUT            IO_HIGH_IMPEDENCE_INPUT //(0U << 0U)
//#define PAL_PAC_MODE_OUTPUT           IO_PUSH_PULL_OUTPUT//(1U << 0U)
//#define PAL_PAC_MODE_ALTERNATE        //(2U << 0U)
//#define PAL_PAC_MODE_ANALOG           IO_ANAOG_INPUT //(3U << 0U)
//
//#define PAL_STM32_OTYPE_MASK            (1U << 2U)
//#define PAL_STM32_OTYPE_PUSHPULL        (0U << 2U)
//#define PAL_STM32_OTYPE_OPENDRAIN       (1U << 2U)
//
//#define PAL_STM32_OSPEED_MASK           (3U << 3U)
//#define PAL_STM32_OSPEED_LOWEST         (0U << 3U)
//#if defined(STM32F0XX) || defined(STM32F30X) || defined(STM32F37X)
//#define PAL_STM32_OSPEED_MID            (1U << 3U)
//#else
//#define PAL_STM32_OSPEED_MID1           (1U << 3U)
//#define PAL_STM32_OSPEED_MID2           (2U << 3U)
//#endif
//#define PAL_STM32_OSPEED_HIGHEST        (3U << 3U)
//
//#define PAL_STM32_PUDR_MASK             (3U << 5U)
//#define PAL_STM32_PUDR_FLOATING         (0U << 5U)
//#define PAL_STM32_PUDR_PULLUP           (1U << 5U)
//#define PAL_STM32_PUDR_PULLDOWN         (2U << 5U)
//
//#define PAL_STM32_ALTERNATE_MASK        (15U << 7U)
//#define PAL_STM32_ALTERNATE(n)          ((n) << 7U)

/**
 * @brief   Alternate function.
 *
 * @param[in] n         alternate function selector
 */
#define PAL_MODE_ALTERNATE(n)           (PAL_PAC_MODE_ALTERNATE |         \
                                         PAL_PAC_ALTERNATE(n))
/** @} */

/**
 * @name    Standard I/O mode flags
 * @{
 */
/**
 * @brief   This mode is implemented as input.
 */
#define PAL_MODE_RESET                  PAL_PAC_MODE_INPUT

/**
 * @brief   This mode is implemented as input with pull-up.
 */
#define PAL_MODE_UNCONNECTED            PAL_MODE_INPUT_PULLUP

/**
 * @brief   Regular input high-Z pad.
 */
#define PAL_MODE_INPUT                  PAL_PAC_MODE_INPUT

/**
 * @brief   Input pad with weak pull up resistor.
 */
#define PAL_MODE_INPUT_PULLUP           (PAL_PAC_MODE_INPUT |             \
                                         PAL_PAC_PUDR_PULLUP)

/**
 * @brief   Input pad with weak pull down resistor.
 */
#define PAL_MODE_INPUT_PULLDOWN         (PAL_PAC_MODE_INPUT |             \
                                         PAL_PAC_PUDR_PULLDOWN)

/**
 * @brief   Analog input mode.
 */
#define PAL_MODE_INPUT_ANALOG           PAL_PAC_MODE_ANALOG

/**
 * @brief   Push-pull output pad.
 */
#define PAL_MODE_OUTPUT_PUSHPULL        (PAL_PAC_MODE_OUTPUT |            \
                                         PAL_PAC_OTYPE_PUSHPULL)

/**
 * @brief   Open-drain output pad.
 */
#define PAL_MODE_OUTPUT_OPENDRAIN       (PAL_PAC_MODE_OUTPUT |            \
                                         PAL_PAC_OTYPE_OPENDRAIN)
/** @} */

/* Discarded definitions from the ST headers, the PAL driver uses its own
   definitions in order to have an unified handling for all devices.
   Unfortunately the ST headers have no uniform definitions for the same
   objects across the various sub-families.*/
#undef GPIOA
#undef GPIOB
#undef GPIOC
#undef GPIOD
#undef GPIOE
#undef GPIOF
#undef GPIOG
#undef GPIOH
#undef GPIOI

/**
 * @name    GPIO ports definitions
 * @{
 */
#define GPIOA                           PAC55XX_GPIOA
#define GPIOB                           PAC55XX_GPIOB
#define GPIOC                           PAC55XX_GPIOC
#define GPIOD                           PAC55XX_GPIOD
#define GPIOE                           PAC55XX_GPIOE
#define GPIOF                           PAC55XX_GPIOF
#define GPIOG                           PAC55XX_GPIOG
/** @} */

/*===========================================================================*/
/* I/O Ports Types and constants.                                            */
/*===========================================================================*/

/**
 * @brief   GPIO port setup info.
 */
typedef struct {
    uint32_t              muxsel;  // Initial value for PxMUXSEL register.
    uint32_t              mode;    // Initial value for MODE register.
    uint32_t              puen;    // Initial value for PxPUEN register.
    uint32_t              pden;    // Initial value for PxPDEN register.
    uint32_t              ds;      // Initial value for PxDS register.
    uint32_t              out;     // Initial value for OUT register.
} pac_gpio_setup_t;

/**
 * @brief   PAC GPIO static initializer.
 * @details An instance of this structure must be passed to @p palInit() at
 *          system startup time in order to initialize the digital I/O
 *          subsystem. This represents only the initial setup, specific pads
 *          or whole ports can be reprogrammed at later time.
 */
typedef struct {
#if PAC_HAS_GPIOA || defined(__DOXYGEN__)
  /** @brief Port A setup data.*/
  pac_gpio_setup_t    PAData;
#endif
#if PAC_HAS_GPIOB || defined(__DOXYGEN__)
  /** @brief Port B setup data.*/
  pac_gpio_setup_t    PBData;
#endif
#if PAC_HAS_GPIOC || defined(__DOXYGEN__)
  /** @brief Port C setup data.*/
  pac_gpio_setup_t    PCData;
#endif
#if PAC_HAS_GPIOD || defined(__DOXYGEN__)
  /** @brief Port D setup data.*/
  pac_gpio_setup_t    PDData;
#endif
#if PAC_HAS_GPIOE || defined(__DOXYGEN__)
  /** @brief Port E setup data.*/
  pac_gpio_setup_t    PEData;
#endif
#if PAC_HAS_GPIOF || defined(__DOXYGEN__)
  /** @brief Port F setup data.*/
  pac_gpio_setup_t    PFData;
#endif
#if PAC_HAS_GPIOG || defined(__DOXYGEN__)
  /** @brief Port G setup data.*/
  pac_gpio_setup_t    PGData;
#endif
} PALConfig;

/**
 * @brief   Width, in bits, of an I/O port.
 */
#define PAL_IOPORTS_WIDTH 8

/**
 * @brief   Whole port mask.
 * @details This macro specifies all the valid bits into a port.
 */
#define PAL_WHOLE_PORT ((ioportmask_t)0x00FF)

/**
 * @brief   Digital I/O port sized unsigned type.
 */
typedef uint32_t ioportmask_t;

/**
 * @brief   Digital I/O modes.
 */
typedef uint32_t iomode_t;

/**
 * @brief   Port Identifier.
 * @details This type can be a scalar or some kind of pointer, do not make
 *          any assumption about it, use the provided macros when populating
 *          variables of this type.
 */
typedef PAC55XX_GPIO_TYPEDEF * ioportid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/* The low level driver wraps the definitions already present in the STM32   */
/* firmware library.                                                         */
/*===========================================================================*/

/**
 * @brief   GPIO port A identifier.
 */
#if PAC_HAS_GPIOA || defined(__DOXYGEN__)
#define IOPORT1         GPIOA
#endif

/**
 * @brief   GPIO port B identifier.
 */
#if PAC_HAS_GPIOB || defined(__DOXYGEN__)
#define IOPORT2         GPIOB
#endif

/**
 * @brief   GPIO port C identifier.
 */
#if PAC_HAS_GPIOC || defined(__DOXYGEN__)
#define IOPORT3         GPIOC
#endif

/**
 * @brief   GPIO port D identifier.
 */
#if PAC_HAS_GPIOD || defined(__DOXYGEN__)
#define IOPORT4         GPIOD
#endif

/**
 * @brief   GPIO port E identifier.
 */
#if PAC_HAS_GPIOE || defined(__DOXYGEN__)
#define IOPORT5         GPIOE
#endif

/**
 * @brief   GPIO port F identifier.
 */
#if PAC_HAS_GPIOF || defined(__DOXYGEN__)
#define IOPORT6         GPIOF
#endif

/**
 * @brief   GPIO port G identifier.
 */
#if PAC_HAS_GPIOG || defined(__DOXYGEN__)
#define IOPORT7         GPIOG
#endif

/*===========================================================================*/
/* Implementation, some of the following macros could be implemented as      */
/* functions, if so please put them in pal_lld.c.                            */
/*===========================================================================*/

/**
 * @brief   GPIO ports subsystem initialization.
 *
 * @notapi
 */
#define pal_lld_init(config) _pal_lld_init(config)

/**
 * @brief   Reads an I/O port.
 * @details This function is implemented by reading the GPIO IDR register, the
 *          implementation has no side effects.
 * @note    This function is not meant to be invoked directly by the application
 *          code.
 *
 * @param[in] port      port identifier
 * @return              The port bits.
 *
 * @notapi
 */
#define pal_lld_readport(port) ((port)->IN.w)

/**
 * @brief   Reads the output latch.
 * @details This function is implemented by reading the GPIO ODR register, the
 *          implementation has no side effects.
 * @note    This function is not meant to be invoked directly by the application
 *          code.
 *
 * @param[in] port      port identifier
 * @return              The latched logical states.
 *
 * @notapi
 */
#define pal_lld_readlatch(port) ((port)->OUT.w)

/**
 * @brief   Writes on a I/O port.
 * @details This function is implemented by writing the GPIO ODR register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits) ((port)->OUT.w = (bits))

/**
 * @brief   Sets a bits mask on a I/O port.
 * @details This function is implemented by writing the GPIO BSRR register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be ORed on the specified port
 *
 * @notapi
 */
#define pal_lld_setport(port, bits) ((port)->DOSET = (uint16_t)(bits))

/**
 * @brief   Clears a bits mask on a I/O port.
 * @details This function is implemented by writing the GPIO BSRR register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be cleared on the specified port
 *
 * @notapi
 */
#define pal_lld_clearport(port, bits) ((port)->CLEAR = (uint16_t)(bits))

/**
 * @brief   Writes a group of bits.
 * @details This function is implemented by writing the GPIO BSRR register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    the group bit offset within the port
 * @param[in] bits      bits to be written. Values exceeding the group
 *                      width are masked.
 *
 * @notapi
 */
#if 0
#define pal_lld_writegroup(port, mask, offset, bits)                        \
  ((port)->BSRR.W = ((~(bits) & (mask)) << (16U + (offset))) |              \
                     (((bits) & (mask)) << (offset)))
#endif

/**
 * @brief   Pads group mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 *
 * @param[in] port      port identifier
 * @param[in] mask      group mask
 * @param[in] offset    group bit offset within the port
 * @param[in] mode      group mode
 *
 * @notapi
 */
#if 0
#define pal_lld_setgroupmode(port, mask, offset, mode)                      \
  _pal_lld_setgroupmode(port, mask << offset, mode)
#endif

/**
 * @brief   Writes a logical state on an output pad.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] bit       logical value, the value must be @p PAL_LOW or
 *                      @p PAL_HIGH
 *
 * @notapi
 */
#define pal_lld_writepad(port, pad, bit) pal_lld_writegroup(port, 1, pad, bit)

extern const PALConfig pal_default_config;

#ifdef __cplusplus
extern "C" {
#endif
  void _pal_lld_init(const PALConfig *config);
//  void _pal_lld_setgroupmode(ioportid_t port,
//                             ioportmask_t mask,
//                             iomode_t mode);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL */

#endif /* _PAL_LLD_H_ */

/** @} */
