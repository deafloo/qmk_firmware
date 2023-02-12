#include QMK_KEYBOARD_H
#include <keymap_german.h>
#include <color.h>
#include "custom_colors.h"
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
    ARROWS,
    MAKRO,
    GAMING
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
            KC_P4,    KC_P5,    KC_P6,    TO(MATH),   \
            KC_P1,    KC_P2,    KC_P3,    TO(NUMPAD),    \
            KC_P0,    KC_DOT,  KC_PDOT,  KC_PENT
    ),
    [MATH] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            _______,    _______,    _______,
            _______,    _______,    _______,    TO(ARROWS),
            _______,    _______,    _______,    _______,    
            _______,    _______,    _______,    _______
    ),
    [ARROWS] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            KC_BSPC,    KC_DEL,    KC_HOME,
            KC_TAB,     KC_UP,     KC_END,      TO(GAMING),
            KC_LEFT,    KC_DOWN,   KC_RIGHT,    _______,
            KC_SPACE,   _______,   _______,     KC_ENT
    ),
    [MAKRO] = LAYOUT_numpad_5x4(
        _______, _______, _______,
            _______,    _______,    _______,
            _______,    _______,    _______,    TO(GAMING),
            _______,    _______,    _______,    _______,    
            _______,    _______,    _______,    _______
    ),
    [GAMING] = LAYOUT_numpad_5x4(
        _______, _______, KC_ESC,
            KC_TAB,     KC_I,       KC_M,
            KC_Q,       KC_W,       KC_E,       TO(NUMPAD),
            KC_A,       KC_S,       KC_D,       KC_G,
            KC_LSFT,    KC_LCTL,    KC_C,       KC_SPACE

    )
};


// LED behavior
led_config_t g_led_config = { 
{   // Key Matrix to LED index
    {NO_LED, NO_LED, NO_LED},
        {13,   12,  11},
        {10,   9,   8,   7},
{NO_LED, 6,    5,   4},
        {3,    2,   1,   0}
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
    4,4,4,4,
    4,4,4,
    4,4,4,4
}
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void){
    rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [NUMPAD] =  { {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, {HSV_blue0},
                  {HSV_blue3}, {HSV_blue2}, {HSV_blue1},
                  {HSV_function_yellow}, {HSV_blue6}, {HSV_blue5}, {HSV_blue4},
                  {HSV_blue9}, {HSV_blue8}, {HSV_blue7} },

    [MATH] =    { {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green},
                  {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green},
                  {HSV_function_yellow}, {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green},
                  {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green} },

    [ARROWS] =  { {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, 
                  {HSV_blue5}, {HSV_blue5}, {HSV_blue5}, 
                  {HSV_function_yellow}, {HSV_custom_green}, {HSV_blue5}, {HSV_custom_green}, 
                  {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green} },

    [MAKRO] =   { {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green},
                  {HSV_PINK}, {HSV_TURQUOISE}, {HSV_RED},
                  {HSV_function_yellow}, {HSV_TEAL}, {HSV_MAGENTA}, {HSV_ORANGE},
                  {HSV_AZURE}, {HSV_BLUE}, {HSV_GREEN} },

    [GAMING] =  { {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green}, 
                  {HSV_custom_red}, {HSV_custom_red}, {HSV_custom_red}, 
                  {HSV_function_yellow}, {HSV_custom_green}, {HSV_custom_red}, {HSV_custom_green}, 
                  {HSV_custom_green}, {HSV_custom_green}, {HSV_custom_green} }
};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void matrix_scan_user(void){
  if (!rgblight_is_enabled()) { return; }
  switch (biton32(layer_state)) {
    case NUMPAD:
      set_layer_color(NUMPAD);
      break;
    case MATH:
      set_layer_color(MATH);
      break;
    case ARROWS:
      set_layer_color(ARROWS);
      break;
    case MAKRO:
      set_layer_color(MAKRO);
      break;
    case GAMING:
      set_layer_color(GAMING);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

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
        case ARROWS:
            clockwise ? tap_code(KC_WH_U):tap_code(KC_WH_D);
            break;
        case GAMING:
            clockwise ? tap_code(KC_VOLU):tap_code(KC_VOLD);
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
        case ARROWS:
            oled_write_P(PSTR("Movement\n"), false);
            break;
        case GAMING:
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }    
    return false;
}
#endif
