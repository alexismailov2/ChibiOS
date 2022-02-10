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
 * @file    PAC/GPIOv2/pal_lld.c
 * @brief   PAC55xx GPIO low level driver code.
 *
 * @addtogroup PAL
 * @{
 */

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

#if 0 // TODO: Should be deletd after replaced with corresponded implementation from PAC55xx
#if defined(STM32L1XX)
#define AHB_EN_MASK     (RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN |          \
                         RCC_AHBENR_GPIOCEN | RCC_AHBENR_GPIODEN |          \
                         RCC_AHBENR_GPIOEEN | RCC_AHBENR_GPIOHEN)
#define AHB_LPEN_MASK   AHB_EN_MASK

#elif defined(STM32F0XX)
#define AHB_EN_MASK     STM32_GPIO_EN_MASK

#elif defined(STM32F3XX) || defined(STM32F37X)
#define AHB_EN_MASK     STM32_GPIO_EN_MASK

#elif defined(STM32F2XX) || defined(STM32F4XX)
#define AHB1_EN_MASK    STM32_GPIO_EN_MASK
#define AHB1_LPEN_MASK  AHB1_EN_MASK

#else
#error "missing or unsupported platform for GPIOv2 PAL driver"
#endif
#endif

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

static void initgpio(PAC55XX_GPIO_TYPEDEF* gpiop, const pac_gpio_setup_t* config) {
  if (gpiop == PAC55XX_GPIOA) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PAMUXSEL.w = config->muxsel; // PAMUXSEL (PA Peripheral MUX Select, 400D 040Ch)
      PAC55XX_SCC->PAPUEN.w = config->puen;     // PAPUEN (PA Pull-up Enable, 400D 0428h)
      PAC55XX_SCC->PAPDEN.w = config->pden;     // PAPDEN (PA Pull-Down Enable, 400D 0444h)
      PAC55XX_SCC->PADS.w = config->ds;         // PADS (PA Drive Strength/Schmitt Trigger, 400D 0460h)
  } else if (gpiop == PAC55XX_GPIOB) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PBMUXSEL.w = config->muxsel; // PBMUXSEL (PB Peripheral MUX Select, 400D 0410h)
      PAC55XX_SCC->PBPUEN.w = config->puen;     // PBPUEN (PB Pull-up Enable, 400D 042Ch)
      PAC55XX_SCC->PBPDEN.w = config->pden;     // PBPDEN (PB Pull-Down Enable, 400D 0448h)
      PAC55XX_SCC->PBDS.w = config->ds;         // PBDS (PB Drive Strength/Schmitt Trigger, 400D 0464h)
  } else if (gpiop == PAC55XX_GPIOC) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PCMUXSEL.w = config->muxsel; // PCMUXSEL (PC Peripheral MUX Select, 400D 0414h)
      PAC55XX_SCC->PCPUEN.w = config->puen;     // PCPUEN (PC Pull-up Enable, 400D 0430h)
      PAC55XX_SCC->PCPDEN.w = config->pden;     // PCPDEN (PC Pull-Down Enable, 400D 044Ch)
      PAC55XX_SCC->PCDS.w = config->ds;         // PCDS (PC Drive Strength/Schmitt Trigger, 400D 0468h)
  } else if (gpiop == PAC55XX_GPIOD) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PDMUXSEL.w = config->muxsel; // PDMUXSEL (PD Peripheral MUX Select, 400D 0418h)
      PAC55XX_SCC->PDPUEN.w = config->puen;     // PDPUEN (PD Pull-up Enable, 400D 0434h)
      PAC55XX_SCC->PDPDEN.w = config->pden;     // PDPDEN (PD Pull-Down Enable, 400D 0450h)
      PAC55XX_SCC->PDDS.w = config->ds;         // PDDS (PD Drive Strength/Schmitt Trigger, 400D 046Ch)
  } else if (gpiop == PAC55XX_GPIOE) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PEMUXSEL.w = config->muxsel; // PEMUXSEL (PE Peripheral MUX Select, 400D 041Ch)
      PAC55XX_SCC->PEPUEN.w = config->puen;     // PEPUEN (PE Pull-up Enable, 400D 0438h)
      PAC55XX_SCC->PEPDEN.w = config->pden;     // PEPDEN (PE Pull-Down Enable, 400D 0454h)
      PAC55XX_SCC->PEDS.w = config->ds;         // PEDS (PE Drive Strength/Schmitt Trigger, 400D 0470h)
  } else if (gpiop == PAC55XX_GPIOF) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PFMUXSEL.w = config->muxsel; // PFMUXSEL (PF Peripheral MUX Select, 400D 0420h)
      PAC55XX_SCC->PFPUEN.w = config->puen;     // PFPUEN (PF Pull-up Enable, 400D 043Ch)
      PAC55XX_SCC->PFPDEN.w = config->pden;     // PFPDEN (PF Pull-Down Enable, 400D 0458h)
      PAC55XX_SCC->PFDS.w = config->ds;         // PFDS (PF Drive Strength/Schmitt Trigger, 400D 0474h)
  } else if (gpiop == PAC55XX_GPIOG) {
      gpiop->OUT.w = config->out;               //
      gpiop->MODE.w = config->mode;             //
      PAC55XX_SCC->PGMUXSEL.w = config->muxsel; // PGMUXSEL (PG Peripheral MUX Select, 400D 0424h)
      PAC55XX_SCC->PGPUEN.w = config->puen;     // PGPUEN (PG Pull-up Enable, 400D 0440h)
      PAC55XX_SCC->PGPDEN.w = config->pden;     // PGPDEN (PG Pull-Down Enable, 400D 045Ch)
      PAC55XX_SCC->PGDS.w = config->ds;         // PGDS (PG Drive Strength/Schmitt Trigger, 400D 0478h)
  }
}

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   STM32 I/O ports configuration.
 * @details Ports A-D(E, F, G, H) clocks enabled.
 *
 * @param[in] config    the STM32 ports configuration
 *
 * @notapi
 */
void _pal_lld_init(const PALConfig *config) {

  /*
   * Enables the GPIO related clocks.
   */

//#if defined(STM32L1XX)
//  rccEnableAHB(AHB_EN_MASK, TRUE);
//  RCC->AHBLPENR |= AHB_LPEN_MASK;
//#elif defined(STM32F0XX)
//  rccEnableAHB(AHB_EN_MASK, TRUE);
//#elif defined(STM32F3XX) || defined(STM32F37X)
//  rccEnableAHB(AHB_EN_MASK, TRUE);
//#elif defined(STM32F2XX) || defined(STM32F4XX)
//  RCC->AHB1ENR   |= AHB1_EN_MASK;
//  RCC->AHB1LPENR |= AHB1_LPEN_MASK;
//#endif

  /*
   * Initial GPIO setup.
   */
#if PAC_HAS_GPIOA && defined(PAC_INIT_GPIOA_NEEDED)
  initgpio(GPIOA, &config->PAData);
#endif
#if PAC_HAS_GPIOB && defined(PAC_INIT_GPIOB_NEEDED)
  initgpio(GPIOB, &config->PBData);
#endif
#if PAC_HAS_GPIOC && defined(PAC_INIT_GPIOC_NEEDED)
  initgpio(GPIOC, &config->PCData);
#endif
#if PAC_HAS_GPIOD && defined(PAC_INIT_GPIOD_NEEDED)
  initgpio(GPIOD, &config->PDData);
#endif
#if PAC_HAS_GPIOE && defined(PAC_INIT_GPIOE_NEEDED)
  initgpio(GPIOE, &config->PEData);
#endif
#if PAC_HAS_GPIOF && defined(PAC_INIT_GPIOF_NEEDED)
  initgpio(GPIOF, &config->PFData);
#endif
#if PAC_HAS_GPIOG && defined(PAC_INIT_GPIOG_NEEDED)
  initgpio(GPIOG, &config->PGData);
#endif
}

/**
 * @brief   Pads mode setup.
 * @details This function programs a pads group belonging to the same port
 *          with the specified mode.
 * @note    @p PAL_MODE_UNCONNECTED is implemented as push pull at minimum
 *          speed.
 *
 * @param[in] port      the port identifier
 * @param[in] mask      the group mask
 * @param[in] mode      the mode
 *
 * @notapi
 */
#if 0
#if 1
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode)
{
    (void)port;
    (void)mask;
    (void)mode;
//  uint32_t moder   = (mode & PAL_STM32_MODE_MASK) >> 0;
//  uint32_t otyper  = (mode & PAL_STM32_OTYPE_MASK) >> 2;
//  uint32_t ospeedr = (mode & PAL_STM32_OSPEED_MASK) >> 3;
//  uint32_t pupdr   = (mode & PAL_STM32_PUDR_MASK) >> 5;
//  uint32_t altr    = (mode & PAL_STM32_ALTERNATE_MASK) >> 7;
//  uint32_t bit     = 0;
//  while (TRUE) {
//    if ((mask & 1) != 0) {
//      uint32_t altrmask, m1, m2, m4;
//
//      altrmask = altr << ((bit & 7) * 4);
//      m4 = 15 << ((bit & 7) * 4);
//      if (bit < 8)
//        port->AFRL = (port->AFRL & ~m4) | altrmask;
//      else
//        port->AFRH = (port->AFRH & ~m4) | altrmask;
//      m1 = 1 << bit;
//      port->OTYPER  = (port->OTYPER & ~m1) | otyper;
//      m2 = 3 << (bit * 2);
//      port->OSPEEDR = (port->OSPEEDR & ~m2) | ospeedr;
//      port->PUPDR   = (port->PUPDR & ~m2) | pupdr;
//      port->MODER   = (port->MODER & ~m2) | moder;
//    }
//    mask >>= 1;
//    if (!mask)
//      return;
//    otyper <<= 1;
//    ospeedr <<= 2;
//    pupdr <<= 2;
//    moder <<= 2;
//    bit++;
//  }
}
#else
void _pal_lld_setgroupmode(ioportid_t port,
                           ioportmask_t mask,
                           iomode_t mode) {
  uint32_t afrm, moderm, pupdrm, otyperm, ospeedrm;
  uint32_t m1 = (uint32_t)mask;
  uint32_t m2 = 0;
  uint32_t m4l = 0;
  uint32_t m4h = 0;
  uint32_t bit = 0;
  do {
    if ((mask & 1) != 0) {
      m2 |= 3 << bit;
      if (bit < 16)
        m4l |= 15 << ((bit & 14) * 2);
      else
        m4h |= 15 << ((bit & 14) * 2);
    }
    bit += 2;
    mask >>= 1;
  } while (mask);

  afrm = ((mode & PAL_STM32_ALTERNATE_MASK) >> 7) * 0x1111;
  port->AFRL = (port->AFRL & ~m4l) | (afrm & m4l);
  port->AFRH = (port->AFRH & ~m4h) | (afrm & m4h);

  ospeedrm = ((mode & PAL_STM32_OSPEED_MASK) >> 3) * 0x5555;
  port->OSPEEDR = (port->OSPEEDR & ~m2) | (ospeedrm & m2);

  otyperm = ((mode & PAL_STM32_OTYPE_MASK) >> 2) * 0xffff;
  port->OTYPER = (port->OTYPER & ~m1) | (otyperm & m1);

  pupdrm = ((mode & PAL_STM32_PUDR_MASK) >> 5) * 0x5555;
  port->PUPDR = (port->PUPDR & ~m2) | (pupdrm & m2);

  moderm = ((mode & PAL_STM32_MODE_MASK) >> 0) * 0x5555;
  port->MODER = (port->MODER & ~m2) | (moderm & m2);
}
#endif
#endif
#endif /* HAL_USE_PAL */

/** @} */
