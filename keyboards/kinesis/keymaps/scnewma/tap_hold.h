// from: https://github.com/treeman/qmk_firmware/blob/master/keyboards/kyria/keymaps/treeman/tap_hold.h
#pragma once

#include QMK_KEYBOARD_H


// Process tap hold, place in process_record_user().
bool process_tap_hold(uint16_t keycode, const keyrecord_t *record);
// Matrix scan, place in matrix_scan_user()
void tap_hold_matrix_scan(void);

// User can override this to do whatever tap action they want.
void tap_hold_send_tap(uint16_t keycode);
// User must define this to do whatever hold action they want.
void tap_hold_send_hold(uint16_t keycode);
// Per key tap hold timeout
uint16_t tap_hold_timeout(uint16_t keycode);
// User override for what keys to trigger a tap hold action.
bool tap_hold(uint16_t keycode);
