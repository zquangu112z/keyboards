#include QMK_KEYBOARD_H

enum hhkb_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _MOUSE,
};

#define MOUSE     TG(_MOUSE)
#define CTL_ESC   CTL_T(KC_ESC)
#define CTL_GRV   CTL_T(KC_GRV)
#define CTL_Z     CTL_T(KC_Z)
#define CTL_SLS   CTL_T(KC_SLSH)
#define GUI_QUO   GUI_T(KC_QUOT)
#define MOU_SCL   LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define LWR_SPC   LT(_LOWER, KC_SPC)      // Turn on _LOWER layer when held, Space when tapped
#define RSE_GRV   LT(_RAISE, KC_GRV)      // Turn on _RAISE layer when held, ` when tapped
#define RSE_BSP   LT(_RAISE, KC_BSPC)     // Turn on _RAISE layer when held, Backspace when tapped
#define RSE_DEL   LT(_RAISE, KC_DEL)      // Turn on _RAISE layer when held, Del when tapped

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ,--------------------------------------------------------------------------------------------------------.
     * | Esc  |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |  -   |  +   |  \   | BS   |
     * |--------------------------------------------------------------------------------------------------------|
     * | Tab     |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  [   |  ]   |          |
     * |-----------------------------------------------------------------------------------------------, Enter  |
     * | Ctrl      |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;   |  '   |  `   |        |
     * |--------------------------------------------------------------------------------------------------------|
     * | Shift       |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,   |  .   |  /   | Shift|  Up  | Del  |
     * |--------------------------------------------------------------------------------------------------------|
     * | Fn   ||| Ctrl| ALt  | Cmd  | Lower|                 | Raise| Cmd  | Alt  | MOUSE||| Left | Down | Right|
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT_JP(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, GUI_QUO, KC_GRV,  KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, KC_RSFT, KC_UP,   RSE_DEL,
        RSE_GRV, CTL_GRV, KC_LALT, KC_LGUI, LWR_SPC,     KC_SPC,      RSE_BSP, KC_RGUI, KC_RALT, MOUSE,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
     * ,--------------------------------------------------------------------------------------------------------.
     * | ~    |  !   |  @   |  #   |  $   |  %   |  ^   |  &   |  *   |  (   |  )   |  _   |  +   |  |   | Del  |
     * |--------------------------------------------------------------------------------------------------------|
     * |         |      | MS_U |MClick|RClick|      |      |RClick| WH_U |MClick|      |      |      |          |
     * |-----------------------------------------------------------------------------------------------,        |
     * |           | MS_L | MS_D | MS_R |LClick|      |LClick| WH_L | WH_D | WH_R |      |      |      |        |
     * |--------------------------------------------------------------------------------------------------------|
     * |             |      |      |      |      |      |AGnorm|AGswap|      |      |      |      |      | Reset|
     * |--------------------------------------------------------------------------------------------------------|
     * |      |||     |      |      |      |                 |      |      |      |      |||      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_JP(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, KC_PIPE, KC_DEL,
        _______, XXXXXXX, KC_MS_U, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, KC_BTN2, KC_WH_U, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, XXXXXXX, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM, AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, RESET,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______, _______, _______
    ),

    /*
     * ,--------------------------------------------------------------------------------------------------------.
     * | Power|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  Ins |  Del |
     * |--------------------------------------------------------------------------------------------------------|
     * | Capslock|      |      |      | Reset|      |      |      |PrtScr|ScrLk | Pause|  Up  |      |          |
     * |-----------------------------------------------------------------------------------------------,        |
     * |           | Vol- | Vol+ | Mute | Eject|      |  *   |  /   | Home | PgUp | Left | Right|      |        |
     * |--------------------------------------------------------------------------------------------------------|
     * |             |      |      |      |      |      |  +   |  -   | End  | PgDn | Down |      |      |      |
     * |--------------------------------------------------------------------------------------------------------|
     * |      |||     |      |      |      |                 |      |      |      |      |||      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_JP(
        KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
        KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   XXXXXXX,
        _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, XXXXXXX, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, XXXXXXX, KC_PENT,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, XXXXXXX, _______, _______,
        _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______, _______, _______
    ),

    /*
     * ,--------------------------------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |--------------------------------------------------------------------------------------------------------|
     * |         |      |MClick| MS_U |RClick|      |      |RClick| WH_U |MClick|      |      |      |          |
     * |-----------------------------------------------------------------------------------------------,        |
     * |           |LClick| MS_L | MS_D | MS_R |LClick|LClick| WH_L | WH_D | WH_R |      |      |      |        |
     * |--------------------------------------------------------------------------------------------------------|
     * |             |      |      |      |      |      |      |      |      |      |      |      |      |      |
     * |--------------------------------------------------------------------------------------------------------|
     * |      |||     |      |      |      |                 |      |      |      |      |||      |      |      |
     * `--------------------------------------------------------------------------------------------------------'
     */
    [_MOUSE] = LAYOUT_JP(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BTN3, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX, KC_BTN2, KC_WH_U, KC_BTN3, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     _______,      XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
