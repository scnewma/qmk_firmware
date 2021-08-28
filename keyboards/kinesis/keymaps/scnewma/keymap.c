#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "oneshot.h"
#include "tap_hold.h"

#define UPPER 1
#define STATE qk_tap_dance_state_t *state

#define TAPS (state->count > 1)

#define SHIFT(k) register_code(KC_LSFT); register_code(k)
#define UNSHIFT(k) unregister_code(k); unregister_code(KC_LSFT)

#define DANCE_TAP(s, u, k) if (TAPS) { send_string(s); } \
                           else if (u) { SHIFT(k); } \
                           else { register_code(k); } \
                           reset_tap_dance(state)

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

const uint16_t PROGMEM qj_combo[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(qj_combo, C(KC_U)),
    COMBO(jk_combo, C(KC_D)),
};

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_kinesis_base( \
        K01, K02, K03, K04, K05, K06,                    K07, K08, K09, K10, K11, K12, \
        K13, K14, K15, K16, K17, K18,                    K19, K20, K21, K22, K23, K24, \
        K25, K26, K27, K28, K29, K30,                    K31, K32, K33, K34, K35, K36, \
                                   K37, K38,      K39, K40, \
                                        K41,      K42, \
                              K43, K44, K45,      K46, K47, K48 \
    ) \
    LAYOUT_wrapper( \
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8, \
        KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, \
        K01,    K02,     K03,     K04,     K05,     K06, \
        K13,    K14,     K15,     K16,     K17,     K18, \
        K25,    K26,     K27,     K28,     K29,     K30, \
                KC_TRNS, KC_TRNS, KC_LEFT, KC_RGHT, \
                                                       K37, K38, \
                                                            K41, \
                                                  K43, K44, K45, \
        KC_F9, KC_F10, KC_F11,   KC_F12,  KC_PSCR, KC_SLCK, DF(_BASE), DF(_CBASE), DF(_QWERTY), \
        KC_NO, KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO, \
        K07,   K08,    K09,      K10,     K11,     K12, \
        K19,   K20,    K21,      K22,     K23,     K24, \
        K31,   K32,    K33,      K34,     K35,     K36, \
               KC_UP,  KC_DOWN,  KC_TRNS, KC_TRNS, \
                                                      K39, K40, \
                                                           K42, \
                                                 K46, K47, K48 \
    )
#define LAYOUT_kinesis_base_wrapper(...) LAYOUT_kinesis_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,
        C_ESC,    KC_A,     KC_O,    KC_E,    KC_U,    KC_I,
        KC_NO,    KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,
                  _______,  _______, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI, OSL(_COMMANDS),
                                 KC_HYPR,
               KC_BSPC, KC_LSFT, MO(_RGX),

        KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, _______,  DF(_BASE), DF(_BASE2), DF(_QWERTY),
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

[_BASE2] = LAYOUT_kinesis_base_wrapper(
        KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y,                    KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
        KC_ESC, KC_A,    KC_O,    KC_E,   KC_U, KC_I,                    KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS,
        KC_NO,  KC_SCLN, KC_Q,    KC_J,   KC_K, KC_X,                    KC_B, KC_M, KC_W, KC_V, KC_Z, KC_NO,
                                             KC_LGUI, _CMDS,         KC_LALT, KC_RGUI,
                                                      KC_HYPR,       KC_NO,
                          LT(_SFT, KC_BSPC), L_NUM,   KC_NO,         MO(_SYM), KC_ENTER, KC_SPC
),

[_SFT] = LAYOUT_kinesis_base_wrapper(
        KC_TAB, KC_DQUO,    KC_GRV,  KC_TILD, S(KC_P), S(KC_Y),               S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), S(KC_SLSH),
        KC_ESC, S(KC_A),    S(KC_O), S(KC_E), S(KC_U), S(KC_I),               S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), S(KC_MINUS),
        KC_NO,  S(KC_SCLN), S(KC_Q), S(KC_J), S(KC_K), S(KC_X),               S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), KC_NO,
                                                 KC_LGUI, _CMDS,         KC_LALT, KC_RGUI,
                                                          KC_HYPR,       KC_NO,
                                 SFT_T(KC_BSPC), L_NUM,   KC_NO,         MO(_SYM), KC_ENTER, KC_SPC
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
        KC_NO, KC_TILD,   KC_QUES, KC_EXLM, KC_SLSH, KC_PIPE,
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
        KC_NO, KC_NO,   KC_NO,       KC_NO,   KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,       KC_NO,   KC_NO,     KC_NO,
        KC_NO, KC_NO,   KC_NO,       KC_NO,   KC_NO,     KC_NO,
        KC_NO, KC_LCMD, KC_LOPT,     KC_LSFT, KC_LCTL,   KC_NO,
        KC_NO, KC_NO,   TO(_KEYPAD), KC_NO,   TO(_SYM2), KC_NO,
               KC_NO,   KC_NO,       KC_NO,   KC_NO,
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
        KC_NO, KC_NO,   KC_NO,       KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,       KC_NO,    KC_NO,   KC_NO,
        KC_NO, KC_NO,   KC_NO,       KC_NO,    KC_NO,   KC_NO,
        KC_NO, KC_LCMD, KC_LOPT,     KC_LSFT,  KC_LCTL, KC_NO,
        KC_NO, KC_NO,   TO(_KEYPAD), TO(_RGX), KC_NO,   KC_NO,
               KC_NO,   KC_NO,       KC_NO,    KC_NO,
                        /* thumb cluster */
                           _______, _______,
                                    _______,
                  _______, _______, _______,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_PLUS, KC_AMPR, KC_ASTR, KC_DOT,  KC_EQL,  KC_NO,
        KC_PIPE, KC_SLSH, KC_EXLM, KC_QUES, KC_NO,   KC_NO,
        KC_AT,   KC_PERC, TD(_LT), TD(_GT), KC_BSLS, KC_NO,
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
        KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO,
        KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO,
        KC_NO, OS_SHFT, OS_ALT,  OS_CTRL,  OS_CMD,   KC_NO,
        KC_NO, KC_NO,   KC_NO,   TO(_RGX), TO(_SYM2), KC_NO,
                 KC_NO, KC_NO,   KC_NO,    KC_NO,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, _______,

           // Right Hand
        _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_PEQL, KC_PSLS, KC_PAST, _______,
        _______, KC_7,    KC_8,    KC_9,   KC_PMNS, _______,
        _______, KC_4,    KC_5,    KC_6,   KC_PPLS, _______,
        _______, KC_1,    KC_2,    KC_3,   KC_PENT, _______,
                 _______, _______, KC_PDOT, KC_PENT,
                        /* thumb cluster */
                        _______, _______,
                                 _______,
               _______, _______, KC_0
)
};

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

static uint16_t key_timer;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold(keycode, record)) {
        return false;
    }

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LCMD, OS_CMD, keycode, record);

    switch (keycode) {
    case TMX_PRVW:
        if (record->event.pressed) {
            // send tmux leader twice, which i use to switch to previous window
            tap_code16(C(KC_SPC));
            tap_code16(C(KC_SPC));
        }
        return false;
        break;

    case L_NUM:
        if (record->event.pressed) {
            key_timer = timer_read();
            layer_on(_KEYPAD);
        } else {
            layer_off(_KEYPAD);
            layer_off(_RGX);
            layer_off(_SYM2);
        }
        return false;
        break;

    default:
        return true;
    }
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case L_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case L_NUM:
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

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    /* register_key_to_repeat(keycode); */
}

bool tap_hold(uint16_t keycode) {
    switch (keycode) {
        case KC_QUOT:
        case KC_DQUO:
        case KC_GRV:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
        case KC_QUOT:
        case KC_DQUO:
        case KC_GRV:
            triple_tap(keycode);
            return;
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        default:
            tap16_repeatable(keycode);
    }
}

uint16_t tap_hold_timeout(uint16_t keycode) {
    return 175;
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}
