#include QMK_KEYBOARD_H

#define _BASE 0 // Base: Real Programmer's Dvorak
#define _SHIFTED 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
           KC_ESC,       KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_DLR,       KC_PLUS ,KC_LBRC ,KC_LCBR ,KC_LPRN ,KC_AMPR,
           KC_TAB,       KC_SCLN ,KC_COMM ,KC_DOT  ,KC_P    ,KC_Y   ,
           KC_ESC,       KC_A    ,KC_O    ,KC_E    ,KC_U    ,KC_I   ,
           MO(_SHIFTED), KC_QUOT ,KC_Q    ,KC_J    ,KC_K    ,KC_X   ,
                   KC_PIPE ,KC_BSLS ,KC_LEFT ,KC_RGHT,
			   KC_LGUI,KC_LALT,
                                    KC_HOME,
                           KC_BSPC,KC_LCTRL , _______,
    KC_F9  ,KC_F10  ,KC_F11  ,KC_F12  ,KC_PSCR ,KC_SLCK     ,KC_PAUS, KC_FN0, KC_1,
	KC_EQL ,KC_RPRN ,KC_RCBR ,KC_RBRC ,KC_ASTR ,KC_EXLM     ,
	KC_F   ,KC_G    ,KC_C    ,KC_R    ,KC_L    ,KC_SLSH     ,
	KC_D   ,KC_H    ,KC_T    ,KC_N    ,KC_S    ,KC_MINUS    ,
	KC_B   ,KC_M    ,KC_W    ,KC_V    ,KC_Z    ,MO(_SHIFTED),
		KC_UP  ,KC_DOWN ,KC_AT ,_______,
           KC_RCTL,KC_RGUI,
           _______,
           _______,KC_ENTER ,KC_SPC
),

[_SHIFTED] = LAYOUT(
           KC_NO,     KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO  ,KC_NO  ,KC_NO  ,KC_NO,
           KC_GRV,    KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5,
           S(KC_TAB), KC_COLN ,KC_LABK ,KC_RABK ,S(KC_P) ,S(KC_Y)   ,
           KC_ESC,    S(KC_A) ,S(KC_O) ,S(KC_E) ,S(KC_U) ,S(KC_I)   ,
           KC_TRNS,   KC_DQUO ,S(KC_Q) ,S(KC_J) ,S(KC_K) ,S(KC_X)   ,
                   KC_PIPE ,KC_HASH ,KC_TRNS ,KC_TRNS,
			   S(KC_LGUI),S(KC_LALT),
                                    KC_HYPR,
                           S(KC_BSPC),S(KC_LCTRL) , _______,
    KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO   ,KC_NO, KC_NO, KC_NO,
	KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_PERC ,
	S(KC_F) ,S(KC_G) ,S(KC_C) ,S(KC_R) ,S(KC_L) ,KC_QUES ,
	S(KC_D) ,S(KC_H) ,S(KC_T) ,S(KC_N) ,S(KC_S) ,KC_UNDS ,
	S(KC_B) ,S(KC_M) ,S(KC_W) ,S(KC_V) ,S(KC_Z) ,KC_TRNS ,
		KC_UP  ,KC_DOWN ,KC_CIRC , RESET,
           S(KC_RCTL),S(KC_RGUI),
           _______,
           _______,S(KC_ENTER) ,S(KC_SPC)
    )
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
