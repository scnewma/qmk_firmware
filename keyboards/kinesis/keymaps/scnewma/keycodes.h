#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _BASE2,
    _SFT,
    _CBASE,
    _QWERTY,
    _RGX,
    _SYM,
    _COMMANDS,
    _KEYPAD,
    _SYM2
};

enum custom_keycodes {
    TMX_PRVW = SAFE_RANGE,
    L_NUM,

    // swapper keycodes
    SW_WIN, // (cmd-tab)

    // oneshot keycodes
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
};

#define CLIPSC G(S(C(KC_4)))        // Cmd-Shift-Ctrl-4 -> macOS Screenshot (clipboard)
#define PRNTSC G(S(KC_4))           // Cmd-Shift-4 -> macOS Screenshot
#define C_ESC CTL_T(KC_ESC)        // control when held, escape when tapped
#define _CMDS OSL(_COMMANDS)
