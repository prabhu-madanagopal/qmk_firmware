// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "features/achordion.h"

// Layers
enum layers {
    _DVORAK = 0,
    _SYMBOL,
    _NUMERAL,
    _NAVIGATION,
    _MEDIA,
    _FN,
};
// Quantum keys / Abbreviations
enum custom_keycodes {
    VVV = KC_TRNS,
    SYM = TO(_SYMBOL),
    DVORAK = TO(_DVORAK),
    NUM = TO(_NUMERAL),
    NAV = TO(_NAVIGATION),
    MEDIA = TO(_MEDIA),
    FN = TO(_FN),
    CSA_SPC = MEH_T(KC_SPC),
    O_LGUI = OSM(MOD_LGUI),
    O_LSFT = OSM(MOD_LSFT),
    PRV_TAB = LCTL(LSFT(KC_TAB)),
    NXT_TAB = RCTL(KC_TAB),
    BACK = LGUI(KC_LBRC),
    FWD = LGUI(KC_RBRC),
    ALT_O = ALT_T(KC_O),
    ALT_N = ALT_T(KC_N),
    ALT_EQL = ALT_T(KC_EQL),
    ALT_PIP = ALT_T(KC_PIPE),
    GUI_E = GUI_T(KC_E),
    GUI_T = GUI_T(KC_T),
    GUI_MIN = GUI_T(KC_MINUS),
    GUI_RBR = GUI_T(KC_RBRC),
    CTL_U = CTL_T(KC_U),
    CTL_H = CTL_T(KC_H),
    CTL_SCN = CTL_T(KC_SCLN),
    CTL_LBR = CTL_T(KC_LBRC),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ ' │ , │ . │ P │ Y │       │ F │ G │ C │ R │ L │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ O │ E │ U │ I │       │ D │ H │ T │ N │ S │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ / │ Q │ J │ K │ X │       │ B │ M │ W │ V │ Z │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │SPC├───┐   ┌───┤SYM│
      *               └───┤SFT│   │NUM├───┘
      *                   └───┘   └───┘
      */
    [_DVORAK] = LAYOUT_split_3x5_2_pico(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
        KC_A,    ALT_O,   GUI_E,   CTL_U,   KC_I,                               KC_D,    CTL_H,   GUI_T,   ALT_N,   KC_S,
        KC_SLSH, KC_Q,    KC_J,    KC_K,    KC_X,                               KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                                   CSA_SPC, O_LSFT,                             NUM,     SYM
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│ @ │ . │ $ │ * │       │ ^ │ & │ % │ ! │BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│ = │ - │ ; │ + │       │ \ │ [ │ ] │ | │ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ~ │ ` │ _ │ : │ # │       │ { │ ( │ ) │ } │NAV│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤   │
      *               └───┤SFT│   │NUM├───┘
      *                   └───┘   └───┘
      */
    [_SYMBOL] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_AT,   KC_DOT,  KC_DLR,  KC_ASTR,                            KC_CIRC, KC_AMPR, KC_PERC, KC_EXLM, KC_BSPC,
        KC_TAB,  ALT_EQL, GUI_MIN, CTL_SCN, KC_PLUS,                                 KC_BSLS, CTL_LBR, GUI_RBR, ALT_PIP, KC_ENT,
        KC_TILD, KC_GRV,  KC_UNDS, KC_COLN, KC_HASH,                            KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, NAV,
                                   DVORAK, O_LSFT,                              NUM,     _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│ @ │ . │ $ │ * │       │ - │ 7 │ 8 │ 9 │BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│ = │ - │ ; │ + │       │ = │ 4 │ 5 │ 6 │ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ / │ ` │ _ │ : │ # │       │ 0 │ 1 │ 2 │ 3 │FN │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤SFT│   │   ├───┘
      *                   └───┘   └───┘
      */
    [_NUMERAL] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_AT,   KC_DOT,  KC_DLR,  KC_ASTR,                            KC_MINS, KC_7,    KC_8,    KC_9, KC_BSPC,
        KC_TAB,  ALT_EQL, KC_MINS, CTL_SCN, KC_PLUS,                            KC_EQL,  KC_4,    KC_5,    KC_6, KC_ENT,
        KC_SLSH, KC_GRV,  KC_UNDS, KC_COLN, KC_HASH,                            KC_0,    KC_1,    KC_2,    KC_3, FN,
                                   DVORAK, O_LSFT,                              _______, SYM
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│WHL│MSU│WHR│ % │       │BCK│PTB│NTB│FWD│BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│MSL│MSD│MSR│DEL│       │<- │DN │ UP│RGT│ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ~ │RCK│WHU│WHD│ . │       │LCK│AC1│AC2│AC3│MDA│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤SFT│   │NUM├───┘
      *                   └───┘   └───┘
      */
    [_NAVIGATION] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_WH_L, KC_MS_U, KC_WH_R, KC_PERC,                            BACK,    PRV_TAB, NXT_TAB, FWD,     KC_BSPC,
        KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_TILD, KC_BTN2, KC_WH_U, KC_WH_D, KC_PGDN,                            KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, MEDIA,
                                   DVORAK, O_LSFT,                              NUM,     SYM
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│WHL│SPI│WHR│ % │       │BCK│PTB│NTB│FWD│BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│SAD│SPD│SAI│DEL│       │HUD│VAD│VAI│HUI│ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ~ │RCK│WHU│WHD│ . │       │TOG│MOD│AC2│AC3│NAV│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤SFT│   │NUM├───┘
      *                   └───┘   └───┘
      */
    [_MEDIA] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_WH_L, RGB_SPI, KC_WH_R, KC_PERC,                            BACK,    PRV_TAB, NXT_TAB, FWD,     KC_BSPC,
        KC_TAB,  RGB_SAD, RGB_SPD, RGB_SAI, KC_DEL,                             RGB_HUD, RGB_VAD, RGB_VAI, RGB_HUI, KC_ENT,
        KC_TILD, KC_BTN2, KC_WH_U, KC_WH_D, KC_DOT,                             RGB_TOG, RGB_MOD, KC_ACL1, KC_ACL2, NAV,
                                   DVORAK, O_LSFT,                              NUM,     SYM
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│ @ │ . │ $ │ * │       │ - │ F7│ F8│ F9│BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│ = │ - │ ; │ + │       │ = │ F4│ F5│ F6│ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ / │ ` │ _ │ : │ # │       │ F0│ F1│ F2│ F3│NAV│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤SFT│   │NUM├───┘
      *                   └───┘   └───┘
      */
    [_FN] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_AT,   KC_DOT,  KC_DLR,  KC_ASTR,                            KC_MINS, KC_F7,    KC_F8,    KC_F9, KC_BSPC,
        KC_TAB,  ALT_EQL, GUI_MIN, CTL_SCN, KC_PLUS,                            KC_EQL,  KC_F4,    KC_F5,    KC_F6, KC_ENT,
        KC_SLSH, KC_GRV,  KC_UNDS, KC_COLN, KC_HASH,                            KC_0,    KC_F1,    KC_F2,    KC_F3, NAV,
                                   DVORAK, O_LSFT,                              NUM,     SYM
    )



};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = rgb_matrix_get_hsv();

    if (layer_state_is(_DVORAK)) {
        hsv.h = 126;
    } else if (layer_state_is(_SYMBOL)){
        hsv.h = 0;
    } else if (layer_state_is(_NUMERAL)){
        hsv.h = 84;
    } else if (layer_state_is(_NAVIGATION)){
        hsv.h = 168;
    } else if (layer_state_is(_MEDIA)){
        hsv.h = 42;
    } else if (layer_state_is(_FN)){
        hsv.h = 210;
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
    case CTL_U:
    // Repeating is useful for Vim navigation keys.
    case CTL_H:
    case GUI_T:
    case ALT_N:
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
