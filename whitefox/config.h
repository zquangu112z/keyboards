#ifndef CONFIG_PHONGNH_H
#define CONFIG_PHONGNH_H

#include "../../config.h"

// Copy from ErgoDox EZ
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 5
#define MOUSEKEY_MAX_SPEED   5
#define MOUSEKEY_WHEEL_DELAY 0

#define TAPPING_TOGGLE  1

#define TAPPING_TERM    200
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap
// #def LOCKING_SUPPORT_ENABLE

// Locking resynchronize hack
// #def LOCKING_RESYNC_ENABLE

// disable debug print
// #define NO_DEBUG

// disable print
// #define NO_PRINT

#endif
