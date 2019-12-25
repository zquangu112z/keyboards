#pragma once

/* Use I2C or Serial, not both */

#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#undef RGBLED_NUM
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

// Copy from ErgoDox EZ
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_MAX_SPEED   5
#define MOUSEKEY_WHEEL_DELAY 0

#define TAPPING_TERM    200
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

// #define FORCE_NKRO

// #define GRAVE_ESC_ALT_OVERRIDE   1
// #define GRAVE_ESC_CTRL_OVERRIDE  1
// #define GRAVE_ESC_GUI_OVERRIDE   1
// #define GRAVE_ESC_SHIFT_OVERRIDE 1
