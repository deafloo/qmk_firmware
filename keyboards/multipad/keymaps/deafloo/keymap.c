#include QMK_KEYBOARD_H
#include <keymap_german.h>
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
enum layer_names{
    NUMPAD,
    MATH,
    MAKRO
};

// Switch behavior
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *  Physical Layout
     *   [t1][t2][t3]
     *    ┌───┬───┬───┬───┐
     *    │ 7 │ 8 │ 9 │DSP│
     *    ├───┼───┼───┼───│
     *    │ 4 │ 5 │ 6 │Fnc│
     *┌───┼───┼───┼───┼───┤
     *│ENC│ 1 │ 2 │ 3 │   │
     *└─┬─┴───┼───┼───┤Ent│
     *  │  0  │   │ , │   │
     *  └─────┴───┴───┴───┘
     * 
     *  Logical Layout
     *        [2][3][1]
     *    ┌───┬───┬───┬───┐
     *    │ 7 │ 8 │ 9 │   │
     *    ├───┼───┼───┼───│
     *    │ 4 │ 5 │ 6 │Fnc│
     *    ├───┼───┼───┼───┤
     *    │ 1 │ 2 │ 3 │ENC│
     *  ┌─┴───┼───┼───┼───┤
     *  │  0  │ . │ , │Ent│
     *  └─────┴───┴───┴───┘
     */
    [NUMPAD] = LAYOUT_numpad_5x4(
        RGB_VAI, RGB_TOG, KC_CALC,                  \
            KC_P7,    KC_P8,    KC_P9,              \
            KC_P4,    KC_P5,    KC_P6,    KC_TAB,   \
            KC_P1,    KC_P2,    KC_P3,    TO(MATH),    \
            KC_P0,    KC_DOT,  KC_PDOT,  KC_PENT
    ),
    [MATH] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            _______,    _______,    _______,
            _______,    _______,    _______,    _______,
            _______,    _______,    _______,    TO(MAKRO),    
            _______,    _______,    _______,    _______
    ),
    [MAKRO] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            _______,    _______,    _______,
            _______,    _______,    _______,    _______,
            _______,    _______,    _______,    TO(NUMPAD),    
            _______,    _______,    _______,    _______
    )
};


// LED behavior
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


// Encoder behavior
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case NUMPAD:
            clockwise ? tap_code(KC_VOLU):tap_code(KC_VOLD);
            break;
        case MATH:
            clockwise ? rgblight_increase_val():rgblight_decrease_val();
            break;
        case MAKRO:
            clockwise ? rgblight_increase_hue():rgblight_decrease_hue();
            break;
    }
    return false;
}



// OLED behavior
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case NUMPAD:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case MATH:
            oled_write_P(PSTR("Math\n"), false);
            break;
        case MAKRO:
            oled_write_P(PSTR("Makro\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }    
    return false;
}
#endif
