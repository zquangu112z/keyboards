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
#include "whitefox.h"

enum custom_layers {
    _BASE,
    _MEDIA,
    _SYMBOL,
    _MOUSE,
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
     * ,------------------------------------------------------------------------------.
     * |Esc |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |BkSpace |  ` |
     * |------------------------------------------------------------------------------|
     * |Tab   |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | Del|
     * |------------------------------------------------------------------------------|
     * |FN     |  A |  S |  D |  F |  G |  H |  J |  K |  L | ;  |  ' |     Enter|PgUp|
     * |------------------------------------------------------------------------------|
     * |Shift    |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |  Shift | Up |PgDn|
     * |------------------------------------------------------------------------------|
     * |Ctrl | Gui | Alt |             Space            |Alt |Menu|Ctrl|Left|Down|Rght|
     * `------------------------------------------------------------------------------'
     */
    [_BASE] = KEYMAP( \
        KC_ESC,              KC_1,     KC_2,          KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,     KC_0,                 KC_MINS,          KC_EQL,   KC_BSPC,             KC_BSPC,  KC_GRV,   \
        KC_TAB,              KC_Q,     KC_W,          KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,     KC_P,                 KC_LBRC,          KC_RBRC,  KC_BSLS,                       KC_DEL,   \
        LT(_MEDIA, KC_ESC),  KC_A,     KC_S,          KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,     LT(_MOUSE, KC_SCLN),  ALT_T(KC_QUOTE),  KC_NUHS,  LT(_SYMBOL, KC_ENT),           KC_PGUP,  \
        KC_LSFT,             KC_NUBS,  LCTL_T(KC_Z),  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM,  KC_DOT,               RCTL_T(KC_SLSH),  KC_RSFT,  KC_UP,                         KC_PGDN,  \
        KC_LCTL,             KC_LGUI,  KC_LALT,                       KC_SPC,                   KC_RALT,  RGUI_T(KC_APP),       KC_RCTL,          KC_LEFT,  KC_DOWN,                       KC_RGHT   \
    ),

    /* Layer 1: Media (and Symbol) Layer
    * ,------------------------------------------------------------------------------.
    * |SLEP| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |        |BTLD|
    * |------------------------------------------------------------------------------|
    * |WAKE  | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |PrtScr| Ins|
    * |------------------------------------------------------------------------------|
    * |       |PREV|PLAY|NEXT|    |    |    |VOLD|VOLU|    |    |    |  Control |Home|
    * |------------------------------------------------------------------------------|
    * |         |    |    |    |    |    |NORM|SWAP|F14 |F15 |LED |        |    |End |
    * |------------------------------------------------------------------------------|
    * |     |     |     |                              |    |    |    |    |    |    |
    * `------------------------------------------------------------------------------'
    */
    [_MEDIA] = KEYMAP( \
        KC_SLEP,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  RESET,    \
        KC_WAKE,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,            KC_INS,   \
        KC_TRNS,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_RCTL,            KC_HOME,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  AG_NORM,  AG_SWAP,  KC_F14,   KC_F15,   BL_STEP,  KC_TRNS,  KC_TRNS,            KC_END,   \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                           KC_TRNS,                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS   \
    ),

    /* Layer 2: Media (and Symbol) Layer
    * ,------------------------------------------------------------------------------.
    * |SLEP| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |        |BTLD|
    * |------------------------------------------------------------------------------|
    * |WAKE  | F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 |F10 |F11 |F12 |PrtScr| Ins|
    * |------------------------------------------------------------------------------|
    * |Control|PREV|PLAY|NEXT|    |    |    |VOLD|VOLU|    |    |    |          |Home|
    * |------------------------------------------------------------------------------|
    * |         |    |    |    |    |    |NORM|SWAP|F14 |F15 |LED |        |    |End |
    * |------------------------------------------------------------------------------|
    * |     |     |     |                              |    |    |    |    |    |    |
    * `------------------------------------------------------------------------------'
    */
    [_SYMBOL] = KEYMAP( \
        KC_SLEP,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,  RESET,    \
        KC_WAKE,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,            KC_INS,   \
        KC_LCTL,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_HOME,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  AG_NORM,  AG_SWAP,  KC_F14,   KC_F15,   BL_STEP,  KC_TRNS,  KC_TRNS,            KC_END,   \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                           KC_TRNS,                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS   \
    ),

    /* Layer 3: Mouse Layer
    * ,------------------------------------------------------------------------------.
    * |    |    |    |    |    |    |    |    |    |    |    |    |    |        |    |
    * |------------------------------------------------------------------------------|
    * |      |    |Mclk| MU |Rclk|    |    |Rclk| WU |Mclk|    |    |    |      |    |
    * |------------------------------------------------------------------------------|
    * |Capslck|Lclk| ML | MD | MR |Lclk|Lclk| WL | WD | WR |    |    |          |    |
    * |------------------------------------------------------------------------------|
    * |         |    |    |    |    |    |    |    |    |    |    |        |    |    |
    * |------------------------------------------------------------------------------|
    * |     |     |     |                              |    |    |    |    |    |    |
    * `------------------------------------------------------------------------------'
    */
    [_MOUSE] = KEYMAP( \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_BTN3,  KC_MS_U,  KC_BTN2,  KC_TRNS,  KC_TRNS,  KC_BTN2,  KC_WH_U,  KC_BTN3,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
        KC_CAPS,  KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN1,  KC_BTN1,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  \
        KC_TRNS,  KC_TRNS,  KC_TRNS,                           KC_TRNS,                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS   \
    ),
};

