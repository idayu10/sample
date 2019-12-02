#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_jp.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

#define XXXXXXX KC_NO
#define _______ KC_TRNS

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  | YEN  |           |  ^   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * | Shift  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Cmd    |   Z  |   X  |   C  |   V  |   B  |  L1  |           |  -   |   N  |   M  |   ,  |   .  |   /  |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | win  |  Alt |      |      |hankau|                                       |kana  |      |  Alt |  Cmd | Shift|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Alt |Ctl(C)|       |  ←   |   →  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Ctl(V)|       |  ↑   |        |      |
 *                                 | SPC  | BS   |------|       |------| Del    |Enter |
 *                                 | / Cmd|      |  Tab |       |  ↓   | / Lt2  |/Shift|
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,  JP_YEN,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,  JP_LBRC,
        KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,     KC_G,
        KC_LGUI,  KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    TG(1),
        KC_LCTRL, KC_LALT, XXXXXXX,  XXXXXXX, JP_ZHTG,

                                                    KC_LALT,  LCTL(KC_C),
                                                              LCTL(KC_V),
                                        GUI_T(KC_SPC), KC_BSPC,   KC_TAB,

        // right hand
        JP_CIRC, KC_6,  KC_7,  KC_8,    KC_9,   KC_0,    JP_MINS,
        JP_RBRC, KC_Y,  KC_U,  KC_I,    KC_O,   KC_P,    JP_AT,
                 KC_H,  KC_J,  KC_K,    KC_L,   JP_SCLN, JP_COLN,
        JP_MINS, KC_N,  KC_M,  JP_COMM, JP_DOT, JP_SLSH, JP_UNDS,
                      JP_KANA, XXXXXXX, KC_RALT,KC_RGUI, KC_RSFT,

        KC_LEFT, KC_RIGHT,
        KC_UP,
        KC_DOWN, LT(2,KC_DEL), RSFT_T(KC_ENT)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    ?    |  !   |  @   |  {   |  }   |   |  |      |           |      |  ↑   |  7   |  8   |   9  |  *   |  =     |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    ;    |  #   |  $   |  (   |  )   |  `   |------|           |------|  ↓   |  4   |  5   |   6  |  +   |  -     |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    :    |  %   |  ^   |  [   |  ]   |  ~   |   L0 |           |      |  &   |  1   |  2   |   3  |  /   |  _     |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |  "   |  '   |  <   |  >   |                                       |  ,   |  .   |   0  |  =   |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Alt |Ctl(C)|       |  ←   |   →  |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Ctl(V)|       |  ↑   |        |      |
 *                                 | SPC  | BS   |------|       |------| Del    |Enter |
 *                                 | / Cmd|      |  Tab |       |  ↓   | / Lt2  |/Shift|
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
        KC_ESC,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,
       JP_QUES,JP_EXLM,  JP_AT,JP_LCBR,JP_RCBR,JP_PIPE,_______,
       JP_SCLN,JP_HASH, JP_DLR,JP_LPRN,JP_RPRN, JP_GRV,
       JP_COLN,JP_PERC,JP_CIRC,JP_LBRC,JP_RBRC,JP_TILD,KC_TRNS,
       _______, JP_DQT,JP_QUOT,  JP_LT,  JP_GT,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
         KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11, KC_F12,_______,
       _______,   KC_UP,    KC_7,   KC_8,   KC_9,JP_ASTR, JP_EQL,
                KC_DOWN,    KC_4,   KC_5,   KC_6,JP_PLUS,JP_MINS,
       _______, JP_AMPR,    KC_1,   KC_2,   KC_3,JP_SLSH,JP_UNDS,
                         JP_COMM, JP_DOT,   KC_0, JP_EQL,_______,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Lclk | MsUp | Rclk |      |      |           |      |      |Ctl(A)|ctl(E)|      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| left | down |  up  |right |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | F1   | F2   |       |Vol Dw|Vol Up|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RESET,   _______, _______, _______, _______, _______, _______,
       _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                              KC_F1,  KC_F2,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______,  _______, _______,
       _______,  _______, LCTL(KC_A), LCTL(KC_E),  _______,  _______, _______,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
       _______,  _______, _______, _______, _______,  _______, _______,
                          _______, _______, _______,  _______, _______,
       KC__VOLDOWN, KC__VOLUP,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};