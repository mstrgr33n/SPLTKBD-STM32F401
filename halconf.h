#pragma once

#undef HAL_USE_SERIAL
#define HAL_USE_SERIAL TRUE
#define SERIAL_USB_BUFFERS_SIZE 256

#undef HAL_USE_I2C
#define HAL_USE_I2C TRUE

#define PAL_USE_CALLBACKS TRUE
#define PAL_USE_WAIT TRUE

#include_next <halconf.h>
