#include "keymap_common.h"

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__((section(".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
   // Pok3r-alike keyboard layout - contains most "standard" keypresses, and via other layers,
   // some not so standard keypresses.  Going to this from a Pok3r should be reasonably straightforward.
   // Note that layer 0, 4 & 5 are the potential default layers (0 is factory default).
   // All other layers are on top of one of these three, and accessed either through FN0 or FN6
   // FN0 is the pok3r alike Fn key, but default on CapsLock. FN6 is the APP (Menu) key next to RGUI
   // (the rightmost windows key), through which the "rare" keys are accessed.

   // Layout select layer has been removed; The FN1 layer is a basket to get right, as it has to
   // return to one of the three default layers - but without knowing which layer was in effect.
   // Being only able to effect change in one layer in the core code is the problem here; we
   // need to be able to not only set default layers (easy with ACTION_DEFAULT_LAYER_SET), but
   // sometimes we need to (for the caps layer) toggle that layer, and return to the previous
   // layer.

   // clang-format off
   // Default layer on programming/factory reset.
   [0] = KEYMAP_ISO(ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC,
                    TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC,
                    FN0,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT, NUHS, ENT,
                    LSFT, NUBS, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH, RSFT,
                    LCTL, LGUI, LALT, SPC,                                      RALT, RGUI, FN6,  RCTL),

   // Colemak layer (default layer in waiting).
   [1] = KEYMAP_ISO(ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC,
                    TAB,  Q,    W,    F,    P,    G,    J,    L,    U,    Y,    SCLN, LBRC, RBRC,
                    FN0,  A,    R,    S,    T,    D,    H,    N,    E,    I,    O,    QUOT, NUHS, ENT,
                    LSFT, NUBS, Z,    X,    C,    V,    B,    K,    M,    COMM, DOT,  SLSH, RSFT,
                    LCTL, LGUI, LALT, SPC,                                      RALT, RGUI, FN6,  RCTL),

   // UK Dvorak layer (default layer in waiting).
   [2] = KEYMAP_ISO(ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC,
                    TAB,  SLSH, COMM, DOT,  P,    Y,    F,    G,    C,    R,    L,    LBRC, RBRC,
                    FN0,  A,    O,    E,    U,    I,    D,    H,    T,    N,    S,    QUOT, NUHS, ENT,
                    LSFT, NUBS, SCLN, Q,    J,    K,    X,    B,    M,    W,    V,    Z,    RSFT,
                    LCTL, LGUI, LALT, SPC,                                      RALT, RGUI, FN6,  RCTL),

// All the "useful" Pok3r Function layer keys, momentary layer from the default layer,
// selectable with FN0 (capslock). Note FN1 on "S" key to get to layout select layer.
// This FN1 is actually #defined out - it doesn't work and looks like it needs core
// support to make it work too.  More to come on this...
#ifdef USE_FN1_FOR_TRANSITORY_LAYER_SELECT_LAYER
   [3] = KEYMAP_ISO(GRV,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  DEL,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PGUP, UP,   PGDN, TRNS, TRNS, TRNS,
                    TRNS, TRNS, FN1,  TRNS, TRNS, TRNS, HOME, LEFT, DOWN, RGHT, INS,  TRNS, F20,  TRNS,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, END,  TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS,                                     TRNS, TRNS, TRNS, TRNS),
#else
   [3] = KEYMAP_ISO(GRV,  F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  DEL,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PGUP, UP,   PGDN, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, HOME, LEFT, DOWN, RGHT, INS,  TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, END,  TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS,                                     TRNS, TRNS, TRNS, TRNS),
#endif

   // Alternate keymap, with CapsLock intact, but with rarely used key as FN (APP).
   // Used as a toggle layer to restore capslock to it's "normal" position.
   // Relies on default keymaps for all other keys (and so can sit on any keymap)
   // Note that the FN key is placed on the right GUI key, which is no longer
   // a GUI (Menu) key - that's the price of CapsLock, folks.
   [4] = KEYMAP_ISO(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    CAPS, TRNS, TRNS, TRNS, TRNS, TRNS, HOME, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS,                                     TRNS, FN0,  TRNS, TRNS),

   // Layer select layer (transitory layer through which new default layouts are available).
   // FN2 = C (Select Capslock layer - DOES NOT MAKE THIS LAYER DEFAULT)
   // FN3 = Q (Select QWERTY layout)
   // FN4 = O (Select Colemak layout)
   // FN5 = D (Select Dvorak layout)
   [5] = KEYMAP_ISO(TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, FN3,  TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,  FN4, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, FN5,  TRNS, TRNS, HOME, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS,  FN2, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
                    TRNS, TRNS, TRNS, TRNS,                                     TRNS, TRNS, TRNS, TRNS),

   // Momentary overlay using FN6 (right APP key) to get mouse & multimedia controls plus misc extras.
   // Most notably, keypad asterisk which as a (Windows) developer I cannot live without.
   [6] = KEYMAP_ISO(GRV,  F13,  F14,  F15,  F16,  F17,  F18,  F19,  F20,  F21,  F22,  F23,  F24,  FN2,
                    TRNS, TRNS, MS_U, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, PSCR, PAUS, TRNS,
                    TRNS, MS_L, MS_D, MS_R, TRNS, TRNS, TRNS, TRNS, VOLU, TRNS, MPRV, MSTP, MNXT, TRNS,
                    TRNS, TRNS, BTN1, BTN2, BTN3, TRNS, TRNS, VOLD, MUTE, NLCK, SLCK, MPLY, TRNS,
                    TRNS, TRNS, TRNS, SLEP,                                     TRNS, TRNS, TRNS, TRNS),
};
// clang-format on
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__((section(".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
   // All non-function keys indicated here are as appears on the default (0) layer.
   [0] = ACTION_LAYER_MOMENTARY(3), // FN0 overlays the Functionkey and arrows cluster
#ifdef USE_FN1_FOR_TRANSITORY_LAYER_SELECT_LAYER
   [1] = ACTION_LAYER_MOMENTARY(5), // FN1 ("S" key ) selects layout layer.
#else
   [1] = {0},
#endif
   // These layers are all accessed through the "layer select" layer.
   [2] = ACTION_LAYER_TOGGLE(4),      // Make capslock work as capslock; FN0 now on RGUI ("C" key).
   [3] = ACTION_DEFAULT_LAYER_SET(0), // set QWERTY layer as default. ("Q" key)
   [4] = ACTION_DEFAULT_LAYER_SET(1), // set colemak layout ("O" key).
   [5] = ACTION_DEFAULT_LAYER_SET(2), // set dvorak layout ("D" key).
   // Tap FN6 = APP key; hold = rare key layer momentary action.
   [6] = ACTION_LAYER_TAP_KEY(6, KC_APP),
#if 0
   // Can't remember what these keys achieve.  Plus the FN7 and FN8 keys aren't defined in the maps.
   [7] = ACTION_MODS_TAP_KEY(MOD_LSFT, ACTION_MODS_KEY(MOD_LSFT, KC_9)),
   [8] = ACTION_MODS_TAP_KEY(MOD_RSFT, ACTION_MODS_KEY(MOD_LSFT, KC_0)),
#endif
};
