/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2021 @dlford
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// wiring of each half
#define MATRIX_COL_PINS { GP2,GP3,GP4,GP5,GP6 }
#define MATRIX_ROW_PINS { GP8,GP9,GP10,GP11 }

#define DIODE_DIRECTION ROW2COL

//split config
//#define SOFT_SERIAL_PIN D2  // or D1, D2, D3, E6


#define USE_SERIAL
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0     // USART TX pin
#define SERIAL_USART_RX_PIN GP1     // USART RX pin
#define SERIAL_USART_PIN_SWAP      // Swap TX and RX pins if keyboard is master halve. (Only available on some MCUs)
#define SERIAL_PIO_USE_PIO0
#define SERIAL_USART_TIMEOUT     100  // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600

// Tap-hold configuration for home row mods.
#undef TAPPING_TERM
#define TAPPING_TERM 175
#define ACHORDION_STREAK
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM_PER_KEY

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1
#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 1
#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 22
#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3



/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#undef LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#undef LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
//#undef PERMISSIVE_HOLD
#define MASTER_RIGHT
#ifdef RGBLIGHT_ENABLE
#  define WS2812_DI_PIN GP7
#  define RGB_DI_PIN GP7
#  define RGBLED_NUM 35
#  define RGBLED_SPLIT { 18, 17 }
#  define RGBLIGHT_SLEEP
#  define RGBLIGHT_LIMIT_VAL 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#  define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING // Sets the default mode, if none has been set
//#  define RGBLIGHT_DEFAULT_HUE 148 // Sets the default hue value, if none has been set
#  define RGBLIGHT_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#  define RGBLIGHT_DEFAULT_VAL RGBLIGHT_LIMIT_VAL // Sets the default brightness value, if none has been set
#  define RGBLIGHT_DEFAULT_SPD 127 // Sets the default animation speed, if none has been set
#  define RGBLIGHT_HUE_STEP 8
#  define RGBLIGHT_SAT_STEP 8
#  define RGBLIGHT_VAL_STEP 8
#  define RGBLIGHT_SPD_STEP 10
#  define SPLIT_LAYER_STATE_ENABLE
#  define RGBLIGHT_LAYERS
// Enable animations
/* #  define RGBLIGHT_MODE_BREATHING  */
/* #  define RGBLIGHT_MODE_RAINBOW_MOOD */
/* #  define RGBLIGHT_MODE_RAINBOW_SWIRL */
/* #  define RGBLIGHT_MODE_SNAKE */
/* #  define RGBLIGHT_MODE_KNIGHT */
/* #  define RGBLIGHT_MODE_CHRISTMAS */
/* #  define RGBLIGHT_MODE_STATIC_GRADIENT */
/* #  define RGBLIGHT_MODE_RGB_TEST */
/* #  define RGBLIGHT_MODE_ALTERNATING */
/* #  define RGBLIGHT_MODE_TWINKLE */

#  define RGBLIGHT_EFFECT_ALTERNATING
#  define RGBLIGHT_EFFECT_BREATHING
#  define RGBLIGHT_EFFECT_CHRISTMAS
#  define RGBLIGHT_EFFECT_KNIGHT
#  define RGBLIGHT_EFFECT_RAINBOW_MOOD
#  define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#  define RGBLIGHT_EFFECT_RGB_TEST
#  define RGBLIGHT_EFFECT_SNAKE
#  define RGBLIGHT_EFFECT_STATIC_GRADIENT
#  define RGBLIGHT_EFFECT_TWINKLE
#endif

#ifdef RGB_MATRIX_ENABLE
#  define WS2812_DI_PIN GP7
#  define RGB_DI_PIN GP7
#  define WS2812_DI_PIN GP7
#  define RGB_MATRIX_LED_COUNT 35
#  define RGB_MATRIX_SPLIT { 18, 17 }
#  define RGB_MATRIX_CENTER { 133, 54 }
// #  define RGB_MATRIX_TIMEOUT 300000 // number of milliseconds to wait until disabling effects
#  define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#  define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#  define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#  define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
#  define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT // Sets the default mode, if none has been set
#  define RGB_MATRIX_DEFAULT_HUE 148 // Sets the default hue value, if none has been set
#  define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#  define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
#  define RGB_MATRIX_DEFAULT_SPD 127 // Sets the default animation speed, if none has been set
#  define RGB_MATRIX_HUE_STEP 8
#  define RGB_MATRIX_SAT_STEP 8
#  define RGB_MATRIX_VAL_STEP 8
#  define RGB_MATRIX_SPD_STEP 10
#  define SPLIT_LAYER_STATE_ENABLE
#  define RGB_TRIGGER_ON_KEYDOWN      // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
// Enable animations
#  define ENABLE_RGB_MATRIX_ALPHAS_MODS                 // Static dual hue speed is hue for secondary hue
#  define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN            // Static gradient top to bottom speed controls how much gradient changes
#  define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT         // Static gradient left to right speed controls how much gradient changes
#  define ENABLE_RGB_MATRIX_BREATHING                   // Single hue brightness cycling animation
#  define ENABLE_RGB_MATRIX_BAND_SAT                    // Single hue band fading saturation scrolling left to right
#  define ENABLE_RGB_MATRIX_BAND_VAL                    // Single hue band fading brightness scrolling left to right
#  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT           // Single hue 3 blade spinning pinwheel fades saturation
#  define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL           // Single hue 3 blade spinning pinwheel fades brightness
#  define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT             // Single hue spinning spiral fades saturation
#  define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL             // Single hue spinning spiral fades brightness
#  define ENABLE_RGB_MATRIX_CYCLE_ALL                   // Full keyboard solid hue cycling through full gradient
#  define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT            // Full gradient scrolling left to right
#  define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN               // Full gradient scrolling top to bottom
#  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN                // Full gradient scrolling out to in
#  define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL           // Full dual gradients scrolling out to in
#  define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON      // Full gradent Chevron shapped scrolling left to right
#  define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL              // Full gradient spinning pinwheel around center of keyboard
#  define ENABLE_RGB_MATRIX_CYCLE_SPIRAL                      // Full gradient spinning spiral around center of keyboard
#  define ENABLE_RGB_MATRIX_DUAL_BEACON                 // Full gradient spinning around center of keyboard
#  define ENABLE_RGB_MATRIX_RAINBOW_BEACON              // Full tighter gradient spinning around center of keyboard
#  define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS           // Full dual gradients spinning two halfs of keyboard
#  define ENABLE_RGB_MATRIX_RAINDROPS                   // Randomly changes a single key's hue
#  define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS         // Randomly changes a single key's hue and saturation
#  define ENABLE_RGB_MATRIX_HUE_BREATHING               // Hue shifts up a slight ammount at the same time then shifts back
#  define ENABLE_RGB_MATRIX_HUE_PENDULUM                // Hue shifts up a slight ammount in a wave to the right then back to the left
#  define ENABLE_RGB_MATRIX_HUE_WAVE                          // Hue shifts up a slight ammount and then back down in a wave to the right
#  define RGB_MATRIX_FRAMEBUFFER_EFFECTS // Required for the following two effects
#  define ENABLE_RGB_MATRIX_TYPING_HEATMAP               // How hot is your WPM!
#  define ENABLE_RGB_MATRIX_DIGITAL_RAIN                 // That famous computer simulation
#  define RGB_MATRIX_KEYPRESSES // reacts to keypresses, required for the remaining effects
// #    define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE       // Pulses keys hit to hue & value then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE              // Static single hue pulses keys hit to shifted hue then fades to current hue
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE         // Hue & value pulse near a single key hit then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE    // Hue & value pulse near multiple key hits then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS        // Hue & value pulse the same column and row of a single key hit then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS   // Hue & value pulse the same column and row of multiple key hits then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS        // Hue & value pulse away on the same column and row of a single key hit then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS   // Hue & value pulse away on the same column and row of multiple key hits then fades value out
#  define ENABLE_RGB_MATRIX_SPLASH                      // Full gradient & value pulse away from a single key hit then fades value out
#  define ENABLE_RGB_MATRIX_MULTISPLASH                 // Full gradient & value pulse away from multiple key hits then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_SPLASH                // Hue & value pulse away from a single key hit then fades value out
#  define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH           // Hue & value pulse away from multiple key hits then fades value out
#endif
