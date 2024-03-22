// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

// Layers
enum layers {
    _DVORAK = 0,
    _SPECIAL,
    _NUMERAL,
    _NAVIGATION,
    _MEDIA,
    _FN,
};
// Quantum keys / Abbreviations
enum custom_keycodes {
    VVV = KC_TRNS,
    SPECIAL = TO(_SPECIAL),
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
    ALT_EQL = ALT_T(KC_EQL),
    CTL_E = CTL_T(KC_E),
    CTL_T = CTL_T(KC_T),
    CTL_MIN = CTL_T(KC_MINUS),
    CTL_RBR = CTL_T(KC_RBRC),
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
      *               └───┤SFT│   │GUI├───┘
      *                   └───┘   └───┘
      */
    [_DVORAK] = LAYOUT_split_3x5_2_pico(
        KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                               KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
        KC_A,    ALT_O,   CTL_E,   KC_U,    KC_I,                               KC_D,    KC_H,    CTL_T,   KC_N,    KC_S,
        KC_SLSH, KC_Q,    KC_J,    KC_K,    KC_X,                               KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                                   CSA_SPC, O_LSFT,                             O_LGUI,  SPECIAL
    ),
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│ @ │ . │ $ │ * │       │ ^ │ & │ % │ ! │BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│ = │ - │ ; │FN │       │ \ │ [ │ ] │ | │ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ~ │ ` │ _ │ : │ # │       │ { │ ( │ ) │ } │NAV│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤NUM│
      *               └───┤SFT│   │GUI├───┘
      *                   └───┘   └───┘
      */
    [_SPECIAL] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_AT,   KC_DOT,  KC_DLR,  KC_ASTR,                            KC_CIRC, KC_AMPR, KC_PERC, KC_EXLM, KC_BSPC,
        KC_TAB,  ALT_EQL, CTL_MIN, KC_SCLN, FN,                                 KC_BSLS, KC_LBRC, CTL_RBR, KC_PIPE, KC_ENT,
        KC_TILD, KC_GRV,  KC_UNDS, KC_COLN, KC_HASH,                            KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, NAV,
                                   DVORAK, O_LSFT,                              O_LGUI,  NUM
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│ @ │ . │ $ │ * │       │ - │ 7 │ 8 │ 9 │BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│ = │ - │ ; │ + │       │ = │ 4 │ 5 │ 6 │ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ / │ ` │ _ │ : │ # │       │ 0 │ 1 │ 2 │ 3 │NAV│
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤SFT│   │GUI├───┘
      *                   └───┘   └───┘
      */
    [_NUMERAL] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_AT,   KC_DOT,  KC_DLR,  KC_ASTR,                            KC_MINS, KC_7,    KC_8,    KC_9, KC_BSPC,
        KC_TAB,  ALT_EQL, KC_MINS, KC_SCLN, KC_PLUS,                            KC_EQL,  KC_4,    KC_5,    KC_6, KC_ENT,
        KC_SLSH, KC_GRV,  KC_UNDS, KC_COLN, KC_HASH,                            KC_0,    KC_1,    KC_2,    KC_3, NAV,
                                   DVORAK, O_LSFT,                              O_LGUI,  SPECIAL
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
      *               └───┤SFT│   │GUI├───┘
      *                   └───┘   └───┘
      */
    [_NAVIGATION] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_WH_L, KC_MS_U, KC_WH_R, KC_PERC,                            BACK,    PRV_TAB, NXT_TAB, FWD,     KC_BSPC,
        KC_TAB,  KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_ENT,
        KC_TILD, KC_BTN2, KC_WH_U, KC_WH_D, KC_PGDN,                            KC_BTN1, KC_ACL0, KC_ACL1, KC_ACL2, MEDIA,
                                   DVORAK, O_LSFT,                              O_LGUI,  SPECIAL
    ),

     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ESC│WHL│SPI│WHR│ % │       │BCK│PTB│NTB│FWD│BSP│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │TAB│SAD│SPD│SAI│DEL│       │HUD│VAD│VAI│HUI│ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ ~ │RCK│WHU│WHD│ . │       │TOG│MOD│AC2│AC3│   │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *               ┌───┐           ┌───┐
      *               │DVK├───┐   ┌───┤SYM│
      *               └───┤SFT│   │GUI├───┘
      *                   └───┘   └───┘
      */
    [_MEDIA] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_WH_L, RGB_SPI, KC_WH_R, KC_PERC,                            BACK,    PRV_TAB, NXT_TAB, FWD,     KC_BSPC,
        KC_TAB,  RGB_SAD, RGB_SPD, RGB_SAI, KC_DEL,                             RGB_HUD, RGB_VAD, RGB_VAI, RGB_HUI, KC_ENT,
        KC_TILD, KC_BTN2, KC_WH_U, KC_WH_D, KC_DOT,                             RGB_TOG, RGB_MOD, KC_ACL1, KC_ACL2, _______,
                                   DVORAK, O_LSFT,                              O_LGUI,  SPECIAL
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
      *               └───┤SFT│   │GUI├───┘
      *                   └───┘   └───┘
      */
    [_FN] = LAYOUT_split_3x5_2_pico(
        KC_ESC,  KC_AT,   KC_DOT,  KC_DLR,  KC_ASTR,                            KC_MINS, KC_F7,    KC_F8,    KC_F9, KC_BSPC,
        KC_TAB,  ALT_EQL, KC_MINS, KC_SCLN, KC_PLUS,                            KC_EQL,  KC_F4,    KC_F5,    KC_F6, KC_ENT,
        KC_SLSH, KC_GRV,  KC_UNDS, KC_COLN, KC_HASH,                            KC_0,    KC_F1,    KC_F2,    KC_F3, NAV,
                                   DVORAK, O_LSFT,                              O_LGUI,  SPECIAL
    )



};
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = rgb_matrix_get_hsv();

    if (layer_state_is(_DVORAK)) {
        hsv.h = 126;
    } else if (layer_state_is(_SPECIAL)){
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
