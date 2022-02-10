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
 * @file    PAC55xx/pac_isr.h
 * @brief   ISR remapper driver header.
 *
 * @addtogroup PAC55xx_ISR
 * @{
 */

#pragma once

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR names and numbers remapping
 * @{
 */

//=========================================================================
// External Exceptions
//=========================================================================
#define MemCtl_IRQHandler   Vector40
#define Wdt_IRQHandler      Vector44
#define RTC_IRQHandler      Vector48
#define ADC_IRQHandler      Vector4C
#define ADC1_IRQHandler     Vector50
#define ADC2_IRQHandler     Vector54
#define ADC3_IRQHandler     Vector58
#define TimerA_IRQHandler   Vector5C
#define TimerB_IRQHandler   Vector60
#define TimerC_IRQHandler   Vector64
#define TimerD_IRQHandler   Vector68
#define QEPA_IRQHandler     Vector6C
#define QEPB_IRQHandler     Vector70
#define QEPC_IRQHandler     Vector74
#define QEPD_IRQHandler     Vector78
#define GpioA_IRQHandler    Vector7C
#define GpioB_IRQHandler    Vector80
#define GpioC_IRQHandler    Vector84
#define GpioD_IRQHandler    Vector88
#define GpioE_IRQHandler    Vector8C
#define GpioF_IRQHandler    Vector90
#define GpioG_IRQHandler    Vector94
#define I2C_IRQHandler      Vector98
#define USARTA_IRQHandler   Vector9C
#define USARTB_IRQHandler   VectorA0
#define USARTC_IRQHandler   VectorA4
#define USARTD_IRQHandler   VectorA8
#define CAN_IRQHandler      VectorAC
#define GPTimerA_IRQHandler VectorB0
#define GPTimerB_IRQHandler VectorB4
#define SYSCTRL_IRQHandler  VectorB8

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/** @} */
