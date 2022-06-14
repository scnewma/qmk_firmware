#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SFT,
    _COMMANDS,
};

#define CLIPSC G(S(C(KC_4)))        // Cmd-Shift-Ctrl-4 -> macOS Screenshot (clipboard)
#define PRNTSC G(S(KC_4))           // Cmd-Shift-4 -> macOS Screenshot
#define TPFX C(KC_SPC)              // tmux prefix
#define LA_CMD LGUI_T(KC_TAB)
#define LA_SFT LT(_SFT, KC_ESC)

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_kinesis_base( \
        T01, T02, T03, T04, T05, T06,                    T07, T08, T09, T10, T11, T12, \
        K01, K02, K03, K04, K05, K06,                    K07, K08, K09, K10, K11, K12, \
        K13, K14, K15, K16, K17, K18,                    K19, K20, K21, K22, K23, K24, \
        K25, K26, K27, K28, K29, K30,                    K31, K32, K33, K34, K35, K36, \
                       K43, K44, K45,          K46, K47, K48 \
    ) \
    LAYOUT_wrapper( \
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_F6, KC_F7, KC_F8, \
        T01,     T02,     T03,     T04,     T05,     T06, \
        K01,     K02,     K03,     K04,     K05,     K06, \
        K13,     K14,     K15,     K16,     K17,     K18, \
        K25,     K26,     K27,     K28,     K29,     K30, \
                 _______, _______, KC_LEFT, KC_RGHT, \
                                                       K45, OSL(_COMMANDS), \
                                                            KC_HYPR, \
                                                  K43, K44, KC_RCTL, \
        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, DF(_BASE), KC_NO, KC_NO, \
        T07,    T08,     T09,     T10,     T11,     T12,  \
        K07,    K08,     K09,     K10,     K11,     K12,  \
        K19,    K20,     K21,     K22,     K23,     K24,  \
        K31,    K32,     K33,     K34,     K35,     K36,  \
                KC_UP,   KC_DOWN, _______, _______, \
                                                    XXXXXXX, K46, \
                                                             XXXXXXX, \
                                               KC_LALT, K47, K48 \
    )
#define LAYOUT_kinesis_base_wrapper(...) LAYOUT_kinesis_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT_kinesis_base_wrapper(
        KC_DLR,  KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,                 KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
        KC_TAB,  KC_DQUO, KC_COMM, KC_DOT,  KC_P,    KC_Y,                    KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_PIPE,
        TPFX,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                    KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
        KC_COLN, KC_SLSH, KC_Q,    KC_J,    KC_K,    KC_X,                    KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    KC_SCLN,
                                          KC_BSPC, LA_SFT, LA_CMD,     KC_BSLS, KC_ENTER, KC_SPC
),

[_SFT] = LAYOUT_kinesis_base_wrapper(
        KC_TILD,   KC_1,    KC_2,       KC_3,      KC_4,    KC_5,                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PERC,
        S(KC_TAB), KC_QUOT, S(KC_COMM), S(KC_DOT), S(KC_P), S(KC_Y),               S(KC_F), S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_GRV,
        TPFX,      S(KC_A), S(KC_O),    S(KC_E),   S(KC_U), S(KC_I),               S(KC_D), S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS,
        KC_AT,     KC_QUES, S(KC_Q),    S(KC_J),   S(KC_K), S(KC_X),               S(KC_B), S(KC_M), S(KC_W), S(KC_V), S(KC_Z), KC_CIRC,
                                      KC_BSPC, _______, LA_CMD,        KC_HASH, S(KC_ENTER), KC_SPC
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

        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 XXXXXXX, XXXXXXX, XXXXXXX, RESET,
                        /* thumb cluster */
                         XXXXXXX, XXXXXXX,
                                  XXXXXXX,
                XXXXXXX, XXXXXXX, A(KC_SPC)
),
};
