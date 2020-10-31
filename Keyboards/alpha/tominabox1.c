#include QMK_KEYBOARD_H
#include "tominabox1.h"

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,  KC_QUOT, //Y+QUOTE = KC_BSPC
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S),LSFT_T(KC_T),KC_D,KC_H,RSFT_T(KC_N),RCTL_T(KC_E),RALT_T(KC_I),RGUI_T(KC_O),
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
          KC_Z,     KC_X,     KC_C,LT(_NAV, KC_V),  LT(_NUM_SYM,KC_B), KC_K,     LT(_FKEY,KC_M), KC_DOT
  //`---------+---------+---------+---------+-------------------+---------+---------+---------+---------'
  ),

  [_NUM_SYM] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
          KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0, //0 + 9 = KC_BSPC
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_EXLM,    KC_AT,  KC_HASH,   TD(TD_DLR_LP), KC_PERC, KC_CIRC, TD(TD_AMP_RP), KC_ASTR,   KC_EQL,  KC_MINS,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_GRV,  KC_BSLS,  KC_UNDS,  KC_ENT,       KC_TRNS     ,  KC_COMM,   KC_DOT,  KC_SLSH
  //`---------+---------+---------+---------+-------------------+---------+---------+---------+---------'
  ),

  [_NAV] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
       KC_GESC,KC_MS_BTN1,KC_MS_UP,  KC_MS_BTN2,  KC_WH_U,  KC_GRV,KC_PGDN,    KC_UP,  KC_PGUP,  TD(TD_RESET),
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
      RGB_TOG,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,KC_WH_D,KC_HOME, KC_LEFT,  KC_DOWN,  KC_RGHT,   KC_END,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,     KC_ENT       ,  KC_COMM,   KC_DOT,  KC_SLSH
  //`---------+---------+---------+---------+-------------------+---------+---------+---------+---------'
  ),
  //
  [_FKEY] = LAYOUT(
  //,---------------------------------------------------------------------------------------------------.
         KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
        KC_GRV,  KC_TILD,  KC_HASH,   KC_DLR,  KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,   KC_F11,  KC_F12,
  //|---------+---------+---------+---------+---------+---------+---------+---------+---------+---------|
       KC_DEL ,  RGB_HUI,  RGB_SAI,  RGB_VAI,      KC_LPRN      ,  RESET,  KC_RPRN,  KC_TRNS
  //`---------+---------+---------+---------+-------------------+---------+---------+---------+---------'
  )

};

int RGB_current_mode;
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

  bool result = false;
  switch (keycode) {
    #ifdef RGBLIGHT_ENABLE
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    case KC_LSFT && KC_DOT:
        tap_code16(KC_QUES);
    default:
      result = true;
      break;
  }

  return result;
}

void keyboard_post_init_keymap(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
}
