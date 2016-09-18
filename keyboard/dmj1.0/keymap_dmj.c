#include "keymap_common.h"

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
	// Pok3r-alike keyboard layout - contains most "standard" keypresses.
	// CapsLock = FN0 key.
	// Default layer on programming/factory reset.
    [0] = KEYMAP_ISO(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL ,BSPC, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,      \
        FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,ENT , \
        LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,      \
        LCTL,LGUI,LALT,          SPC,                     RALT,RGUI,FN6, RCTL),     
    // All the "useful" Pok3r Function layer keys, momentary layer from the default layer,
    // selectable with FN0 (capslock). Note FN1 on "S" key to get to layout select layer.
    [1] = KEYMAP_ISO(
        GRV, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12 ,DEL ,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PGUP,UP,  PGDN,TRNS,TRNS,TRNS,       \
        TRNS,TRNS,FN1 ,TRNS,TRNS,TRNS,HOME,LEFT,DOWN,RGHT,INS ,TRNS,TRNS,TRNS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,END ,TRNS,TRNS,TRNS,TRNS,TRNS,       \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
    // Alternate keymap, with CapsLock intact, but with rarely used key as FN (RGUI).
    // Used as a toggle layer to restore capslock to it's "normal" position.
    // Relies on default keymaps for all other keys (and so can sit on any keymap)
    [2] = KEYMAP_ISO(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       \
        CAPS,TRNS,TRNS,TRNS,TRNS,TRNS,HOME,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,FN0 ,TRNS,TRNS),
    // Layer select layer (transitory layer through which new default layouts are available).
    [3] = KEYMAP_ISO(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
        TRNS,FN3 ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,FN4 ,TRNS,TRNS,TRNS,       \
        TRNS,TRNS,TRNS,FN5 ,TRNS,TRNS,HOME,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,  \
        TRNS,TRNS,TRNS,TRNS,FN2 ,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,       \
        TRNS,TRNS,TRNS,          TRNS,                    TRNS,TRNS,TRNS,TRNS),
    // Colemak layer (default layer in waiting).
    [4] = KEYMAP_ISO(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL ,BSPC,  \
        TAB, Q,   W,   F,   P,   G,   J,   L,   U,   Y,   SCLN,LBRC,RBRC,       \
        FN0, A,   R,   S,   T,   D,   H,   N,   E,   I,   O,   QUOT,NUHS,ENT,   \
        LSFT,NUBS,Z,   X,   C,   V,   B,   K,   M,   COMM,DOT, SLSH,RSFT,       \
        LCTL,LGUI,LALT,          SPC,                     RALT,RGUI,FN6, RCTL),     
    // UK Dvorak layer (default layer in waiting).
    [5] = KEYMAP_ISO(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL ,BSPC,  \
        TAB, SLSH,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,   LBRC,RBRC,       \
        FN0, A,   O,   E,   U,   I,   D,   H,   T,   N,   S,   QUOT,NUHS,ENT,   \
        LSFT,NUBS,SCLN,Q,   J,   K,   X,   B,   M,   W,   V,   Z,   RSFT,       \
        LCTL,LGUI,LALT,          SPC,                     RALT,RGUI,FN6, RCTL),     
    // Momentary overlay using FN6 (APP key) to get mouse & multimedia controls plus misc extras.
    [6] = KEYMAP_ISO(
        TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PAST,TRNS,TRNS,TRNS,TRNS,TRNS,  \
        TRNS,TRNS,MS_U,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PSCR,PAUS,TRNS,       \
        TRNS,MS_L,MS_D,MS_R,TRNS,TRNS,TRNS,TRNS,VOLU,MPRV,MNXT,MSTP,TRNS,TRNS,  \
        TRNS,TRNS,BTN1,BTN2,BTN3,TRNS,TRNS,VOLD,MUTE,NLCK,SLCK,MPLY,TRNS,       \
        TRNS,TRNS,TRNS,          SLEP,                    TRNS,TRNS,TRNS,TRNS),
};

#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
	// All non-function keys indicated here are as appears on the default (0) layer.
    [0] = ACTION_LAYER_MOMENTARY(1),     // FN0 overlays the Functionkey and arrows cluster
    [1] = ACTION_LAYER_SET(3, ON_PRESS), // FN1 ("S" key ) selects layout layer.  Only way out of this
                                         // is to press one of the layer 3 FN keys.
    // These layers are all accessed through the "layer select" layer.
    [2] = ACTION_LAYER_TOGGLE(2),        // Make capslock work as capslock; FN0 now on RGUI ("C" key).
    [3] = ACTION_DEFAULT_LAYER_SET(0),   // set QWERTY layer as default. ("Q" key)
    [4] = ACTION_DEFAULT_LAYER_SET(4),   // set colemak layout ("O" key).
    [5] = ACTION_DEFAULT_LAYER_SET(5),   // set dvorak layout ("D" key).
    // Tap FN6 = APP key; hold = rare key layer momentary action.
    [6] = ACTION_LAYER_TAP_KEY(6, KC_APP),
};


#if 0
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0] = ACTION_DEFAULT_LAYER_SET(0),                // Default layer(not used)
    [1] = ACTION_LAYER_TAP_TOGGLE(1),                 // HHKB layer(toggle with 5 taps)
    [2] = ACTION_LAYER_TAP_KEY(2, KC_SLASH),          // Cursor layer with Slash*
    [3] = ACTION_LAYER_TAP_KEY(3, KC_SCLN),           // Mousekey layer with Semicolon*
    [4] = ACTION_LAYER_TAP_KEY(4, KC_SPC),            // Mousekey layer with Space
    [5] = ACTION_LAYER_MOMENTARY(4),                  // Mousekey layer(IJKL)
    [6] = ACTION_MODS_TAP_KEY(MOD_RCTL, KC_ENT),      // RControl with tap Enter
    [7] = ACTION_MODS_ONESHOT(MOD_LSFT),              // Oneshot Shift
    [8] = ACTION_MACRO(ALT_TAB),                      // Application switching
    [9] = ACTION_MODS_KEY(MOD_LALT, KC_LEFT),
   [10] = ACTION_MODS_KEY(MOD_LALT, KC_RIGHT),

//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_BSPC),        // LControl with tap Backspace
//  [x] = ACTION_LMOD_TAP_KEY(KC_LCTL, KC_ESC),         // LControl with tap Esc
//  [x] = ACTION_FUNCTION_TAP(LSHIFT_LPAREN),           // Function: LShift with tap '('
//  [x] = ACTION_MACRO(HELLO),                          // Macro: say hello
//  [x] = ACTION_MACRO(VOLUP),                          // Macro: media key
};
#endif

