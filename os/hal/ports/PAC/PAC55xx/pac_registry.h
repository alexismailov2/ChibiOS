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
 * @file    PAC55xx/pac_registry.h
 * @brief   PAC55xx capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#pragma once

#if defined(PAC5523) || defined(__DOXYGEN__)
#define CAFE_ARCH1

#include "pac55xx_sdk/peripheral/pac5xxx.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_driver_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_power_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_signal_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_system_manager.h"
#elif defined(PAC5524)
#define CAFE_ARCH1

#include "pac55xx_sdk/peripheral/pac5xxx.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_driver_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_power_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_signal_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_system_manager.h"
#elif defined(PAC5526)
#define CAFE_ARCH2

#include "pac55xx_sdk/peripheral/pac5xxx.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_driver_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_power_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_signal_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_system_manager.h"
#elif defined(PAC5527)
#define CAFE_ARCH2

#include "pac55xx_sdk/peripheral/pac5xxx.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_driver_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_power_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_signal_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_system_manager.h"
#elif defined(PAC5532)
#define CAFE_ARCH2

#include "pac55xx_sdk/peripheral/pac5xxx.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_driver_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_power_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_signal_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_system_manager.h"
#elif defined(PAC5556)
#define CAFE_ARCH2

#include "pac55xx_sdk/peripheral/pac5xxx.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_driver_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_power_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_signal_manager.h"
#include "pac55xx_sdk/peripheral/pac5xxx_tile_system_manager.h"
#else
    #error "Should be selected device"
#endif

#include "pac55xx_sdk/driver/pac5xxx_driver_adc.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_config.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_gpio.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_memory.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_socbridge.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_system.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_tile.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_timer.h"
#include "pac55xx_sdk/driver/pac5xxx_driver_uart.h"