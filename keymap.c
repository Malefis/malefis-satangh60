
#include "satan.h"


#define DEFAULT 0
#define LAYERONE 1
#define MEDIA 2
// increase readability 
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap DEFAULT: Default Layer
     * ,-----------------------------------------------------------.
     * |Grv|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Enter| 
     * |------------------------------------------------------     |
     * |Caps Lock| A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|' |#|     |
     * |-----------------------------------------------------------|
     * |Sft | \ |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|   Shift  | 
     * |-----------------------------------------------------------|
     * |Ctrl |Win | Alt |      Space         |Alt |Win  |Menu |RCtl|
     * `-----------------------------------------------------------'  
     */
    [DEFAULT] = MALEFIS_ISO_SATAN(
        KC_GRV,   KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   \
        KC_TAB,  KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_ENT,   \
        KC_CAPS, KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT, \
        KC_LSFT,  KC_NUBS, KC_Z,    KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH,KC_RSFT, KC_RSFT,\
        KC_LCTL,  KC_LGUI, KC_LALT,             KC_SPC,                       KC_RALT, KC_RGUI, KC_APP, KC_RCTL),


    [LAYERONE] = MALEFIS_ISO_SATAN(
        _______,   KC_F1,    KC_F2,    KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,    KC_F10,    KC_F11, KC_F12,  KC_DEL,   \
        _______,  _______,    _______,    _______, _______, _______, _______, _______, KC_UP, _______,    _______,    _______, _______,KC_ESC,   \
        _______,_______,    _______,    _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT,    KC_HOME, KC_END, KC_PSCR, KC_ESC, \
        _______,  _______,    _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______,\
        _______,  _______, _______,             _______,                       _______, _______, _______, _______)
    [MEDIA] = MALEFIS_ISO_SATAN(
        _______,   _______,    _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______,  _______,   \
        _______,  _______,    _______,    _______, _______, _______, _______, _______, KC_VOLU, _______,    _______,    _______, _______,_______,   \
        _______,_______,    _______,    _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT,    KC_MUTE, KC_MPLY, KC_MSTP, _______, \
        _______,  _______,    _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______,\
        _______,  _______, _______,             _______,                       _______, _______, _______, _______)
};

enum function_id {
    LAUNCH,
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
    [1]  = ACTION_FUNCTION(LAUNCH),
    [2]  = ACTION_FUNCTION(RGBLED_TOGGLE),
    [3]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
    [4]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
    [5]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
    [6]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
    [7]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
    [8]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
    [9]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
    [10] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ENT),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case 0:
            return (record->event.pressed ? 
                    MACRO( D(RALT), T(SPC), U(RALT), END )
                    :MACRO( END ));
            break;
        case 1:
            return (record->event.pressed ? 
                    MACRO( D(LALT), T(F2), U(LALT), END )
                    :MACRO( END ));
            break;
    }
    return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    switch (id) {
        case RGBLED_TOGGLE:
            //led operations
            if (record->event.pressed) {
                rgblight_toggle();
            }
            break;
        case RGBLED_INCREASE_HUE:
            if (record->event.pressed) {
                rgblight_increase_hue();
            }
            break;
        case RGBLED_DECREASE_HUE:
            if (record->event.pressed) {
                rgblight_decrease_hue();
            }
            break;
        case RGBLED_INCREASE_SAT:
            if (record->event.pressed) {
                rgblight_increase_sat();
            }
            break;
        case RGBLED_DECREASE_SAT:
            if (record->event.pressed) {
                rgblight_decrease_sat();
            }
            break;
        case RGBLED_INCREASE_VAL:
            if (record->event.pressed) {
                rgblight_increase_val();
            }
            break;
        case RGBLED_DECREASE_VAL:
            if (record->event.pressed) {
                rgblight_decrease_val();
            }
            break;
        case RGBLED_STEP_MODE:
            if (record->event.pressed) {
                rgblight_step();
            }
            break;
    }
}
