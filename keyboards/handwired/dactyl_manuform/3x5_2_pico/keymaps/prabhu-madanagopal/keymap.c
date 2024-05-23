// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "features/achordion.h"

// Layers
enum layers {
    _DVORAK = 0,
    _SYMBOL,
    _NAVIGATION,
};
// Quantum keys / Abbreviations
enum custom_keycodes {
    VVV = KC_TRNS,
    SYM = TO(_SYMBOL),
    DVORAK = TO(_DVORAK),
    NAV = TO(_NAVIGATION),
    CSA_SPC = MEH_T(KC_SPC),
    CSA_SYM = MEH_T(TO(_SYMBOL)),
    O_LSFT = OSM(MOD_LSFT),

    LCTL_A = LCTL_T(KC_A),
    LALT_O = LALT_T(KC_O),
    LGUI_E = LGUI_T(KC_E),
    LSFT_U = LSFT_T(KC_U),
    RSFT_H = RSFT_T(KC_H),
    RGUI_T = RGUI_T(KC_T),
    RALT_N = RALT_T(KC_N),
    RCTL_S = RCTL_T(KC_S),
    LCTL_1 = LCTL_T(KC_1),
    LALT_2 = LALT_T(KC_2),
    LGUI_3 = LGUI_T(KC_3),
    LSFT_4 = LSFT_T(KC_4),
    RSFT_7 = RSFT_T(KC_7),
    RGUI_8 = RGUI_T(KC_8),
    RALT_9 = RALT_T(KC_9),
    RCTL_0 = RCTL_T(KC_0),
    CTL_F11= LCTL_T(KC_F11),
    ALT_F12= LALT_T(KC_F12),
    SFT_LT = RSFT_T(KC_LEFT),
    GUI_DN = RGUI_T(KC_DOWN),
    ALT_RT = RALT_T(KC_RGHT),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │' "│, <│. >│ P │ Y │       │ F │ G │ C │ R │ L │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │A ⎈│O ⌥│E ⌘│U ⇧│ I │       │ D │H ⇧│T ⌘│N ⌥│S ⎈│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │/ ?│ Q │ J │ K │ X │       │ B │ M │ W │ V │ Z │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │ ␣ ├───┐   ┌───┤SYM│
      *               └───┤ ⇥ │   │ ⏎ ├───┘
      *                   └───┘   └───┘
      */
    [_DVORAK] = LAYOUT_split_3x5_2_pico(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
        LCTL_A,  LALT_O,  LGUI_E,  LSFT_U,  KC_I,                               KC_D,    RSFT_H,  RGUI_T,  RALT_N,  RCTL_S,
        KC_SLSH, KC_Q,    KC_J,    KC_K,    KC_X,                               KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                                   KC_SPC,  KC_TAB,                             KC_ENT,  SYM
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ ⎋ │` ~│; :│- _│= +│       │. >│[ {│] }│\ |│ ⌫ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │1 !│2 @│3 #│4 $│5 %│       │6 ^│7 &│8 *│9 (│0 )│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │   │   │   │   │   │       │   │   │   │   │NAV│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤   │
      *               └───┤ ⇥ │   │ ⏎ ├───┘
      *                   └───┘   └───┘
      */
    [_SYMBOL] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_GRV,  KC_SCLN, KC_MINS, KC_EQL,                             KC_DOT,  KC_LBRC, KC_RBRC, KC_BSLS, KC_BSPC,
        LCTL_1,  LALT_2,  LGUI_3,  LSFT_4,  KC_5,                               KC_6,    RSFT_7,  RGUI_8,  RALT_9,  RCTL_0,
        _______, _______, _______, _______, _______,                            _______, _______, _______, _______, NAV,
                                   DVORAK,  KC_TAB,                             KC_ENT,  _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ ⎋ │RMD│MOD│TOG│ ↑ │       │ ⇞ │   │ ▲ │   │ ⌫ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │F11│F12│ ⌘ │ ⇧ │ ↓ │       │ ⇟ │ ◀ │ ▼ │ ▶ │ ⎈ │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │F1 │F2 │F3 │F4 │F5 │       │F6 │F7 │F8 │F9 │F10│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤ ⇥ │   │ ⏎ ├───┘
      *                   └───┘   └───┘
      */
    [_NAVIGATION] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  RGB_RMOD,RGB_MOD, RGB_TOG, KC_HOME,                            KC_PGUP, _______, KC_UP,   _______, KC_BSPC,
        CTL_F11, ALT_F12, KC_LGUI, KC_LSFT, KC_END,                             KC_PGDN, SFT_LT,  GUI_DN,  ALT_RT,  KC_RCTL,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
                                   DVORAK,  KC_TAB,                             KC_ENT,  SYM
    )

};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = rgb_matrix_get_hsv();

    if (layer_state_is(_DVORAK)) {
        hsv.h = 126;
    } else if (layer_state_is(_SYMBOL)){
        hsv.h = 0;
    } else if (layer_state_is(_NAVIGATION)){
        hsv.h = 84;
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x08)) { // 0x08 == LED_FLAG_INDICATOR
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        }
    }
    return false;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    // Repeating is useful for Vim navigation keys.
    case LSFT_U:
    case LGUI_E:
    case RSFT_H:
    case RALT_N:
    case SFT_LT:
    case GUI_DN:
    case ALT_RT:
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

//achordion - starts here
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // macros ...
  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LGUI:
    case MOD_RGUI:
      return true;  // Eagerly apply Cmd mods.

    default:
      return false;
  }
}

//achordion - ends here
