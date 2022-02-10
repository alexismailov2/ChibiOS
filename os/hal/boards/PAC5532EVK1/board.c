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

#include "hal.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)
/**
 * @brief   PAL setup.
 * @details Digital I/O ports static configuration as defined in @p board.h.
 *          This variable is used by the HAL when initializing the PAL driver.
 */
const PALConfig pal_default_config = {
#if PAC_HAS_GPIOA
        {VAL_GPIOA_MUXSEL, VAL_GPIOA_MODE, VAL_GPIOA_PUEN, VAL_GPIOA_PDEN, VAL_GPIOA_DS, VAL_GPIOA_OUT},
#endif
#if PAC_HAS_GPIOB
        {VAL_GPIOB_MUXSEL, VAL_GPIOB_MODE, VAL_GPIOB_PUEN, VAL_GPIOB_PDEN, VAL_GPIOB_DS, VAL_GPIOB_OUT},
#endif
#if PAC_HAS_GPIOC
        {VAL_GPIOC_MUXSEL, VAL_GPIOC_MODE, VAL_GPIOC_PUEN, VAL_GPIOC_PDEN, VAL_GPIOC_DS, VAL_GPIOC_OUT},
#endif
#if PAC_HAS_GPIOD
        {VAL_GPIOD_MUXSEL, VAL_GPIOD_MODE, VAL_GPIOD_PUEN, VAL_GPIOD_PDEN, VAL_GPIOD_DS, VAL_GPIOD_OUT},
#endif
#if PAC_HAS_GPIOE
        {VAL_GPIOE_MUXSEL, VAL_GPIOE_MODE, VAL_GPIOE_PUEN, VAL_GPIOE_PDEN, VAL_GPIOE_DS, VAL_GPIOE_OUT},
#endif
#if PAC_HAS_GPIOF
        {VAL_GPIOF_MUXSEL, VAL_GPIOF_MODE, VAL_GPIOF_PUEN, VAL_GPIOF_PDEN, VAL_GPIOF_DS, VAL_GPIOF_OUT},
#endif
#if PAC_HAS_GPIOG
        {VAL_GPIOG_MUXSEL, VAL_GPIOG_MODE, VAL_GPIOG_PUEN, VAL_GPIOG_PDEN, VAL_GPIOG_DS, VAL_GPIOG_OUT},
#endif
};
#endif

/**
 * @brief   Early initialization code.
 * @details This initialization must be performed just after stack setup
 *          and before any other initialization.
 */
void __early_init(void) {

    pac_clock_init();
}

#if HAL_USE_SDC || defined(__DOXYGEN__)
/**
 * @brief   SDC card detection.
 */
bool sdc_lld_is_card_inserted(SDCDriver *sdcp) {

  (void)sdcp;
  /* TODO: Fill the implementation.*/
  return true;
}

/**
 * @brief   SDC card write protection detection.
 */
bool sdc_lld_is_write_protected(SDCDriver *sdcp) {

  (void)sdcp;
  /* TODO: Fill the implementation.*/
  return false;
}
#endif /* HAL_USE_SDC */

#if HAL_USE_MMC_SPI || defined(__DOXYGEN__)
/**
 * @brief   MMC_SPI card detection.
 */
bool mmc_lld_is_card_inserted(MMCDriver *mmcp) {

  (void)mmcp;
  /* TODO: Fill the implementation.*/
  return true;
}

/**
 * @brief   MMC_SPI card write protection detection.
 */
bool mmc_lld_is_write_protected(MMCDriver *mmcp) {

  (void)mmcp;
  /* TODO: Fill the implementation.*/
  return false;
}
#endif

/**
 * @brief   Board-specific initialization code.
 * @todo    Add your board-specific code, if any.
 */
void boardInit(void) {
}
