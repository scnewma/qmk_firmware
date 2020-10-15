/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _SYMBOLS 1
#define _NUMBERS 2
#define _NAV 3

#define _JBASE 4
#define _JNUM 5
#define _JSYM 6
#define _JFN 7

#define _LAYERS 8

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Workman
[_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,         KC_Q,    KC_D,    KC_R,              KC_W,    KC_B,         KC_J,         KC_F,   KC_U,    KC_P,    KC_SCLN, KC_MINS,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_H,              KC_T,    KC_G,         KC_Y,         KC_N,   KC_E,    KC_O,    KC_I,    KC_QUOT,
    KC_LSFT,        KC_Z,    KC_X,    KC_M,              KC_C,    KC_V,         KC_K,         KC_L,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_NO,          KC_LALT, KC_LGUI, LT(_NAV, KC_BSPC), KC_LSFT, MO(_SYMBOLS), MO(_NUMBERS), KC_SPC, KC_ENT,  KC_RGUI, KC_RALT, KC_NO
),

// Symbols
[_SYMBOLS] = LAYOUT_ortho_4x12(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,     KC_AMPR,     KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_UNDS,     KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      S(KC_NUHS),  S(KC_NUBS), KC_HOME, KC_END,  KC_TRNS,
    RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(_LAYERS), KC_TRNS,     KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

// Numbers
[_NUMBERS] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,       KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,      KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS,
    RGB_TOG, RGB_MOD, BL_INC,  BL_DEC, KC_TRNS, MO(_LAYERS), KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

// Navigation
[_NAV] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO, KC_NO,         LALT(KC_BSPC), LALT(KC_DEL), KC_NO, KC_NO,         LALT(KC_LEFT), KC_UP,   LALT(KC_RIGHT), KC_NO,          KC_NO,
    KC_NO, KC_NO, LGUI(KC_BSPC), KC_BSPC,       KC_DEL,       KC_NO, LGUI(KC_LEFT), KC_LEFT,       KC_DOWN, KC_RIGHT,       LGUI(KC_RIGHT), KC_NO,
    KC_NO, KC_NO, KC_NO,         KC_NO,         KC_NO,        KC_NO, KC_NO,         KC_PGUP,       KC_PGDN, KC_NO,          KC_NO,          KC_NO,
    KC_NO, KC_NO, KC_NO,         KC_NO,         KC_NO,        KC_NO, KC_NO,         KC_NO,         KC_NO,   KC_NO,          KC_NO,          KC_NO
),

// Jamie Base
[_JBASE] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,    KC_P,         KC_Y,    KC_F,   KC_G,         KC_C,     KC_R,    KC_L,    KC_DEL,
    KC_TAB,  KC_A,    KC_O,    KC_E,      LSFT_T(KC_U), KC_I,    KC_D,   RSFT_T(KC_H), KC_T,     KC_N,    KC_S,    KC_QUES,
    KC_NO,   KC_SCLN, KC_Q,    KC_J,      KC_K,         KC_X,    KC_B,   KC_M,         KC_W,     KC_V,    KC_Z,    KC_UP,
    KC_LCTL, KC_LALT, KC_LGUI, MO(_JSYM), MO(_JNUM),    KC_BSPC, KC_SPC, KC_ENT,       MO(_JFN), KC_LEFT, KC_DOWN, KC_RIGHT
),

// Jamie Numbers
[_JNUM] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_PPLS, KC_7, KC_8,    KC_9,  KC_PAST,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_PMNS, KC_4, KC_5,    KC_6,  KC_PSLS,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_PEQL, KC_1, KC_2,    KC_3,  KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT,  KC_0, KC_PDOT, KC_NO, KC_NO
),

// Jamie Symbols
[_JSYM] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_GRV,  KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_BSLS, KC_DLR,  KC_PERC, KC_CIRC, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,   KC_LBRC, KC_RBRC, KC_EXLM, KC_AT,   KC_HASH, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO
),

// Jamie Function
[_JFN] = LAYOUT_ortho_4x12(
    KC_NO, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_NO,   KC_NO,   KC_NO,   MO(_LAYERS), KC_NO, KC_NO, KC_NO,
    KC_NO, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_NO, KC_NO, KC_NO
),

// Layer Switching
[_LAYERS] = LAYOUT_ortho_4x12(
    KC_NO, KC_NO,     KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,
    KC_NO, DF(_BASE), DF(_JBASE), KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,     KC_NO,      KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO,     KC_NO,      KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO
),

};
