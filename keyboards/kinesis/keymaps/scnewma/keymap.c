#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "oneshot.h"
#include "swapper.h"
#include "tap_hold.h"

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_kinesis_base( \
        K02, K03, K04, K05, K06,                    K07, K08, K09, K10, K11, \
        K14, K15, K16, K17, K18,                    K19, K20, K21, K22, K23, \
        K26, K27, K28, K29, K30,                    K31, K32, K33, K34, K35, \
                       K43, K44, K45,          K46, K47, K48 \
    ) \
    LAYOUT_wrapper( \
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8, \
        XXXXXXX, KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR, \
        ALFRED,  K02,     K03,     K04,     K05,     K06, \
        TPFX,    K14,     K15,     K16,     K17,     K18, \
        KC_COLN, K26,     K27,     K28,     K29,     K30, \
                 _______, _______, KC_LEFT, KC_RGHT, \
                                                       K45, OSL(_COMMANDS), \
                                                            KC_LCMD, \
                                                  K43, K44, KC_RCTL, \
        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, DF(_BASE), DF(_BASE2), DF(_QWERTY), \
        KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, XXXXXXX,  \
        K07,    K08,     K09,     K10,     K11,     KC_MINS,  \
        K19,    K20,     K21,     K22,     K23,     KC_UNDS,  \
        K31,    K32,     K33,     K34,     K35,     KC_SCLN,  \
                KC_UP,   KC_DOWN, _______, _______, \
                                                    XXXXXXX, K46, \
                                                             XXXXXXX, \
                                               XXXXXXX, K47, K48 \
    )
#define LAYOUT_kinesis_base_wrapper(...) LAYOUT_kinesis_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,
        KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,   KC_QUOT,  KC_COMM, KC_DOT,  KC_P,    KC_Y,
        C_ESC,    KC_A,     KC_O,    KC_E,    KC_U,    KC_I,
        XXXXXXX,  KC_SCLN,  KC_Q,    KC_J,    KC_K,    KC_X,
                  XXXXXXX,  XXXXXXX, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
                        KC_LGUI, OSL(_COMMANDS),
                                 KC_HYPR,
               KC_BSPC, KC_LSFT, MO(_RGX),

        KC_F9, KC_F10,  KC_F11,  KC_F12,  KC_PSCR, XXXXXXX,  DF(_BASE), DF(_BASE2), DF(_QWERTY),
        KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        KC_F,  KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_D,  KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        KC_B,  KC_M,    KC_W,    KC_V,    KC_Z,    XXXXXXX,
               KC_UP,  KC_DOWN,  XXXXXXX, XXXXXXX,
                        /* thumb cluster */
                        KC_LALT,  KC_RGUI,
                                  XXXXXXX,
              MO(_SYM), KC_ENTER, KC_SPC
),

[_BASE2] = LAYOUT_kinesis_base_wrapper(
        KC_DQUO, KC_COMM, KC_DOT, KC_P, KC_Y,                    KC_F, KC_G, KC_C, KC_R, KC_L,
        KC_A,    KC_O,    KC_E,   KC_U, KC_I,                    KC_D, KC_H, KC_T, KC_N, KC_S,
        KC_SLSH, KC_Q,    KC_J,   KC_K, KC_X,                    KC_B, KC_M, KC_W, KC_V, KC_Z,
                           KC_BSPC, LA_SFT, LA_CMD,     LA_SYM, LA_NUM, KC_SPC
),

// todo: 
// * need to configure upper-left thumb to point to RSYM layer
// * need to determine how to access L_CMD layer now. part of RSYM/RNUM layers?

[_SFT] = LAYOUT_kinesis_base_wrapper(
        KC_QUOT, S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),               S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L),
        S(KC_A), S(KC_O),    S(KC_E),   S(KC_U), S(KC_I),               S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S),
        KC_QUES, S(KC_Q),    S(KC_J),   S(KC_K), S(KC_X),               S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z),
                                      KC_BSPC, _______, LA_CMD,     LA_SYM, LA_NUM, KC_SPC
),

[_RNUM] = LAYOUT_kinesis_base_wrapper(
        KC_LBRC, KC_9, KC_8, KC_7, KC_RBRC,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN, KC_6, KC_5, KC_4, KC_EQL,                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_GRV,  KC_3, KC_2, KC_1, KC_BSLS,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        KC_0, KC_MINS, LA_CMD,        XXXXXXX, _______, XXXXXXX
),

[_RSYM] = LAYOUT_kinesis_base_wrapper(
        KC_LCBR, KC_LPRN, KC_ASTR, KC_AMPR, KC_RCBR,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_COLN, KC_CIRC, KC_PERC, KC_DLR,  KC_PLUS,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TILD, KC_HASH, KC_AT,   KC_EXLM, KC_PIPE,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                KC_RPRN, KC_UNDS, LA_CMD,   _______, XXXXXXX, XXXXXXX
),

[_CMD] = LAYOUT_kinesis_base_wrapper(
        XXXXXXX, SW_WIN,  XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, P_RASM,  P_RALG,  XXXXXXX, XXXXXXX,
        OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  TPFX,                  P_PEQL,  P_DCLN,  P_HBNG,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                XXXXXXX, XXXXXXX, _______,     XXXXXXX, XXXXXXX, XXXXXXX
),

[_SYM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_DOT,  KC_ASTR, KC_AMPR, KC_PLUS,
        XXXXXXX, KC_TILD, KC_QUES, KC_EXLM, KC_SLSH, KC_PIPE,
        XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_PERC, KC_AT,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        /* thumb cluster */
                           XXXXXXX, XXXXXXX,
                                    XXXXXXX,
                  XXXXXXX, KC_EQL,  KC_BSLS,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ASTR, KC_LBRC, KC_CIRC, KC_RBRC, XXXXXXX, XXXXXXX,
        KC_QUES, KC_LPRN, KC_DLR,  KC_RPRN, XXXXXXX, XXXXXXX,
        KC_PIPE, KC_LCBR, KC_HASH, KC_RCBR, XXXXXXX, XXXXXXX,
                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                        /* thumb cluster */
                           XXXXXXX, XXXXXXX,
                                    XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX
),

[_RGX] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,   XXXXXXX,
        XXXXXXX, KC_LCMD, KC_LOPT,     KC_LSFT, KC_LCTL,   XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, TO(_SYM2), XXXXXXX,
                 XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                        /* thumb cluster */
                           XXXXXXX, XXXXXXX,
                                    XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_ASTR, KC_LBRC, KC_CIRC, KC_RBRC, XXXXXXX, XXXXXXX,
        KC_QUES, KC_LPRN, KC_DLR,  KC_RPRN, XXXXXXX, XXXXXXX,
        KC_PIPE, KC_LCBR, KC_HASH, KC_RCBR, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        /* thumb cluster */
                           XXXXXXX, XXXXXXX,
                                    XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX
),

[_SYM2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LCMD, KC_LOPT,     KC_LSFT,  KC_LCTL, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,     TO(_RGX), XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX,     XXXXXXX,  XXXXXXX,
                        /* thumb cluster */
                           XXXXXXX, XXXXXXX,
                                    XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_PLUS, KC_AMPR, KC_ASTR, KC_DOT,  KC_EQL,  XXXXXXX,
        KC_PIPE, KC_SLSH, KC_EXLM, KC_QUES, XXXXXXX, XXXXXXX,
        KC_AT,   KC_PERC, KC_LT,   KC_GT,   KC_BSLS, XXXXXXX,
                 XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
                        /* thumb cluster */
                           XXXXXXX, XXXXXXX,
                                    XXXXXXX,
                  XXXXXXX, XXXXXXX, XXXXXXX
),

[_COMMANDS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CLIPSC,  PRNTSC,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        /* thumb cluster */
                         XXXXXXX, XXXXXXX,
                                  XXXXXXX,
                XXXXXXX, XXXXXXX, XXXXXXX,

        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, TMX_PRVW, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX,  XXXXXXX, RESET,
                        /* thumb cluster */
                         XXXXXXX, XXXXXXX,
                                  XXXXXXX,
                XXXXXXX, XXXXXXX, KC_NO
),
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

bool sw_win_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_tap_hold(keycode, record)) {
        return false;
    }

    update_swapper(&sw_win_active, KC_LGUI, KC_TAB, SW_WIN, keycode, record);

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

    case P_RASM:
        if (record->event.pressed) {
            send_string("->");
        }
        return false;

    case P_RALG:
        if (record->event.pressed) {
            send_string("=>");
        }
        return false;

    case P_DCLN:
        if (record->event.pressed) {
            send_string("::");
        }
        return false;

    case P_HBNG:
        if (record->event.pressed) {
            send_string("#!");
        }
        return false;

    case P_PEQL:
        if (record->event.pressed) {
            send_string("+=");
        }
        return false;

    default:
        return true;
    }
}

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_CMD:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_CMD:
    case LA_SFT:
    case LA_SYM:
    case LA_NUM:
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

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
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
        case KC_DQUO:
        case KC_QUOT:
            return true;
        default:
            return false;
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
        case KC_DQUO:
            tap_code16(KC_QUOT);
            return;
        case KC_QUOT:
            // send shifted symbols when held
            tap_code16(S(keycode));
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
