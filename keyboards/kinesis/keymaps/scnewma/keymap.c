#include QMK_KEYBOARD_H

#define _BASE 0 
#define _SHIFTED 1
#define _CBASE 2
#define _CSFT 3
#define _COMMANDS 4

//  TODO: 
//    CLIPSC and PRNTSC might be better combined onto one key using tap dance.
//    PRNTSC would be the tap command and CLIPSC would be the hold command.
#define CLIPSC G(S(C(KC_4)))        // Cmd-Shift-Ctrl-4 -> macOS Screenshot (clipboard)
#define PRNTSC G(S(KC_4))           // Cmd-Shift-4 -> macOS Screenshot
#define OPTBS  A(KC_BSPC)           // macOS backspace one word

enum custom_keycodes {
    TMX_PRVW = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// Real Programmer's Dvorak
[_BASE] = LAYOUT(
        KC_ESC,       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_DLR,       KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,
        KC_TAB,       KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,
        KC_ESC,       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,
        MO(_SHIFTED), KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,
                      KC_PIPE, KC_BSLS, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
			           KC_LGUI,  KC_LALT,
                                 KC_HYPR,
              KC_BSPC, KC_LCTRL, OSL(_COMMANDS),

        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK,      DF(_BASE), DF(_CBASE), KC_NO,
        KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
        KC_F,   KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH,
        KC_D,   KC_H,    KC_T,    KC_N,    KC_S,    KC_MINUS,
        KC_B,   KC_M,    KC_W,    KC_V,    KC_Z,    MO(_SHIFTED),
                KC_UP,  KC_DOWN, KC_AT,   _______,
                        /* thumb cluster */
                       KC_RCTL,  KC_RGUI,
                                 _______,
              _______, KC_ENTER, KC_SPC
),

// Shift Layer for Real Programmer's Dvorak
[_SHIFTED] = LAYOUT(
        KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        S(KC_TAB), KC_COLN, KC_LABK, KC_RABK, S(KC_P), S(KC_Y),
        KC_TILD,   S(KC_A), S(KC_O), S(KC_E), S(KC_U), S(KC_I),
        KC_TRNS,   KC_DQUO, S(KC_Q), S(KC_J), S(KC_K), S(KC_X),
                   KC_PIPE ,KC_HASH ,KC_TRNS ,KC_TRNS,
                        /* thumb cluster */
			            S(KC_LGUI),  S(KC_LALT),
                                     KC_HYPR,
            S(KC_BSPC), S(KC_LCTRL), _______,

        KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
        KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_PERC,
        S(KC_F),   S(KC_G), S(KC_C), S(KC_R), S(KC_L), KC_QUES,
        S(KC_D),   S(KC_H), S(KC_T), S(KC_N), S(KC_S), KC_UNDS,
        S(KC_B),   S(KC_M), S(KC_W), S(KC_V), S(KC_Z), KC_TRNS,
                   KC_UP,   KC_DOWN, KC_CIRC, KC_NO,
                        /* thumb cluster */
                       S(KC_RCTL),  S(KC_RGUI),
                                    _______,
              _______, S(KC_ENTER), S(KC_SPC)
),

// Real Programmer's Colemak DHm
// Adds the symbol/number layout of RPD to Colemak DHm
[_CBASE] = LAYOUT(
        KC_ESC,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_F7, KC_F8,
        KC_DLR,    KC_PLUS, KC_LBRC, KC_LCBR, KC_LPRN, KC_AMPR,
        KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,
        KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
        MO(_CSFT), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
                   KC_PIPE, KC_BSLS, KC_LEFT, KC_RGHT,
                        /* thumb cluster */
			           KC_LGUI,  KC_LALT,
                                 KC_HYPR,
              KC_BSPC, KC_LCTRL, OSL(_COMMANDS),

        KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK,   DF(_BASE), DF(_CBASE), KC_NO,
        KC_EQL, KC_RPRN, KC_RCBR, KC_RBRC, KC_ASTR, KC_EXLM,
        KC_J,   KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_MINUS,
        KC_M,   KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_K,   KC_H,    KC_COMM, KC_DOT,  KC_SLSH, MO(_CSFT),
                KC_UP,   KC_DOWN, KC_AT,   _______,
                        /* thumb cluster */
                       KC_RCTL,  KC_RGUI,
                                 _______,
              _______, KC_ENTER, KC_SPC
),

// Shift Layer for Real Programmer's Colemak DHm
[_CSFT] = LAYOUT(
        KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
        KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        S(KC_TAB), S(KC_Q), S(KC_W), S(KC_F), S(KC_P), S(KC_B),
        KC_TILD,   S(KC_A), S(KC_R), S(KC_S), S(KC_T), S(KC_G),
        KC_TRNS,   S(KC_Z), S(KC_X), S(KC_C), S(KC_D), S(KC_V),
                   KC_PIPE ,KC_HASH ,KC_TRNS ,KC_TRNS,
                        /* thumb cluster */
			            S(KC_LGUI),  S(KC_LALT),
                                     KC_HYPR,
            S(KC_BSPC), S(KC_LCTRL), _______,

        KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
        KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_PERC,
        S(KC_J),   S(KC_L), S(KC_U), S(KC_Y), KC_COLN, KC_UNDS,
        S(KC_M),   S(KC_N), S(KC_E), S(KC_I), S(KC_O), KC_DQUO,
        S(KC_K),   S(KC_H), KC_LABK, KC_RABK, KC_QUES, KC_TRNS,
                   KC_UP,   KC_DOWN, KC_CIRC, KC_NO,
                        /* thumb cluster */
                       S(KC_RCTL),  S(KC_RGUI),
                                    _______,
              _______, S(KC_ENTER), S(KC_SPC)
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
        OPTBS, KC_NO, TMX_PRVW, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO,
               KC_NO, KC_NO,    KC_NO, RESET,
                        /* thumb cluster */
                       KC_NO, KC_NO,
                              KC_NO,
                KC_NO, KC_NO, KC_NO
)
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

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
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

}
