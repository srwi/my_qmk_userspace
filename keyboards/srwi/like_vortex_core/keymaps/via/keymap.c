#include QMK_KEYBOARD_H

#include "raw_hid.h"

#define ___x___ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, KC_BSPC,
    LT(2,KC_TAB), KC_A, KC_S,  KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,          KC_SLSH,
    KC_LCTL, KC_LWIN, KC_LALT, MO(4),     LT(3, KC_SPC),           KC_SPC,           KC_RALT, MO(2),   KC_RGUI, KC_RCTL
  ),
  [1] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  ),
  [2] = LAYOUT(
    KC_ESC,  KC_VOLD, _______, KC_VOLU, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, KC_DEL,
    _______, AU_TOGG, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,           _______,
    _______, _______, _______, CK_TOGG, _______, _______, KC_END,  MU_TOGG, KC_SCRL, KC_PAUS, KC_NUM,           _______,
    _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  ),
  [3] = LAYOUT(
    KC_TRNS, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_BSLS,
    _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  ),
  [4] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,           KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  ),
  [5] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,          _______,          _______,          _______, _______, _______, _______
  )
};

// float startup[][2] = SONG(
//   B__NOTE(_REST),
//   E__NOTE(_GS6),
//   E__NOTE(_A6),
//   S__NOTE(_REST),
//   ED_NOTE(_E7),
//   S__NOTE(_REST),
//   ED_NOTE(_A7),
// );

// void keyboard_post_init_user(void) {
//     PLAY_SONG(startup);
// }

layer_state_t default_layer_state_set_user(layer_state_t state) {
	eeconfig_update_default_layer(state);
	return state;
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    uint8_t *value_id = &(data[2]);
    uint8_t *value_data = &(data[3]);

    switch(*value_id) {
        case 1:
            layer_move(*value_data);
            break;
        default:
            *command_id = id_unhandled;
            break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t layer = get_highest_layer(state);
    uint8_t data[RAW_EPSIZE] = { 0 };
    data[0] = 0x01;
    data[1] = layer;
    raw_hid_send(data, RAW_EPSIZE);
    return state;
}
