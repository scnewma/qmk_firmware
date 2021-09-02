#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "oneshot.h"
#include "swapper.h"
#include "tap_hold.h"

enum combo_events {
    CTL_U_COMBO,
    CTL_D_COMBO,
    CTL_Z_COMBO,
    ESC_COMBO,
    TAB_COMBO,
    Q_COMBO,
    CAP_Q_COMBO,
    SM_ARROW_LEFT_COMBO,
    SM_ARROW_RIGHT_COMBO,
    LG_ARROW_RIGHT_COMBO,
    EX_PIPE_COMBO,
    /* LPRN_COMBO, */
    /* RPRN_COMBO, */
    /* LBRC_COMBO, */
    /* RBRC_COMBO, */
    /* LCBR_COMBO, */
    /* RCBR_COMBO, */
    /* EQL_COMBO, */
    SLSH_COMBO,
};

const uint16_t PROGMEM ctl_u_combo[] = {KC_UNDS, KC_J, COMBO_END};
const uint16_t PROGMEM ctl_d_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ctl_z_combo[] = {KC_K, KC_X, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM sm_arrow_left_combo[] = {KC_T, KC_W, COMBO_END};
const uint16_t PROGMEM sm_arrow_right_combo[] = {KC_N, KC_V, COMBO_END};
const uint16_t PROGMEM lg_arrow_right_combo[] = {KC_T, KC_C, COMBO_END};
const uint16_t PROGMEM ex_pipe_combo[] = {KC_N, KC_R, COMBO_END};
const uint16_t PROGMEM q_combo[] = {KC_SCLN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM cap_q_combo[] = {KC_COLN, KC_MINS, COMBO_END};
/* const uint16_t PROGMEM lprn_combo[] = {KC_H, KC_T, COMBO_END}; */
/* const uint16_t PROGMEM rprn_combo[] = {KC_T, KC_N, COMBO_END}; */
/* const uint16_t PROGMEM lbrc_combo[] = {KC_G, KC_C, COMBO_END}; */
/* const uint16_t PROGMEM rbrc_combo[] = {KC_C, KC_R, COMBO_END}; */
/* const uint16_t PROGMEM lcbr_combo[] = {KC_M, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM rcbr_combo[] = {KC_W, KC_V, COMBO_END}; */
/* const uint16_t PROGMEM eql_combo[] = {KC_R, KC_L, COMBO_END}; */
const uint16_t PROGMEM slsh_combo[] = {KC_H, KC_T, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [CTL_U_COMBO] = COMBO_ACTION(ctl_u_combo),
    [CTL_D_COMBO] = COMBO_ACTION(ctl_d_combo),
    [CTL_Z_COMBO] = COMBO_ACTION(ctl_z_combo),
    [ESC_COMBO] = COMBO_ACTION(esc_combo),
    [TAB_COMBO] = COMBO_ACTION(tab_combo),
    [Q_COMBO] = COMBO_ACTION(q_combo),
    [CAP_Q_COMBO] = COMBO_ACTION(cap_q_combo),
    [SM_ARROW_LEFT_COMBO] = COMBO_ACTION(sm_arrow_left_combo),
    [SM_ARROW_RIGHT_COMBO] = COMBO_ACTION(sm_arrow_right_combo),
    [LG_ARROW_RIGHT_COMBO] = COMBO_ACTION(lg_arrow_right_combo),
    [EX_PIPE_COMBO] = COMBO_ACTION(ex_pipe_combo),
    /* [LPRN_COMBO] = COMBO_ACTION(lprn_combo), */
    /* [RPRN_COMBO] = COMBO_ACTION(rprn_combo), */
    /* [LBRC_COMBO] = COMBO_ACTION(lbrc_combo), */
    /* [RBRC_COMBO] = COMBO_ACTION(rbrc_combo), */
    /* [LCBR_COMBO] = COMBO_ACTION(lcbr_combo), */
    /* [RCBR_COMBO] = COMBO_ACTION(rcbr_combo), */
    /* [EQL_COMBO] = COMBO_ACTION(eql_combo), */
    [SLSH_COMBO] = COMBO_ACTION(slsh_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case SM_ARROW_LEFT_COMBO:
            if (pressed) {
                send_string("<-");
            }
            break;
        case SM_ARROW_RIGHT_COMBO:
            if (pressed) {
                send_string("->");
            }
            break;
        case LG_ARROW_RIGHT_COMBO:
            if (pressed) {
                send_string("=>");
            }
            break;
        case EX_PIPE_COMBO:
            if (pressed) {
                send_string("|>");
            }
            break;
        case CTL_U_COMBO:
            if (pressed) {
                tap_code16(C(KC_U));
            }
            break;
        case CTL_D_COMBO:
            if (pressed) {
                tap_code16(C(KC_D));
            }
            break;
        case CTL_Z_COMBO:
            if (pressed) {
                tap_code16(C(KC_Z));
            }
            break;
        case ESC_COMBO:
            if (pressed) {
                tap_code16(KC_ESC);
            }
            break;
        case TAB_COMBO:
            if (pressed) {
                tap_code16(KC_TAB);
            }
            break;
        case Q_COMBO:
            if (pressed) {
                tap_code16(KC_Q);
            }
            break;
        case CAP_Q_COMBO:
            if (pressed) {
                tap_code16(S(KC_Q));
            }
            break;
        /* case LPRN_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LPRN); */
        /*     } */
        /*     break; */
        /* case RPRN_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_RPRN); */
        /*     } */
        /*     break; */
        /* case LBRC_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LBRC); */
        /*     } */
        /*     break; */
        /* case RBRC_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_RBRC); */
        /*     } */
        /*     break; */
        /* case LCBR_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_LCBR); */
        /*     } */
        /*     break; */
        /* case RCBR_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_RCBR); */
        /*     } */
        /*     break; */
        /* case EQL_COMBO: */
        /*     if (pressed) { */
        /*         tap_code16(KC_EQL); */
        /*     } */
        /*     break; */
        case SLSH_COMBO:
            if (pressed) {
                tap_code16(KC_SLSH);
            }
            break;
    }
}

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_kinesis_base( \
        K02, K03, K04, K05, K06,                    K07, K08, K09, K10, K11, \
        K14, K15, K16, K17, K18,                    K19, K20, K21, K22, K23, \
        K26, K27, K28, K29, K30,                    K31, K32, K33, K34, K35, \
                            K43, K44,          K47, K48 \
    ) \
    LAYOUT_wrapper( \
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, K02,     K03,     K04,     K05,     K06, \
        XXXXXXX, K14,     K15,     K16,     K17,     K18, \
        XXXXXXX, K26,     K27,     K28,     K29,     K30, \
                 _______, _______, KC_LEFT, KC_RGHT, \
                                                     XXXXXXX, OSL(_COMMANDS), \
                                                              XXXXXXX, \
                                                  K43, K44,   XXXXXXX, \
        KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_PSCR,  KC_SLCK, DF(_BASE), DF(_BASE2), DF(_QWERTY), \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        K07,     K08,    K09,      K10,     K11,     XXXXXXX, \
        K19,     K20,    K21,      K22,     K23,     XXXXXXX, \
        K31,     K32,    K33,      K34,     K35,     XXXXXXX, \
                 KC_UP,  KC_DOWN,  _______, _______, \
                                                    XXXXXXX, XXXXXXX, \
                                                             XXXXXXX, \
                                               XXXXXXX, K47,   K48 \
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
        KC_SCLN, KC_UNDS, KC_J,   KC_K, KC_X,                    KC_B, KC_M, KC_W, KC_V, KC_Z,
                          LT(_SFT, KC_BSPC), L_NUM,        LT(_LRGX, KC_ENTER), KC_SPC
),

[_SFT] = LAYOUT_kinesis_base_wrapper(
        KC_QUOT,    KC_GRV,  KC_TILD, S(KC_P), S(KC_Y),               S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L),
        S(KC_A),    S(KC_O), S(KC_E), S(KC_U), S(KC_I),               S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S),
        S(KC_SCLN), KC_MINS, S(KC_J), S(KC_K), S(KC_X),               S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z),
                                            _______, L_NUM,       KC_ENTER, KC_SPC
),

// + = ? / \ |
// /
[_LRGX] = LAYOUT_kinesis_base_wrapper(
        XXXXXXX, KC_QUES, KC_LBRC, KC_RBRC, KC_PLUS,               XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
        KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_PIPE,               XXXXXXX, OS_CMD,   OS_CTRL,   OS_ALT,   OS_SHFT,
        XXXXXXX, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS,               XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,
                                           KC_BSPC, L_NUM,     _______, XXXXXXX
),

[_RNUM] = LAYOUT_kinesis_base_wrapper(
        XXXXXXX, SW_WIN,  XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX,
        OS_SHFT, OS_ALT,  OS_CTRL, OS_CMD,  TPFX,                  XXXXXXX, KC_4, KC_5, KC_6, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, KC_1, KC_2, KC_3, XXXXXXX,
                                       XXXXXXX, _______,     LT(_LRGX, KC_ENTER), KC_0
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

static uint16_t key_timer;

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

    case L_NUM:
        if (record->event.pressed) {
            key_timer = timer_read();
            /* layer_on(_KEYPAD); */
            layer_on(_RNUM);
        } else {
            layer_off(_RNUM);
            /* layer_off(_KEYPAD); */
            /* layer_off(_RGX); */
            /* layer_off(_SYM2); */
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
        case KC_QUOT:
        case KC_DQUO:
        case KC_GRV:
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9:
        case KC_0:
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
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9:
        case KC_0:
            // send symbols when numbers are held
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
