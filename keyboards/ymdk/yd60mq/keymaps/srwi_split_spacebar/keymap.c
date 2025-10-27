#include QMK_KEYBOARD_H

#include "raw_hid.h"
#include "usb_descriptor.h"

#define _______ KC_NO

enum my_keycodes {
  QS_UP = SAFE_RANGE,
  QS_DOWN,
  QS_LEFT,
  QS_RGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_all(
		KC_ESC   , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_MINS , KC_EQL  , _______ , KC_BSPC ,
		KC_TAB   , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC , KC_RBRC , KC_BSLS ,
		KC_CAPS  , KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN , KC_QUOT , _______ , KC_ENT  ,
		KC_LSFT  , _______ , KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_N    , KC_M    , KC_COMM , KC_DOT  , KC_SLSH , _______ , KC_RSFT , _______ ,
		KC_LCTL  , KC_LGUI , KC_LALT ,          KC_SPC   ,       KC_SPC   ,          KC_SPC   ,              KC_RALT , MO(3)   , _______ , KC_RGUI , KC_RCTL
	),

	[1] = LAYOUT_all(
		KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , _______ , KC_TRNS ,
		KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
		MO(3)    , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , _______ , KC_TRNS ,
		KC_TRNS  , _______ , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , _______ , KC_TRNS , _______ ,
		KC_TRNS  , KC_TRNS , KC_TRNS ,          KC_TRNS  ,       KC_TRNS  ,          KC_TRNS  ,             KC_TRNS  , KC_TRNS , _______ , KC_TRNS , KC_TRNS
	),

	[2] = LAYOUT_all(
		KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , _______ , KC_TRNS ,
		KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,
		KC_TRNS  , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , _______ , KC_TRNS ,
		KC_TRNS  , _______ , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , _______ , KC_TRNS , _______ ,
		KC_TRNS  , KC_TRNS , KC_TRNS ,          KC_TRNS  ,       KC_TRNS  ,          KC_TRNS  ,             KC_TRNS  , KC_TRNS , _______ , KC_TRNS , KC_TRNS
	),

	[3] = LAYOUT_all(
		KC_GRV   , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  , _______ , KC_DEL  ,
		KC_TRNS  , KC_MRWD , QS_UP   , KC_MFFD , KC_TRNS , KC_TRNS , KC_TRNS , KC_PGUP , KC_UP   , KC_PGDN , KC_PSCR , KC_SCRL , KC_PAUS , KC_TRNS ,
		KC_TRNS  , QS_LEFT , QS_DOWN , QS_RGHT , KC_MUTE , KC_TRNS , KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_ENT  , KC_DEL  , _______ , KC_TRNS ,
		KC_TRNS  , _______ , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_END  , KC_TRNS , DF(0)   , DF(1)   , DF(3)   , _______ , KC_TRNS , _______ ,
		KC_TRNS  , KC_TRNS , KC_TRNS ,          KC_TRNS  ,       KC_TRNS  ,          KC_TRNS  ,             KC_TRNS  , KC_TRNS , _______ , KC_TRNS , KC_TRNS
	)

};

layer_state_t default_layer_state_set_user(layer_state_t state) {
	eeconfig_update_default_layer(state);
	return state;
}

// Switch layer using the command (replace L with the desired layer):
// ./hidapitester.exe --vidpid 594D/604D --usagePage 0xff60 --usage 0x61 --open --send-output 0,9,0,1,L --close
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

static bool quick_scroll_up_active = false;   // Track if QS_UP is active
static bool quick_scroll_down_active = false; // Track if QS_DOWN is active
static bool quick_scroll_left_active = false; // Track if QS_LEFT is active
static bool quick_scroll_right_active = false; // Track if QS_RGHT is active
static uint16_t last_scroll_time = 0;         // Timer for repeats

void perform_quick_scroll_action(uint16_t keycode) {
    switch (keycode) {
        case QS_UP:
            SEND_STRING(SS_DOWN(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_UP));
            SEND_STRING(SS_UP(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_UP));
            break;

        case QS_DOWN:
            SEND_STRING(SS_DOWN(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_DOWN));
            SEND_STRING(SS_UP(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_DOWN));
            break;
        case QS_LEFT:
            SEND_STRING(SS_TAP(X_LEFT));
            break;
        case QS_RGHT:
            SEND_STRING(SS_TAP(X_RIGHT));
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QS_UP:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_UP);
                quick_scroll_up_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_up_active = false;
            }
            return false;

        case QS_DOWN:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_DOWN);
                quick_scroll_down_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_down_active = false;
            }
            return false;
        case QS_LEFT:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_LEFT);
                quick_scroll_left_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_left_active = false;
            }
            return false;
        case QS_RGHT:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_RGHT);
                quick_scroll_right_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_right_active = false;
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

void matrix_scan_user(void) {
    static const uint16_t repeat_interval = 12; // Time between repeats in milliseconds

    if (timer_elapsed(last_scroll_time) > repeat_interval) {
        if (quick_scroll_up_active) {
            perform_quick_scroll_action(QS_UP);
        }

        if (quick_scroll_down_active) {
            perform_quick_scroll_action(QS_DOWN);
        }

        if (quick_scroll_left_active) {
            perform_quick_scroll_action(QS_LEFT);
        }

        if (quick_scroll_right_active) {
            perform_quick_scroll_action(QS_RGHT);
        }

        last_scroll_time = timer_read();
    }
}
