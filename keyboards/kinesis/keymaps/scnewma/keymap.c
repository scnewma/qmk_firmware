#include QMK_KEYBOARD_H

#define _BASE 0
#define _SHIFTED 1
#define _CBASE 2
#define _CSFT 3
#define _QWERTY 4
#define _COMMANDS 5
#define _KEYPAD 6

//  TODO:
//    CLIPSC and PRNTSC might be better combined onto one key using tap dance.
//    PRNTSC would be the tap command and CLIPSC would be the hold command.
#define CLIPSC G(S(C(KC_4)))        // Cmd-Shift-Ctrl-4 -> macOS Screenshot (clipboard)
#define PRNTSC G(S(KC_4))           // Cmd-Shift-4 -> macOS Screenshot

enum custom_keycodes {
    TMX_PRVW = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,
        KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,
                 _______, KC_BSLS, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI,     OSL(_COMMANDS),
                                     KC_HYPR,
               KC_BSPC, KC_LSFT, KC_LCTL,

        KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK,  DF(_BASE), DF(_CBASE), DF(_QWERTY),
        KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_F,  KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_D,  KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,    _______,
               KC_UP,  KC_DOWN,  KC_LBRC, KC_RBRC,
                        /* thumb cluster */
                        KC_LALT,  KC_RGUI,
                                  _______,
               _______, KC_ENTER, KC_SPC
),

[_CBASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,
        KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                   KC_PIPE, KC_BSLS, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI, OSL(_COMMANDS),
                                 KC_HYPR,
               KC_BSPC, _______, KC_LCTL,

        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK,  DF(_BASE), DF(_CBASE), DF(_QWERTY),
        KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_J,  KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINUS,
        KC_H,  KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_K,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
               KC_UP,   KC_DOWN, KC_AT,   _______,
                        /* thumb cluster */
                       KC_LALT,  KC_RGUI,
                                 _______,
              _______, KC_ENTER, KC_SPC
),

// A qwerty layout that I use for gaming.
// Changes made to standard qwerty:
// * swapped CAPS LOCK with ESC
[_QWERTY] = LAYOUT(
        KC_ESC,  KC_F1,  KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
        KC_EQL,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,
        KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,
        KC_ESC,  KC_A,   KC_S,    KC_D,    KC_F,  KC_G,
        KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,
                 KC_GRV,  KC_INS, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                                KC_LCTL, KC_LALT,
                                         KC_HOME,
                       KC_BSPC, KC_DEL,  KC_END,

        KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, DF(_BASE), DF(_CBASE), DF(_QWERTY),
        KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
               KC_UP, KC_DOWN, KC_LBRC, KC_RBRC,
                        /* thumb cluster */
                                 KC_RGUI,  KC_RCTL,
                                           KC_PGUP,
                        KC_PGDN, KC_ENTER, KC_SPC
),

[_COMMANDS] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, CLIPSC, PRNTSC,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,
               KC_NO, KC_NO, KC_NO, KC_NO,
                        /* thumb cluster */
                         KC_NO, KC_NO,
                                KC_NO,
                  KC_NO, KC_NO, KC_NO,

        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, TMX_PRVW, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,
               KC_NO, KC_NO,    KC_NO, RESET,
                        /* thumb cluster */
                       KC_NO, KC_NO,
                              KC_NO,
                KC_NO, KC_NO, KC_NO
),

[_KEYPAD] = LAYOUT (
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                 _______, _______,  _______, _______,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, _______,

           // Right Hand
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_PEQL, KC_PSLS, KC_PAST, _______,
        _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
        _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______,
        _______, KC_P1,   KC_P2,   KC_P3,   KC_PENT, _______,
                 _______, _______, KC_PDOT, KC_PENT,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, KC_P0
)
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void register_unshifted_kc(uint16_t keycode, bool lsft_pressed, bool rsft_pressed) {
    // we need to unregister any registered shift presses since the kc that we
    // are registering should be unshifted
    unregister_code(KC_LSHIFT);
    unregister_code(KC_RSHIFT);

    // register the actual keycode
    tap_code16(keycode);

    // re-register any shift keys that were registered
    if (lsft_pressed) {
        register_code(KC_LSHIFT);
    }
    if (rsft_pressed) {
        register_code(KC_RSHIFT);
    }
}

// process_record_user_shifted_keycode processes keycode if shift is not pressed and processes
// shifted_keycode if shift is pressed
bool process_record_user_shifted_keycode(uint16_t keycode, uint16_t shifted_keycode, keyrecord_t *record) {
    bool lsft_pressed = get_mods() & MOD_BIT(KC_LSFT);
    bool rsft_pressed = get_mods() & MOD_BIT(KC_RSFT);
    if (record->event.pressed && (lsft_pressed || rsft_pressed)) {
        register_unshifted_kc(shifted_keycode, lsft_pressed, rsft_pressed);
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TMX_PRVW:
        if (record->event.pressed) {
            // send tmux leader twice, which i use to switch to previous window
            tap_code16(C(KC_SPC));
            tap_code16(C(KC_SPC));
        }
        break;

    // handle my non-default shifted keycodes
    /* case KC_DLR: */
    /*     return process_record_user_shifted_keycode(keycode, KC_GRV, record); */
    /* case KC_PLUS: */
    /*     return process_record_user_shifted_keycode(keycode, KC_1, record); */
    /* case KC_LBRC: */
    /*     return process_record_user_shifted_keycode(keycode, KC_2, record); */
    /* case KC_LCBR: */
    /*     return process_record_user_shifted_keycode(keycode, KC_3, record); */
    /* case KC_LPRN: */
    /*     return process_record_user_shifted_keycode(keycode, KC_4, record); */
    /* case KC_AMPR: */
    /*     return process_record_user_shifted_keycode(keycode, KC_5, record); */
    /* case KC_EQL: */
    /*     return process_record_user_shifted_keycode(keycode, KC_6, record); */
    /* case KC_RPRN: */
    /*     return process_record_user_shifted_keycode(keycode, KC_7, record); */
    /* case KC_RCBR: */
    /*     return process_record_user_shifted_keycode(keycode, KC_8, record); */
    /* case KC_RBRC: */
    /*     return process_record_user_shifted_keycode(keycode, KC_9, record); */
    /* case KC_ASTR: */
    /*     return process_record_user_shifted_keycode(keycode, KC_0, record); */
    /* case KC_EXLM: */
    /*     return process_record_user_shifted_keycode(keycode, KC_PERC, record); */
    /* case KC_BSLS: */
    /*     return process_record_user_shifted_keycode(keycode, KC_HASH, record); */
    /* case KC_AT: */
    /*     return process_record_user_shifted_keycode(keycode, KC_CIRC, record); */
    /* case KC_ESC: */
    /*     return process_record_user_shifted_keycode(keycode, KC_TILD, record); */
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

}
