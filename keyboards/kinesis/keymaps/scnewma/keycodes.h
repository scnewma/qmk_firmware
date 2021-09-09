#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _BASE2,
    _SFT,
    _CBASE,
    _QWERTY,
    _LRGX,
    _RNUM,
    _RSYM,
    _RGX,
    _SYM,
    _CMD,
    _COMMANDS,
    _KEYPAD,
    _SYM2
};

enum custom_keycodes {
    TMX_PRVW = SAFE_RANGE,

    // swapper keycodes
    SW_WIN, // (cmd-tab)

    // oneshot keycodes
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    // programming common symbol string
    P_RASM, // ->
    P_RALG, // =>
    P_DCLN, // ::
    P_HBNG, // #!
    P_PEQL, // +=
};

#define CLIPSC G(S(C(KC_4)))        // Cmd-Shift-Ctrl-4 -> macOS Screenshot (clipboard)
#define PRNTSC G(S(KC_4))           // Cmd-Shift-4 -> macOS Screenshot
#define C_ESC CTL_T(KC_ESC)        // control when held, escape when tapped
#define _CMDS OSL(_COMMANDS)
#define TPFX C(KC_SPC)              // tmux prefix
#define LA_CMD LT(_CMD, KC_TAB)
#define LA_SFT LT(_SFT, KC_ESC)
#define LA_SYM MO(_RSYM)
#define LA_NUM LT(_RNUM, KC_ENTER)
#define ALFRED G(KC_SPC)
