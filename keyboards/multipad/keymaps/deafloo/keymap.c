#include QMK_KEYBOARD_H

// Helpful defines
//#define GRAVE_MODS  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
// The underscores don't mean anything - you can
// have a layer called STUFF or any other name.
// Layer names don't all need to be of the same
// length, and you can also skip them entirely
// and just use numbers.
#define NUMPAD 0
#define MATH 1
#define MAKRO 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *   [1][2][3]
     *    ┌───┬───┬───┬───┐
     *    │ 7 │ 8 │ 9 │DSP│
     *    ├───┼───┼───┼───│
     *    │ 4 │ 5 │ 6 │Fnc│
     *┌───┼───┼───┼───┼───┤
     *│ENC│ 1 │ 2 │ 3 │   │
     *└─┬─┴───┼───┼───┤Ent│
     *  │  0  │   │ , │   │
     *  └─────┴───┴───┴───┘
     */
    [NUMPAD] = LAYOUT_numpad_5x4(
        RGB_TOG, RGB_VAI, KC_CALC,                  \
            KC_P7,    KC_P8,    KC_P9,              \
            KC_P4,    KC_P5,    KC_P6,    KC_TAB,   \
     TG(1), KC_P1,    KC_P2,    KC_P3,              \
            KC_P0,    KC_PDOT,  KC_PCMM,  KC_PENT
    ),
    [MATH] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            _______,    _______,    _______,
            _______,    _______,    _______,    _______,
   _______, _______,    _______,    _______,    
            _______,    _______,    _______,    _______
    ),
    [MAKRO] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            _______,    _______,    _______,
            _______,    _______,    _______,    _______,
   _______, _______,    _______,    _______,    
            _______,    _______,    _______,    _______
    )
};

led_config_t g_led_config = { 
{   // Key Matrix to LED index
    {NO_LED, NO_LED, NO_LED},
    {0,  1,  2},
    {3,  4,  5,  6},
    {NO_LED, 7,  8,  9},
    {10, 11, 12, 13}
},
{
    // LED index to Physical Position
    {0,0},{74,0},{148,0},
    {0,21},{74,21},{148,21},{222,21},
    {0,42},{74,42},{148,42},
    {0,63},{74,63},{148,63},{222,63}
},
{
    // LED index to Flag
    4,4,4,
    4,4,4,1,
    4,4,4,
    4,1,4,4
}
};
