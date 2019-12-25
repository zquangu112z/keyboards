/*
Copyright 2017 Phong Nguyen <nhphong1406@gmail.com>

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

enum custom_layers {
    _BASE,
    _LFN,
    _RFN,
    _MOUSE,
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,------------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |BkSpace |  ` |
     * |------------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | Del|
     * |------------------------------------------------------------------------------|
     * |Ctrl   |  A |  S |  D |  F |  G |  H |  J |  K |  L | ;  |  ' |     Enter|PgUp|
     * |------------------------------------------------------------------------------|
     * |Shift    |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  Shift | Up |PgDn|
     * |------------------------------------------------------------------------------|
     * |FN   | Gui | Alt |             SPACE            |Alt |Gui | FN |Left|Down|Rght|
     * `------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT( \
        KC_ESC,            KC_1,     KC_2,         KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,     KC_0,                 KC_MINS,           KC_EQL,   KC_BSPC,        KC_BSPC,  KC_GRV,   \
        KC_TAB,            KC_Q,     KC_W,         KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,     KC_P,                 KC_LBRC,           KC_RBRC,  KC_BSLS,        KC_DEL,   \
        CTL_T(KC_ESC),     KC_A,     KC_S,         KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,     LT(_MOUSE, KC_SCLN),  ALT_T(KC_QUOTE),   KC_NUHS,  RCTL_T(KC_ENT),           KC_PGUP,  \
        KC_LSFT,           KC_NUBS,  CTL_T(KC_Z),  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,               RCTL_T(KC_SLSH),   KC_RSFT,  KC_UP,                    KC_PGDN,  \
        LT(_LFN, KC_GRV),  KC_LGUI,  KC_LALT,                      KC_SPC,                   KC_RALT,  KC_RGUI,              LT(_RFN, KC_APP),  KC_LEFT,  KC_DOWN,                  KC_RGHT   \
    ),

    /* Layer 2: Left Function Layer
    * ,------------------------------------------------------------------------------.
    * |    | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |  RALT  |PSCR|
    * |------------------------------------------------------------------------------|
    * |      |    |    |    |    |    |    |    |    |    |    |    |    | RGUI |Ins |
    * |------------------------------------------------------------------------------|
    * |       |    |    |    |    |    |    |    |    |    |    |    |   RCTL   |Home|
    * |------------------------------------------------------------------------------|
    * |         |    |    |    |    |    |    |    |    |    |    |        |VolU| End|
    * |------------------------------------------------------------------------------|
    * |     |     |     |         HYPER / SPACE        |    |    |    |F14 |VolD| F15|
    * `------------------------------------------------------------------------------'
    */
    [_LFN] = LAYOUT( \
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_RALT,  KC_TRNS,  KC_PSCR,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_RGUI,            KC_INS,   \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_HOME,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLU,            KC_END,   \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                     ALL_T(KC_SPC),                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_SLCK,  KC_VOLD,            KC_PAUS   \
    ),

    /* Layer 3: Right Function Layer
    * ,------------------------------------------------------------------------------.
    * |LALT| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |        |PSCR|
    * |------------------------------------------------------------------------------|
    * |LGUI  |    |    |    |    |    |    |    |    |    |    |    |    |      |Ins |
    * |------------------------------------------------------------------------------|
    * |LCTL   |    |    |    |    |    |    |    |    |    |    |    |          |Home|
    * |------------------------------------------------------------------------------|
    * |         |    |    |    |    |    |    |    |    |    |    |        |VolU| End|
    * |------------------------------------------------------------------------------|
    * |     |     |     |           MEH / SPACE        |    |    |    |F14 |VolD| F15|
    * `------------------------------------------------------------------------------'
    */
    [_RFN] = LAYOUT( \
        KC_LALT,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  KC_PSCR,  \
        KC_LGUI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_INS,   \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_HOME,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  BL_STEP,  KC_TRNS,  KC_VOLU,            KC_END,   \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                      MEH_T(KC_SPC),                          KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F14,   KC_VOLD,            KC_F15    \
    ),

    /* Layer 4: Mouse Layer
    * ,------------------------------------------------------------------------------.
    * |BOOT|    |LFN |RFN |MOU |    |    |    |    |    |    |    |    |        |    |
    * |------------------------------------------------------------------------------|
    * |      |    |Mclk| MU |Rclk|    |    |Rclk| WU |Mclk|    |    |    |      |    |
    * |------------------------------------------------------------------------------|
    * |Capslck|Lclk| ML | MD | MR |Lclk|Lclk| WL | WD | WR |    |    |          |    |
    * |------------------------------------------------------------------------------|
    * |         |    |    |    |    |    |Norm|Swap|    |    |    |        |    |    |
    * |------------------------------------------------------------------------------|
    * |     |     |     |            LED               |    |    |    |    |    |    |
    * `------------------------------------------------------------------------------'
    */
    [_MOUSE] = LAYOUT( \
        RESET,    KC_TRNS,  KC_FN1,   KC_FN2,   KC_FN3,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_BTN3,  KC_MS_U,  KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_BTN2,  KC_WH_U,  KC_BTN3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
        KC_CAPS,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,  KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  AG_NORM,  AG_SWAP,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                           BL_STEP,                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS   \
    ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TOGGLE(_LFN),
    [2] = ACTION_LAYER_TOGGLE(_RFN),
    [3] = ACTION_LAYER_TOGGLE(_MOUSE),
};
