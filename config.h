// Copyright 2022 mr.Gr33n (@mr.Gr33n)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

#ifndef STM32_LSECLK
#    define STM32_LSECLK 32768U
#endif  // STM32_LSECLK

#ifndef STM32_HSECLK
#    define STM32_HSECLK 25000000U
#endif  // STM32_HSECLK

#ifndef EARLY_INIT_PERFORM_BOOTLOADER_JUMP
#    define EARLY_INIT_PERFORM_BOOTLOADER_JUMP TRUE
#endif

/* USB Device descriptor parameter
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    mr.Gr33n
#define PRODUCT         splt.Kbd
*/
#define USE_SERIAL
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 20


#define SPLIT_USB_TIMEOUT 500
#define SPLIT_USB_TIMEOUT_POLL 10

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

#define DIODE_DIRECTION ROW2COL

#define BOOTMAGIC_LITE_ROW          0
#define BOOTMAGIC_LITE_COLUMN       0
#define BOOTMAGIC_LITE_ROW_RIGHT    6
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

#define DEBOUNCE 5

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define MATRIX_ROW_PINS { A1, A2, A3, A4 }
#define MATRIX_COL_PINS { B12, B13, B14, B15, C14, C15 }

#define SPLIT_HAND_PIN B9

#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B6
#define I2C1_SDA_PIN B7
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
#define I2C1_TIMINGR_PRESC 0x00U
#define I2C1_TIMINGR_SCLDEL 0x03U
#define I2C1_TIMINGR_SDADEL 0x01U
#define I2C1_TIMINGR_SCLH 0x03U
#define I2C1_TIMINGR_SCLL 0x09U
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_2
#define PAL_MODE_STM32_ALTERNATE_OPENDRAIN (PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN)
