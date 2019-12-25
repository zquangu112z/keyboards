#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum iris_layers {
    _PHONG,
    _PHONG_V1,
    _PHONG_V2,
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum iris_keycodes {
    PHONG = SAFE_RANGE,
    PHONG_V1,
    PHONG_V2,
    QWERTY,
    LOWER,
    RAISE,
    MOUSE,
};

#define LWR_SPC LT(_LOWER, KC_SPC)      // Turn on _LOWER layer when held, Space when tapped
#define RSE_ENT LT(_RAISE, KC_ENT)      // Turn on _RAISE layer when held, End when tapped
#define RSE_BSP LT(_RAISE, KC_BSPC)     // Turn on _RAISE layer when held, Backspace when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left Control when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left Control when held, z when tapped
#define CTL_SCL LCTL_T(KC_SCLN)         // Left Control when held, ; when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right Control when held, / when tapped
#define GUI_QUO RGUI_T(KC_QUOT)         // Right Gui when held, " when tapped
#define CAG_TAB LCAG_T(KC_TAB)          // Ctrl+Alt+Gui when held, Tab when tapped
#define SFT_ENT RSFT_T(KC_ENT)          // Right Shift when held, Enter when tapped
#define SFT_BSP RSFT_T(KC_BSPC)         // Right Shift when held, Backspace when tapped
#define SFT_BSL RSFT_T(KC_BSLS)         // Right Shift when held, \ when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                             │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │                             │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │                             │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││   [    │       │    ]   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft/BkSp│
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │  Enter │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_PHONG] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        CAG_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_BSP,
                                            KC_LGUI, LWR_SPC, KC_SPC,       KC_ENT,  RSE_ENT, KC_LALT
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                             │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │                             │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │                             │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││   [    │       │    ]   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft/ Ent│
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │ BkSpace│││││RSE/BkSp│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_PHONG_V1] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        CAG_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT,
                                            KC_LGUI, LWR_SPC, KC_SPC,       KC_BSPC, RSE_BSP, KC_LALT
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   =    │   1    │   2    │   3    │   4    │   5    │                             │   6    │   7    │   8    │   9    │   0    │   -    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │                             │   Y    │   U    │   I    │   O    │   P    │ BkSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │                             │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││   [    │       │    ]   │││  N     │   M    │   ,    │   .    │ / / CTL│Sft / \ │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │  Enter │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_PHONG_V2] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        CAG_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_BSL,
                                            KC_LGUI, LWR_SPC, KC_SPC,       KC_ENT,  RSE_ENT, KC_LALT
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  Esc   │   1    │   2    │   3    │   4    │   5    │                             │   6    │   7    │   8    │   9    │   0    │ BkSpace│
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Tab   │   Q    │   W    │   E    │   R    │   T    │                             │   Y    │   U    │   I    │   O    │   P    │   \    │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │Esc/ CTL│   A    │   S    │   D    │   F    │   G    │                             │   H    │   J    │   K    │   L    │ ; / MOU│' / GUI │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │ Shift  │Z / CTL │   X    │   C    │   V    │   B    │││   [    │       │    ]   │││  N     │   M    │   ,    │   .    │ / / CTL│ Shift  │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │  GUI   │LWR/ SPC│││││ Space  │       │  Enter │││││RSE/ ENT│  ALT   │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        CAG_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,      KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT,
                                            KC_LGUI, LWR_SPC, KC_SPC,       KC_ENT,  RSE_ENT, KC_LALT
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │   ~    │   !    │   @    │   #    │   $    │   %    │                             │   ^    │   &    │   *    │   (    │   )    │  PgUp  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   `    │   1    │   2    │   3    │   4    │   5    │                             │   6    │   7    │   8    │   9    │   0    │  PgDn  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  CAPS  │        │  Left  │ Right  │   Up   │   [    │                             │   ]    │   4    │   5    │   6    │   +    │  Home  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │  Down  │   {    │││   (    │       │   )    │││   }    │   1    │   2    │   3    │   -    │  End   │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │ LOWER  │││││        │       │  Del   │││││ RAISE  │   0    │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PGUP,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PGDN,
        KC_CAPS, _______, KC_LEFT, KC_RGHT, KC_UP,   KC_LBRC,                        KC_RBRC, KC_P4,   KC_P5,   KC_P6,   KC_PLUS, KC_HOME,
        BL_STEP, _______, _______, _______, KC_DOWN, KC_LCBR, KC_LPRN,      KC_RPRN, KC_RCBR, KC_P1,   KC_P2,   KC_P3,   KC_MINS, KC_END,
                                            _______, LOWER,   KC_DEL,       KC_DEL,  RAISE,   KC_P0
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  F12   │   F1   │   F2   │   F3   │   F4   │   F5   │                             │   F6   │   F7   │   F8   │   F9   │  F10   │  F11   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │   ~    │   !    │   @    │   #    │   $    │   %    │                             │   ^    │   &    │   *    │   (    │   )    │  F12   │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Del   │  Prev  │  Next  │  Vol+  │  PgUp  │   _    │                             │   =    │  Home  │  Hue+  │  Sat+  │  Val+  │  RGBT  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  Mute  │  Stop  │  Play  │  Vol-  │  PgDn  │   -    │││   (    │       │   )    │││   +    │  End   │  Hue-  │  Sat-  │  Val-  │  RGBM  │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │ LOWER  │││││ BkSpace│       │        │││││ RAISE  │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_RAISE] = LAYOUT(
        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12,
        KC_DEL,  KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                        KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG,
        KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,      KC_RPRN, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD,
                                            _______, LOWER,   KC_BSPC,      _______, RAISE,   _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │  RESET │  F14   │  F15   │        │        │ AG_NORM│                             │ AG_SWAP│  Prev  │  Play  │  Next  │  Mute  │  Vol-  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  RGBT  │        │        │   Up   │        │        │                             │        │        │   Up   │        │        │  Vol+  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │  RGBM  │        │  Left  │  Down  │  Right │        │                             │        │  Left  │  Down  │  Right │        │  RGBM  │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │  BL    │        │        │        │        │        │││        │       │        │││        │        │        │        │        │  BRTG  │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_ADJUST] = LAYOUT(
        RESET,   KC_F14,  KC_F15,  _______, _______, AG_NORM,                        AG_SWAP, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,
        RGB_TOG, _______, _______, KC_UP,   _______, _______,                        _______, _______, KC_UP,   _______, _______, KC_VOLU,
        RGB_RMOD,_______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, RGB_MOD,
        BL_STEP, _______, RGB_VAD, RGB_SAD, RGB_HUD, _______, _______,      _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, BL_BRTG,
                                            _______, _______, _______,      _______, _______, _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │ PHONG  │PHONG_V1│PHONG_V2│ QWERTY │ AG_NORM│                             │ AG_SWAP│        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │ MClick │  MS_U  │ RClick │        │                             │        │ RClick │  WH_U  │ MClick │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │Capslock│ LClick │  MS_L  │  MS_D  │  MS_R  │ LClick │                             │ LClick │  WH_L  │  WH_D  │  WH_L  │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
    [_MOUSE] = LAYOUT(
        _______, PHONG,   PHONG_V1,PHONG_V2,QWERTY,  AG_NORM,                        AG_SWAP, _______, _______, _______, _______, _______,
        _______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______,                        _______, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______,
        KC_CAPS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,                        KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,      _______, _______, _______
    ),

    /*
     * ┌────────┬────────┬────────┬────────┬────────┬────────┐                             ┌────────┬────────┬────────┬────────┬────────┬────────┐
     * │        │        │        │        │        │        │                             │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │                             │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┤                             ├────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │                             │        │        │        │        │        │        │
     * ├────────┼────────┼────────┼────────┼────────┼────────┼─┬────────┐       ┌────────┬─┼────────┼────────┼────────┼────────┼────────┼────────┤
     * │        │        │        │        │        │        │││        │       │        │││        │        │        │        │        │        │
     * └────────┴────────┴────────┴──────┬─┴──────┬─┴──────┬─┼─┼────────┤       ├────────┼─┼─┬──────┴─┬──────┴─┬──────┴────────┴────────┴────────┘
     *                                   │        │        │││││        │       │        │││││        │        │
     *                                   └────────┴────────┴─┴─┴────────┘       └────────┴─┴─┴────────┴────────┘
     */
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case PHONG:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_PHONG);
        }
        return false;
        break;
    case PHONG_V1:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_PHONG_V1);
        }
        return false;
        break;
    case PHONG_V2:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_PHONG_V2);
        }
        return false;
        break;
    case QWERTY:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
        break;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case MOUSE:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_MOUSE);
        }
        return false;
        break;
    }
    return true;
}
