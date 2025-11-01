#include QMK_KEYBOARD_H

#include <quick_scroll.h>
#include <layer_handling.h>

#define _______ KC_NO

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
