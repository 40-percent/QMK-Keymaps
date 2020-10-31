#include QMK_KEYBOARD_H
#include "quantum.h"
#include "tominabox1.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_split_spacewrap(
	KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
	_______________HOMEROW_MOD_________________,
	_______________COLEMAK3____________________,
    DM_REC1, DM_PLY1, KC_NAV_ENT, KC_NUM_SPC, KC_NAV_ENT, RGUI(RSFT(RCTL(KC_4)))
  ),

  [_NUM_SYM] = LAYOUT_33_split_spacewrap(
	__________________NUM_1____________________,
	__________________NUM_2____________________,
	KC_BSLS, __________________NUM_3____________________, KC_DOT, KC_GRV,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT_33_split_spacewrap(
    RESET,  KC_NO,  KC_NO, KC_NO, KC_NO,  KC_NO,  KC_PGDN,    KC_UP,  KC_PGUP,    TD(TD_RESET),
    RGB_TOG,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
    RGB_MOD,  DM_REC1,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_COMM,   KC_DOT,  KC_BSLS,
    RGB_MOD, KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, RGUI(RSFT(KC_S))
  ),

  [_GAME] = LAYOUT_33_split_spacewrap(
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_L, KC_U, KC_Y, TO(_BASE),
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_N, KC_E, KC_I, KC_O,
	KC_LCTRL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_M, KC_COMM, KC_DOT, KC_SLSH,
  KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS, KC_TRNS
  ),
};
