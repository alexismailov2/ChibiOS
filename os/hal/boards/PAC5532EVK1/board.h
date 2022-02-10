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

#pragma once

/*
 * Setup for PAC5556EVK... <Should be filled> board.
 */

/*
 * Board identifier.
 */
//#define BOARD_ST_STM32F4_DISCOVERY
#define BOARD_NAME                  "Active-semi PAC5556EVK"


/*
 * Board oscillators-related settings.
 * NOTE: LSE not fitted.
 */
//#if !defined(STM32_LSECLK)
//#define STM32_LSECLK                0U
//#endif
//
//#if !defined(STM32_HSECLK)
//#define STM32_HSECLK                8000000U
//#endif

/*
 * Board voltages.
 * Required for performance limits calculation.
 */
// TODO: Does not used shoule be found analog if there is in pac55xx.
//#define STM32_VDD                   300U

/*
 * MCU type as defined in the PAC header.
 */
//#define PAC5532

/*
 * IO pins assignments.
 */
#define GPIO_PIN0                  0U
#define GPIO_PIN1                  1U
#define GPIO_PIN2                  2U
#define GPIO_PIN3                  3U
#define GPIO_PIN4                  4U
#define GPIO_PIN5                  5U
#define GPIO_PIN6                  6U
#define GPIO_PIN7                  7U

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE(n, mode)   (mode << ((n) * 2U))
#define PIN_OUT_LOW(n)      (0U << (n))
#define PIN_OUT_HIGH(n)     (1U << (n))
#define PIN_PUEN(n, en)     (en << (n))
#define PIN_PDEN(n, en)     (en << (n))
#define PIN_MUXSEL(n, v)    ((v) << (((n) & 0x07) * 4U))
#define PIN_DS(n, v)        ((v) << (((n) & 0x0F) * 4U))

/*
 * GPIOA setup:
 */
#define VAL_GPIOA_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOA_MODE               (PIN_MODE(GPIO_PIN0, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOA_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOA_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOA_DS                 (PIN_DS(GPIO_PIN0, 0) | \
                                      PIN_DS(GPIO_PIN1, 0) | \
                                      PIN_DS(GPIO_PIN2, 0) | \
                                      PIN_DS(GPIO_PIN3, 0) | \
                                      PIN_DS(GPIO_PIN4, 0) | \
                                      PIN_DS(GPIO_PIN5, 0) | \
                                      PIN_DS(GPIO_PIN6, 0) | \
                                      PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOA_OUT                (PIN_OUT_HIGH(GPIO_PIN0) | \
                                      PIN_OUT_HIGH(GPIO_PIN1) | \
                                      PIN_OUT_HIGH(GPIO_PIN2) | \
                                      PIN_OUT_HIGH(GPIO_PIN3) | \
                                      PIN_OUT_HIGH(GPIO_PIN4) | \
                                      PIN_OUT_HIGH(GPIO_PIN5) | \
                                      PIN_OUT_HIGH(GPIO_PIN6) | \
                                      PIN_OUT_HIGH(GPIO_PIN7))

/*
 * GPIOB setup:
 */
#define VAL_GPIOB_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOB_MODE               (PIN_MODE(GPIO_PIN0, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOB_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOB_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOB_DS                (PIN_DS(GPIO_PIN0, 0) | \
                                     PIN_DS(GPIO_PIN1, 0) | \
                                     PIN_DS(GPIO_PIN2, 0) | \
                                     PIN_DS(GPIO_PIN3, 0) | \
                                     PIN_DS(GPIO_PIN4, 0) | \
                                     PIN_DS(GPIO_PIN5, 0) |  \
                                     PIN_DS(GPIO_PIN6, 0) |  \
                                     PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOB_OUT               (PIN_OUT_HIGH(GPIO_PIN0) | \
                                     PIN_OUT_HIGH(GPIO_PIN1) | \
                                     PIN_OUT_HIGH(GPIO_PIN2) | \
                                     PIN_OUT_HIGH(GPIO_PIN3) | \
                                     PIN_OUT_HIGH(GPIO_PIN4) | \
                                     PIN_OUT_HIGH(GPIO_PIN5) | \
                                     PIN_OUT_HIGH(GPIO_PIN6) | \
                                     PIN_OUT_HIGH(GPIO_PIN7))

/*
 * GPIOC setup:
 */
#define VAL_GPIOC_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOC_MODE               (PIN_MODE(GPIO_PIN0, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOC_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOC_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOC_DS                (PIN_DS(GPIO_PIN0, 0) | \
                                     PIN_DS(GPIO_PIN1, 0) | \
                                     PIN_DS(GPIO_PIN2, 0) | \
                                     PIN_DS(GPIO_PIN3, 0) | \
                                     PIN_DS(GPIO_PIN4, 0) | \
                                     PIN_DS(GPIO_PIN5, 0) |  \
                                     PIN_DS(GPIO_PIN6, 0) |  \
                                     PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOC_OUT               (PIN_OUT_HIGH(GPIO_PIN0) | \
                                     PIN_OUT_HIGH(GPIO_PIN1) | \
                                     PIN_OUT_HIGH(GPIO_PIN2) | \
                                     PIN_OUT_HIGH(GPIO_PIN3) | \
                                     PIN_OUT_HIGH(GPIO_PIN4) | \
                                     PIN_OUT_HIGH(GPIO_PIN5) | \
                                     PIN_OUT_HIGH(GPIO_PIN6) | \
                                     PIN_OUT_HIGH(GPIO_PIN7))

/*
 * GPIOD setup:
 */
#define VAL_GPIOD_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOD_MODE               (PIN_MODE(GPIO_PIN0, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOD_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOD_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOD_DS                (PIN_DS(GPIO_PIN0, 0) | \
                                     PIN_DS(GPIO_PIN1, 0) | \
                                     PIN_DS(GPIO_PIN2, 0) | \
                                     PIN_DS(GPIO_PIN3, 0) | \
                                     PIN_DS(GPIO_PIN4, 0) | \
                                     PIN_DS(GPIO_PIN5, 0) |  \
                                     PIN_DS(GPIO_PIN6, 0) |  \
                                     PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOD_OUT               (PIN_OUT_HIGH(GPIO_PIN0) | \
                                     PIN_OUT_HIGH(GPIO_PIN1) | \
                                     PIN_OUT_HIGH(GPIO_PIN2) | \
                                     PIN_OUT_HIGH(GPIO_PIN3) | \
                                     PIN_OUT_HIGH(GPIO_PIN4) | \
                                     PIN_OUT_HIGH(GPIO_PIN5) | \
                                     PIN_OUT_HIGH(GPIO_PIN6) | \
                                     PIN_OUT_HIGH(GPIO_PIN7))

/*
 * GPIOE setup:
 */
#define VAL_GPIOE_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOE_MODE               (PIN_MODE(GPIO_PIN0, IO_PUSH_PULL_OUTPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_PUSH_PULL_OUTPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOE_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOE_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOE_DS                (PIN_DS(GPIO_PIN0, 0) | \
                                     PIN_DS(GPIO_PIN1, 0) | \
                                     PIN_DS(GPIO_PIN2, 0) | \
                                     PIN_DS(GPIO_PIN3, 0) | \
                                     PIN_DS(GPIO_PIN4, 0) | \
                                     PIN_DS(GPIO_PIN5, 0) |  \
                                     PIN_DS(GPIO_PIN6, 0) |  \
                                     PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOE_OUT               (PIN_OUT_LOW(GPIO_PIN0) | \
                                     PIN_OUT_LOW(GPIO_PIN1) | \
                                     PIN_OUT_LOW(GPIO_PIN2) | \
                                     PIN_OUT_LOW(GPIO_PIN3) | \
                                     PIN_OUT_LOW(GPIO_PIN4) | \
                                     PIN_OUT_LOW(GPIO_PIN5) | \
                                     PIN_OUT_LOW(GPIO_PIN6) | \
                                     PIN_OUT_LOW(GPIO_PIN7))
/*
 * GPIOF setup:
 */
#define VAL_GPIOF_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOF_MODE               (PIN_MODE(GPIO_PIN0, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOF_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOF_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOF_DS                (PIN_DS(GPIO_PIN0, 0) | \
                                     PIN_DS(GPIO_PIN1, 0) | \
                                     PIN_DS(GPIO_PIN2, 0) | \
                                     PIN_DS(GPIO_PIN3, 0) | \
                                     PIN_DS(GPIO_PIN4, 0) | \
                                     PIN_DS(GPIO_PIN5, 0) |  \
                                     PIN_DS(GPIO_PIN6, 0) |  \
                                     PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOF_OUT               (PIN_OUT_HIGH(GPIO_PIN0) | \
                                     PIN_OUT_HIGH(GPIO_PIN1) | \
                                     PIN_OUT_HIGH(GPIO_PIN2) | \
                                     PIN_OUT_HIGH(GPIO_PIN3) | \
                                     PIN_OUT_HIGH(GPIO_PIN4) | \
                                     PIN_OUT_HIGH(GPIO_PIN5) | \
                                     PIN_OUT_HIGH(GPIO_PIN6) | \
                                     PIN_OUT_HIGH(GPIO_PIN7))

/*
 * GPIOG setup:
 */
#define VAL_GPIOG_MUXSEL             (PIN_MUXSEL(GPIO_PIN0, 0) | \
                                      PIN_MUXSEL(GPIO_PIN1, 0) | \
                                      PIN_MUXSEL(GPIO_PIN2, 0) | \
                                      PIN_MUXSEL(GPIO_PIN3, 0) | \
                                      PIN_MUXSEL(GPIO_PIN4, 0) | \
                                      PIN_MUXSEL(GPIO_PIN5, 0) | \
                                      PIN_MUXSEL(GPIO_PIN6, 0) | \
                                      PIN_MUXSEL(GPIO_PIN7, 0))

#define VAL_GPIOG_MODE               (PIN_MODE(GPIO_PIN0, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN1, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN2, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN3, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN4, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN5, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN6, IO_HIGH_IMPEDENCE_INPUT) | \
                                      PIN_MODE(GPIO_PIN7, IO_HIGH_IMPEDENCE_INPUT))

#define VAL_GPIOG_PUEN               (PIN_PUEN(GPIO_PIN0, 0) | \
                                      PIN_PUEN(GPIO_PIN1, 0) | \
                                      PIN_PUEN(GPIO_PIN2, 0) | \
                                      PIN_PUEN(GPIO_PIN3, 0) | \
                                      PIN_PUEN(GPIO_PIN4, 0) | \
                                      PIN_PUEN(GPIO_PIN5, 0) | \
                                      PIN_PUEN(GPIO_PIN6, 0) | \
                                      PIN_PUEN(GPIO_PIN7, 0))

#define VAL_GPIOG_PDEN               (PIN_PDEN(GPIO_PIN0, 0) | \
                                      PIN_PDEN(GPIO_PIN1, 0) | \
                                      PIN_PDEN(GPIO_PIN2, 0) | \
                                      PIN_PDEN(GPIO_PIN3, 0) | \
                                      PIN_PDEN(GPIO_PIN4, 0) | \
                                      PIN_PDEN(GPIO_PIN5, 0) | \
                                      PIN_PDEN(GPIO_PIN6, 0) | \
                                      PIN_PDEN(GPIO_PIN7, 0))

#define VAL_GPIOG_DS                (PIN_DS(GPIO_PIN0, 0) | \
                                     PIN_DS(GPIO_PIN1, 0) | \
                                     PIN_DS(GPIO_PIN2, 0) | \
                                     PIN_DS(GPIO_PIN3, 0) | \
                                     PIN_DS(GPIO_PIN4, 0) | \
                                     PIN_DS(GPIO_PIN5, 0) |  \
                                     PIN_DS(GPIO_PIN6, 0) |  \
                                     PIN_DS(GPIO_PIN7, 0))

#define VAL_GPIOG_OUT               (PIN_OUT_HIGH(GPIO_PIN0) | \
                                     PIN_OUT_HIGH(GPIO_PIN1) | \
                                     PIN_OUT_HIGH(GPIO_PIN2) | \
                                     PIN_OUT_HIGH(GPIO_PIN3) | \
                                     PIN_OUT_HIGH(GPIO_PIN4) | \
                                     PIN_OUT_HIGH(GPIO_PIN5) | \
                                     PIN_OUT_HIGH(GPIO_PIN6) | \
                                     PIN_OUT_HIGH(GPIO_PIN7))

#define PAC_HAS_GPIOA 1
#define PAC_HAS_GPIOB 1
#define PAC_HAS_GPIOC 1
#define PAC_HAS_GPIOD 1
#define PAC_HAS_GPIOE 1
#define PAC_HAS_GPIOF 1
#define PAC_HAS_GPIOG 1

//#define PAC_INIT_GPIOA_NEEDED
//#define PAC_INIT_GPIOB_NEEDED
//#define PAC_INIT_GPIOC_NEEDED
//#define PAC_INIT_GPIOD_NEEDED
#define PAC_INIT_GPIOE_NEEDED
//#define PAC_INIT_GPIOF_NEEDED
//#define PAC_INIT_GPIOG_NEEDED

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

