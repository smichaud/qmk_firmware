/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum layers_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYMBOLS,
  _ACCENTS
};

enum custom_keycodes {
  LOWER,
  RAISE,
  A_GRV_L,
  A_GRV_U,
  A_HAT_L,
  A_HAT_U,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_grid(
  KC_GRV,               KC_1,    KC_2,    KC_3,          KC_4,    KC_5,    KC_6,    KC_7,    KC_8,         KC_9,    KC_0,    KC_DEL,
  KC_TAB,               KC_Q,    KC_W,    KC_E,          KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,         KC_O,    KC_P,    KC_BSPC,
  MT(MOD_LGUI, KC_ESC), KC_A,    KC_S,    KC_D,          KC_F,    KC_G,    KC_H,    KC_J,    KC_K,         KC_L,    KC_SCLN, MT(MOD_LGUI, KC_ENT),
  KC_LSFT,              KC_Z,    KC_X,    KC_C,          KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,      KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL,              KC_LALT, _______, OSL(_ACCENTS), LOWER,   RAISE,   RAISE,   KC_SPC,  MO(_SYMBOLS), _______, KC_LALT, KC_LCTL
),

[_LOWER] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_DEL,
  _______, _______, KC_ACL0, KC_MS_U, KC_ACL1, KC_MINS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_GRV,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PLUS, KC_ASTR, KC_BTN1, KC_BTN2, KC_BTN3, KC_BSLS, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_preonic_grid(
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_DQUO, _______,
  _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_ENT,  _______, _______
),

[_ADJUST] = LAYOUT_preonic_grid(
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, BL_TOGG, BL_DEC,  BL_INC,  _______, _______,
  _______, _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_SYMBOLS] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,
  KC_CAPS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DLR,  KC_PERC, KC_CIRC, KC_QUOT, KC_GRV,
  _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_ENT,  KC_PIPE, _______
),

[_ACCENTS] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, A_GRV_U, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,
  _______, A_GRV_L, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DLR,  KC_PERC, KC_CIRC, KC_QUOT, KC_GRV,
  _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case A_GRV_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(25) "00e0\n");
          }
          return false;
          break;
        case A_GRV_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(25) "00c0\n");
          }
          return false;
          break;
        case A_HAT_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(25) "00e2\n");
          }
          return false;
          break;
        case A_HAT_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(25) "00c2\n");
          }
          return false;
          break;
      }
    return true;
};
