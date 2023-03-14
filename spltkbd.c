#include <hal.h>
#include "usb_main.h"
#include "spltkbd.h"


void i2c_init(void) {
    setPinInput(B6);
    setPinInput(B7);
    wait_ms(10);

    palSetPadMode(GPIOB, 6, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP); // Set B6 to I2C function
    palSetPadMode(GPIOB, 7, PAL_MODE_ALTERNATE(4) | PAL_STM32_OTYPE_OPENDRAIN | PAL_STM32_PUPDR_PULLUP); // Set B7 to I2C function
}

void keyboard_pre_init_kb(void) {
    if (!eeconfig_is_enabled()) {
      eeconfig_init();
    }
    wait_ms(10);
    keyboard_pre_init_user();
}
