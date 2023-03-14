# MCU name
MCU = STM32F401
BOARD = BLACKPILL_STM32_F401
# Bootloader selection
BOOTLOADER = stm32-dfu

OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
STENO_ENABLE = no
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
KEYBOARD_SHARED_EP = yes
WAIT_FOR_USB = yes
NO_USB_STARTUP_CHECK =  no
LTO_ENABLE = yes
VIA_ENABLE = yes

