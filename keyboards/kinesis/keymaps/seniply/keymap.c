#include QMK_KEYBOARD_H

#include "oneshot.h"

// This layout is a QMK implementation of stevep99's seniply layout:
// https://stevep99.github.io/seniply/

#define COLEMAK 0
#define DVORAK 1
#define EXTEND 2
#define FUNCTION 3
#define SYMBOL 4
#define SYMBOL2 5

enum keycodes {
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

// keycode aliases
#define _bk  A(KC_LEFT)   // back one word
#define _fnd C(KC_F)      // find
#define _fw  A(KC_RIGHT)  // forward one word
#define _udo LCMD(KC_Z)
#define _cut LCMD(KC_X)
#define _cpy LCMD(KC_C)
#define _pst LCMD(KC_V)
#define LA_CMK DF(COLEMAK)
#define LA_DVK DF(DVORAK)
#define LA_EXT MO(EXTEND)
#define LA_FUN MO(FUNCTION)
#define LA_SYM MO(SYMBOL)
#define LA_SYM2 MO(SYMBOL2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[COLEMAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               KC_LSFT, LA_EXT,  LA_SYM2,

        _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                       _______, _______,
                                _______,
              _______, LA_SYM,  KC_SPC
),

[DVORAK] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,
        _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        _______, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               KC_LSFT, LA_EXT,  LA_SYM2,

        _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
        KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______,
        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                       _______, _______,
                                _______,
              _______, LA_SYM,  KC_SPC
),

[EXTEND] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_ESC,  _bk,     _fnd,    _fw,     KC_INS,
        _______, OS_ALT,  OS_CMD,  OS_SHFT, OS_CTRL, _______,
        _______, _udo,    _cut,    _cpy,    _pst,    KC_TAB,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, _______,

        _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS, _______,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  _______,
        KC_ENT,  KC_BSPC, KC_LSFT, KC_LCTL, _______, _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                       _______, _______,
                                _______,
              _______, LA_FUN, KC_ENT
),

[FUNCTION] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, LA_CMK,  LA_DVK,  _______, _______, _______,
        _______, OS_ALT,  OS_CMD,  OS_SHFT, OS_CTRL, _______,
        _______, _udo,    _cut,    _cpy,    _pst,    KC_TAB,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, _______,

        _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        KC_F12,  KC_F7,   KC_F8,   KC_F8,   RESET,   _______,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                       _______, _______,
                                _______,
              _______, _______, _______
),

[SYMBOL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,
        _______, KC_SCLN, KC_COLN, KC_LCBR, KC_LPRN, KC_LBRC,
        _______, KC_CIRC, KC_AMPR, KC_RCBR, KC_RPRN, KC_RBRC,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, LA_FUN,  _______,

        _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS, _______,
        KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                       _______, _______,
                                _______,
              _______, _______, _______
),

[SYMBOL2] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, KC_SCLN, KC_COLN, _______, _______, _______,
        _______, KC_CIRC, KC_AMPR, _______, _______, _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, _______,

        _______, _______, _______, _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, KC_UNDS, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______,
                        /* thumb cluster */
                       _______, _______,
                                _______,
              _______, _______, _______
),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_EXT:
    case LA_SYM:
    case LA_SYM2:
    case LA_FUN:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_EXT:
    case LA_SYM:
    case LA_SYM2:
    case LA_FUN:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_CMD:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
            &os_shft_state, KC_LSFT, OS_SHFT,
            keycode, record
    );
    update_oneshot(
            &os_ctrl_state, KC_LCTL, OS_CTRL,
            keycode, record
    );
    update_oneshot(
            &os_alt_state, KC_LALT, OS_ALT,
            keycode, record
    );
    update_oneshot(
            &os_cmd_state, KC_LCMD, OS_CMD,
            keycode, record
    );

    return true;
}

void led_set_user(uint8_t usb_led) {

}
