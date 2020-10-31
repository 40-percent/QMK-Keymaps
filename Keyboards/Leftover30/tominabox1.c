/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "tominabox1.h"
#include "quantum.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
                  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,KC_QUOTE, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D, KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
                  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT,     KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      KC_MPLY, KC_NAV_ENT,                               KC_NUM_SPC,                              KC_NAV_ENT, KC_SLSH
  //`-----------------------------------------------------------------------------------------------------------'
  ),

  [_NUM_SYM] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
                  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_EXLM, KC_AT, KC_HASH, TD(TD_DLR_LP), KC_PERC, KC_CIRC, TD(TD_AMP_RP), KC_ASTR, KC_EQUAL, KC_MINS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
                  DM_REC1, DM_RSTP, DM_PLY1,  KC_UNDS,  KC_UNDS,  KC_RPRN,  KC_RBRC,  KC_COMM, KC_DOT, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      RESET, KC_TRNS,                               KC_TRNS,                              KC_TRNS, RGUI(RSFT(RCTL(KC_4)))
  //`-----------------------------------------------------------------------------------------------------------'
  ),

    [_NAV] = LAYOUT_all(
  //,-----------------------------------------------------------------------------------------------------------.
                  KC_F1,  KC_F2, KC_F3, KC_F4,  KC_NO,  KC_NO, KC_PGDN, KC_UP,  KC_PGUP,  KC_NO,   TD(TD_RESET),
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
               KC_NO, KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
                    RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_VAI,  KC_NO,   KC_NO,  KC_NO,  KC_COMM,   KC_DOT, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|--------+--------+--------+--------+--------+--------|
      RESET, KC_TRNS,                               KC_TRNS,                              KC_TRNS, KC_RCTL
  //`-----------------------------------------------------------------------------------------------------------'
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // Left encoder
    if (IS_LAYER_ON(_NUM_SYM)) {
          tap_code16((clockwise == true) ? LCTL(KC_Y) : LCTL(KC_Z));
        } else if (IS_LAYER_ON(_NAV)) {
          tap_code16((clockwise == true) ? S(KC_DOWN) : S(KC_UP));
        } else {
          tap_code16((clockwise == true) ? KC_MFFD : KC_MRWD);
        }

    }
    else if (index == 1) { //right encoder
     if (IS_LAYER_ON(_NUM_SYM)) {
          tap_code16((clockwise == true) ? LCTL(KC_Y) : LCTL(KC_Z));
        } else if (IS_LAYER_ON(_NAV)) {
          tap_code16((clockwise == true) ? S(KC_DOWN) : S(KC_UP));
        } else {
          tap_code16((clockwise == true) ? KC_MFFD : KC_MRWD);
        }
}
}

// for exsample customize of LED inducator
bool led_update_user(led_t led_state) {
    writePin(B10, IS_LAYER_ON(_NAV));
    writePin(B11, IS_LAYER_ON(_NUM_SYM));
    return false;
}
