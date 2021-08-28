#include QMK_KEYBOARD_H

#define _BASE 0
#define _CBASE 2
#define _QWERTY 3
#define _RGX 4
#define _SYM 5
#define _COMMANDS 6
#define _KEYPAD 7
#define _BASE2 8
#define _SYM2 9

//  TODO:
//    CLIPSC and PRNTSC might be better combined onto one key using tap dance.
//    PRNTSC would be the tap command and CLIPSC would be the hold command.
#define CLIPSC G(S(C(KC_4)))        // Cmd-Shift-Ctrl-4 -> macOS Screenshot (clipboard)
#define PRNTSC G(S(KC_4))           // Cmd-Shift-4 -> macOS Screenshot
#define _CESC CTL_T(KC_ESC)        // control when held, escape when tapped

#define UPPER 1
#define STATE qk_tap_dance_state_t *state

#define TAPS (state->count > 1)

#define SHIFT(k) register_code(KC_LSFT); register_code(k)
#define UNSHIFT(k) unregister_code(k); unregister_code(KC_LSFT)

#define DANCE_TAP(s, u, k) if (TAPS) { send_string(s); } \
                           else if (u) { SHIFT(k); } \
                           else { register_code(k); } \
                           reset_tap_dance(state)

enum custom_keycodes {
    TMX_PRVW = SAFE_RANGE,
    /* LYR_BASE, */
    /* RGXL */
};

void greater(STATE, void *user_data) {
    DANCE_TAP(" -> ", UPPER, KC_DOT);
}

void greater_reset(STATE, void *user_data) {
    UNSHIFT(KC_DOT);
}

void lesser(STATE, void *user_data) {
    DANCE_TAP(" <- ", UPPER, KC_COMM);
}

void lesser_reset(STATE, void *user_data) {
    UNSHIFT(KC_COMM);
}

void tilde(STATE, void *user_data) {
    DANCE_TAP("~/", UPPER, KC_GRV);
}

void tilde_reset(STATE, void *user_data) {
    UNSHIFT(KC_GRV);
}

// tap dance declarations
enum {
    _GT,
    _LT,
    _TILD,
};

// tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // send `>` on single tap, ` -> ` on double tap
    [_GT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, greater, greater_reset),
    // send `<` on single tap, ` <- ` on double tap
    [_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lesser, lesser_reset),
    // send `~` on single tap, `~/` on double tap
    [_TILD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tilde, tilde_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,
        _CESC,    KC_A,     KC_O,    KC_E,    KC_U,    KC_I,
        KC_NO,    KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,
                  _______,  _______, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI, OSL(_COMMANDS),
                                 KC_HYPR,
               KC_BSPC, KC_LSFT, MO(_RGX),

        KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, DF(_BASE2),  DF(_BASE), DF(_CBASE), DF(_QWERTY),
        KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_F,  KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_D,  KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,    _______,
               KC_UP,  KC_DOWN,  _______, _______,
                        /* thumb cluster */
                        KC_LALT,  KC_RGUI,
                                  _______,
              MO(_SYM), KC_ENTER, KC_SPC
),

[_BASE2] = LAYOUT(
        KC_ESC,   KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,
        _CESC,    KC_A,     KC_O,    KC_E,    KC_U,    KC_I,
        KC_NO,    KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,
                  _______,  _______, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI, OSL(_COMMANDS),
                                 KC_HYPR,
              _______, KC_LSFT, MO(_RGX),

        KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK,  DF(_BASE), DF(_CBASE), DF(_QWERTY),
        KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_F,  KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_D,  KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,    _______,
               KC_UP,  KC_DOWN,  _______, _______,
                        /* thumb cluster */
                        KC_LALT,  KC_RGUI,
                                  _______,
              MO(_SYM), KC_ENTER, KC_SPC
),

[_CBASE] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,
        KC_ESC,   KC_A,    KC_R,    KC_S,    KC_T,    KC_D,
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                   KC_PIPE, KC_BSLS, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI, OSL(_COMMANDS),
                                 KC_HYPR,
               KC_BSPC, KC_LSFT, KC_LCTL,

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

[_SYM] = LAYOUT(
        KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO,     KC_DOT,  KC_ASTR, KC_AMPR, KC_PLUS,
        KC_NO, TD(_TILD), KC_QUES, KC_EXLM, KC_SLSH, KC_PIPE,
        KC_NO, KC_NO,     TD(_LT), TD(_GT), KC_PERC, KC_AT,
               KC_NO,     KC_NO,   KC_NO,   KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, KC_EQL,  KC_BSLS,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_ASTR, KC_LBRC, KC_CIRC, KC_RBRC, KC_NO, KC_NO,
        KC_QUES, KC_LPRN, KC_DLR,  KC_RPRN, KC_NO, KC_NO,
        KC_PIPE, KC_LCBR, KC_HASH, KC_RCBR, KC_NO, KC_NO,
               KC_NO,   KC_NO,   KC_NO,   KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, _______, _______
),

[_RGX] = LAYOUT(
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO, KC_NO,   KC_NO,   KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, _______, _______,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_ASTR, KC_LBRC, KC_CIRC, KC_RBRC, KC_NO, KC_NO,
        KC_QUES, KC_LPRN, KC_DLR,  KC_RPRN, KC_NO, KC_NO,
        KC_PIPE, KC_LCBR, KC_HASH, KC_RCBR, KC_NO, KC_NO,
               KC_NO,   KC_NO,   KC_NO,   KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, _______, _______
),

[_SYM2] = LAYOUT(
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
               KC_NO, KC_NO,   KC_NO,   KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, _______, _______,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
        KC_PLUS, KC_AMPR, KC_ASTR, KC_DOT,  KC_NO, KC_NO,
        KC_PIPE, KC_BSLS, KC_EXLM, KC_QUES, KC_NO, KC_NO,
        KC_AT,   KC_PERC, TD(_LT), TD(_GT), KC_NO, KC_NO,
               KC_NO,   KC_NO,   KC_NO,   KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, _______, _______
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
        return false;
        break;

    /* case LYR_BASE: */
    /*     /1* if (record->event.pressed) { *1/ */
    /*     /1*     layer_on(_RGX); *1/ */
    /*     /1* } else { *1/ */
    /*     /1*     layer_off(_RGX); *1/ */
    /*     /1* } *1/ */
    /*     return false; */
    /*     break; */

    default:
        return true;
    }
}

void led_set_user(uint8_t usb_led) {

}
