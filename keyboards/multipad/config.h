// Copyright 2022 Florian (@deafloo)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/*
* OLED options
* see https://docs.qmk.fm/#/feature_oled_driver?id=supported-hardware
*/
#define OLED_DISPLAY_ADDRESS 0x7B
#define OLED_DISPLAY_CUSTOM
#define OLED_DISPLAY_WIDTH 64
#define OLED_DISPLAY_HEIGHT 48
#define OLED_MATRIX_SIZE 384
#define OLED_BLOCK_TYPE uint16_t
#define OLED_BLOCK_COUNT 16
#define OLED_BLOCK_SIZE 24
#define OLED_COM_PINS COM_PINS_SEQ
#define OLED_SOURCE_MAP { 0, 1, 2, 3, 4, 5, 6, 7 }
#define OLED_TARGET_MAP { 3, 7, 2, 6, 1, 5, 0, 4 }

/*
* Encoder options
* see https://docs.qmk.fm/#/feature_encoders
*/
#define ENCODERS_PAD_A {GP3}
#define ENCODERS_PAD_B {GP4}
#define ENCODER_RESOLUTION 1

/*
* I2C options
* see https://docs.qmk.fm/#/i2c_driver
*/
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP16
#define I2C1_SCL_PIN GP17

/*
* RGB options
*/
#define RGB_DI_PIN GP10
#define DRIVER_LED_TOTAL 14


#define BOOTMAGIG_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define RP2040_FLASH_IS25LP080