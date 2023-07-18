# Build Options
#   change yes to no to disable
#
MCU = RP2040
BOOTLOADER = rp2040
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
#NKRO_ENABLE = yes           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_LIGHT_DRIVER = WS2812
# AUDIO_ENABLE = yes          # Audio output

RGB_MATRIX_ENABLE = yes 			# Enable WS2812 RGB matrix
RGB_MATRIX_DRIVER = WS2812
SPLIT_KEYBOARD = yes
#RGBLIGHT_SUPPORTED = yes
RGB_MATRIX_SUPPORTED = yes
WPM_ENABLE = yes
SERIAL_DRIVER = vendor
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
MOUSE_SHARED_EP = yes
