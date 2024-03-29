#include QMK_KEYBOARD_H
#include "muse.h"

enum layers_names {
  _LINUX,
  _WINDOWS,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYMBOLS,
  _ACCENTS,
  _PERMANENT
};

enum custom_keycodes {
  LINUX = SAFE_RANGE,
  WINDOWS,
  LOWER,
  RAISE,
  A_GRV_L,
  A_GRV_U,
  A_HAT_L,
  A_HAT_U,
  C_CED_L,
  C_CED_U,
  E_GRV_L,
  E_GRV_U,
  E_HAT_L,
  E_HAT_U,
  E_ACU_L,
  E_ACU_U,
  E_UML_L,
  E_UML_U,
  I_HAT_L,
  I_HAT_U,
  I_UML_L,
  I_UML_U,
  O_HAT_L,
  O_HAT_U,
  U_HAT_L,
  U_HAT_U,
  U_GRV_L,
  U_GRV_U
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LINUX] = LAYOUT_planck_grid(
  KC_TAB,               KC_Q,    KC_W,     KC_E,          KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,         KC_O,           KC_P,    KC_BSPC,
  MT(MOD_LGUI, KC_ESC), KC_A,    KC_S,     KC_D,          KC_F,    KC_G,    KC_H,    KC_J,    KC_K,         KC_L,           KC_SCLN, MT(MOD_LGUI, KC_ENT),
  KC_LSFT,              KC_Z,    KC_X,     KC_C,          KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,      KC_DOT,         KC_SLSH, KC_RSFT,
  KC_LCTL,              KC_LALT, KC_LGUI,  OSL(_ACCENTS), LOWER,   RAISE,   RAISE,   KC_SPC,  MO(_SYMBOLS), MO(_PERMANENT), KC_LALT, KC_RCTL
),

// Basically use swap space/raise (use actual space) + windows keys
[_WINDOWS] = LAYOUT_planck_grid(
  KC_TAB,  KC_Q,    KC_W,     KC_E,          KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,         KC_O,           KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,     KC_D,          KC_F,    KC_G,    KC_H,    KC_J,   KC_K,         KC_L,           KC_SCLN, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,     KC_C,          KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,      KC_DOT,         KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LALT, KC_LGUI,  OSL(_ACCENTS), LOWER,   KC_SPC,  KC_SPC,  RAISE,  MO(_SYMBOLS), MO(_PERMANENT), KC_LALT, KC_RCTL
),

[_LOWER] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_DEL,
  _______, _______, KC_ACL0, KC_MS_U, KC_ACL1, KC_MINS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_GRV,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PLUS, KC_ASTR, KC_BTN1, KC_BTN2, KC_BTN3, KC_BSLS, KC_PIPE,
  _______, _______, _______, _______, _______, _______, _______, KC_UNDS, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
  _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_DQUO, _______,
  _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, KC_1,    KC_2,    KC_3,    _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_ENT,  _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
  KC_CAPS, KC_F1,   KC_F2,         KC_F3,   KC_F4,   KC_P7,   KC_P8,   KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
  _______, KC_F5,   KC_F6,         KC_F7,   KC_F8,   KC_P9,   KC_P0,   KC_MPLY, KC_MPRV, KC_MNXT, _______, _______,
  _______, KC_F9,   KC_F10,        KC_F11,  KC_F12,  KC_APP,  KC_RGUI, BL_TOGG, BL_DEC,  BL_INC,  _______, _______,
  _______, _______, QK_BOOTLOADER, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_SYMBOLS] = LAYOUT_planck_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,
  KC_CAPS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_MINS, KC_EQL,  KC_DLR,  KC_PERC, KC_CIRC, KC_QUOT, KC_GRV,
  _______, KC_LT,   KC_GT,   KC_LCBR, KC_RCBR, KC_PLUS, KC_ASTR, KC_EXLM, KC_AT,   KC_HASH, KC_BSLS, KC_BSLS,
  _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT,  KC_ENT,  KC_PIPE, _______
),

[_ACCENTS] = LAYOUT_planck_grid(
  _______, A_GRV_U, E_GRV_U, E_HAT_U, E_ACU_U, E_UML_U, U_GRV_U, U_GRV_L, I_HAT_L, I_HAT_U, O_HAT_L, O_HAT_U,
  _______, A_GRV_L, E_GRV_L, E_HAT_L, E_ACU_L, E_UML_L, U_HAT_U, U_HAT_L, I_UML_L, I_UML_U, _______, _______,
  _______, A_HAT_L, A_HAT_U, C_CED_L, C_CED_U, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_PERMANENT] = LAYOUT_planck_grid(
  _______, _______, WINDOWS, _______, _______, _______,       _______, _______, _______, _______, _______, _______,
  KC_CAPS, LINUX,   _______, _______, _______, WINDOWS,       _______, _______, _______, LINUX,   _______, _______,
  _______, _______, _______, _______, _______, QK_BOOTLOADER, _______, LINUX,   _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______
)

};

#define MACRO_DELAY 45
float linux_sound[][2] = SONG(SOUND_MARIO_MUSHROOM);
float windows_sound[][2] = SONG(SOUND_MARIO_GAMEOVER);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case LINUX:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_LINUX);
          }
          PLAY_SONG(linux_sound);
          return false;
          break;
        case WINDOWS:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_WINDOWS);
          }
          PLAY_SONG(windows_sound);
          return false;
          break;
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
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00e0\n");
          }
          return false;
          break;
        case A_GRV_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00c0\n");
          }
          return false;
          break;
        case A_HAT_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00e2\n");
          }
          return false;
          break;
        case A_HAT_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00c2\n");
          }
          return false;
          break;
        case C_CED_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00e7\n");
          }
          return false;
          break;
        case C_CED_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00c7\n");
          }
          return false;
          break;
        case E_GRV_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00e8\n");
          }
          return false;
          break;
        case E_GRV_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00c8\n");
          }
          return false;
          break;
        case E_HAT_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00ea\n");
          }
          return false;
          break;
        case E_HAT_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00ca\n");
          }
          return false;
          break;
        case E_ACU_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00e9\n");
          }
          return false;
          break;
        case E_ACU_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00c9\n");
          }
          return false;
          break;
        case E_UML_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00eb\n");
          }
          return false;
          break;
        case E_UML_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00cb\n");
          }
          return false;
          break;
        case I_HAT_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00ee\n");
          }
          return false;
          break;
        case I_HAT_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00ce\n");
          }
          return false;
          break;
        case I_UML_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00ef\n");
          }
          return false;
          break;
        case I_UML_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00cf\n");
          }
          return false;
          break;
        case O_HAT_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00f4\n");
          }
          return false;
          break;
        case O_HAT_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00d4\n");
          }
          return false;
          break;
        case U_HAT_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00fb\n");
          }
          return false;
          break;
        case U_HAT_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00db\n");
          }
          return false;
          break;
        case U_GRV_L:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00f9\n");
          }
          return false;
          break;
        case U_GRV_U:
          if (record->event.pressed) {
            SEND_STRING(SS_LCTL(SS_LSFT("u")) SS_DELAY(MACRO_DELAY) "00d9\n");
          }
          return false;
          break;
      }
    return true;
};
