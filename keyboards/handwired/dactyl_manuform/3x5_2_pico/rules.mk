# MCU name
MCU = RP2040
BOOTLOADER = rp2040
SERIAL_DRIVER = vendor
F_CPU = 8000000
SPLIT_KEYBOARD = yes
CAPS_WORD_ENABLE = yes
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
# AUDIO_ENABLE = yes          # Audio output

#LAYOUTS = split_3x5_3

RGB_MATRIX_ENABLE = no 			# Enable WS2812 RGB matrix
#RGB_MATRIX_DRIVER = WS2812
#RGBLIGHT_SUPPORTED = yes
#RGB_MATRIX_SUPPORTED = yes

#SERIAL_DRIVER = vendor
#WS2812_DRIVER = vendor

#achordion for home row mod fixes
SRC += features/achordion.c
