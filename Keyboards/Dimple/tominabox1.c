#include QMK_KEYBOARD_H
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = LAYOUT_wrapper(
    KC_ESC, _______________COLEMAK1____________________, KC_BSPC,
    KC_CTLTB,  _______________HOMEROW_MOD_________________, KC_QUOT,
    KC_LSFT,   _______________COLEMAK3____________________,
    DYN_REC_START1, DYN_REC_STOP, DYN_MACRO_PLAY1, KC_NAV_ENT,  KC_NUM_SPC,  KC_NAV_ENT, MO(_FKEY), KC_NO
	),

	[_NUM_SYM] = LAYOUT_wrapper(
    KC_GRV,  __________________NUM_1____________________, KC_BSPC,
    KC_TILD, __________________NUM_2____________________, KC_PIPE,
    KC_DEL,  KC_NO, __________________NUM_3____________________, KC_DOT, KC_SLSH,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_NAV] = LAYOUT_wrapper(
    KC_NO, ___________________NAV1____________________, TD(TD_RESET),
    KC_NO,___________________NAV2____________________, KC_BSLS,
    KC_LTOG,   ___________________NO______________________,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[_FKEY] = LAYOUT_wrapper(
    RESET,___________________FKEY1___________________, KC_F11,
    KC_NO,  ___________________NO______________________, KC_NO,
    KC_NO,   ___________________NO______________________,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
/*
	[_GAMER] = LAYOUT_wrapper(
		___________________GAMER1__________________,
		___________________GAMER2__________________,
		___________________GAMER3__________________,
		___________________GAMER4__________________
	),*/
};

void keyboard_post_init_user(void) {
    // rgblight_sethsv_range(0,0,0,0, 50);
		// rgblight_sethsv_at(0, 0, 0, 24);
		// rgblight_set();
		writePinHigh(E6);
}
//
// bool led_update_kb(led_t led_state){
//   if(led_state.caps_lock){
//       rgblight_setrgb_at(122, 255, 50, 38);
//       rgblight_mode_noeeprom(0);
//       rgblight_sethsv_range(0,0,0,0, 50);
//   } else{
//       rgblight_sethsv_at(0, 0, 0, 38);
//
//   }
//     return true;
// }
