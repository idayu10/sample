#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_jp.h"

#define XXXXXXX KC_NO

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Esc    |   1  |   2  |   3  |   4  |   5  |  \   |           |  ^   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |  ]   |   Y  |   U  |   I  |   O  |   P  |   @    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   :    |
 * |--------+------+------+------+------+------|  L1  |           |  -   |------+------+------+------+------+--------|
 * | LCtrl  |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |   _    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Win  | LAlt |      |      | îº/ëS|                                       | ÉJÉi |  L2  | RAlt | RCtrl|RShift|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Alt | Copy |       |  Å©  |  Å®  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Space |  Bs  |Paste |       |  Å™  |Del   |Enter |
 *                                 |/Ctrl |      |------|       |------|      |/Shift|
 *                                 |      |      |  Tab |       |  Å´  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_ESC,      KC_1,    KC_2,    KC_3,    KC_4, KC_5,  JP_YEN,            JP_CIRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     JP_MINS,
  KC_TAB,      KC_Q,    KC_W,    KC_E,    KC_R, KC_T, JP_LBRC,            JP_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     JP_AT,
  KC_LSFT,     KC_A,    KC_S,    KC_D,    KC_F, KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN,  JP_COLN,
  KC_LCTRL,    KC_Z,    KC_X,    KC_C,    KC_V, KC_B,  TG(1),             JP_MINS, KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH,  JP_UNDS,
  KC_LGUI,  KC_LALT, XXXXXXX, XXXXXXX, JP_ZKHK,                                             JP_KANA, TG(2),   KC_RALT, KC_RCTRL, KC_RSFT,
                                         KC_LALT, LCTL(KC_C),             KC_LEFT, KC_RIGHT,
                                                  LCTL(KC_V),             KC_UP,
                         LCTL_T(KC_SPC), KC_BSPC,     KC_TAB,             KC_DOWN, KC_DEL, RSFT_T(KC_ENT)
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |    ?    |   !  |   @  |   {  |   }  |   |  | Print|           | Page | Home |   7  |   8  |   9  |   *  |   =    |
 * |---------+------+------+------+------+------|Screen|           |  Up  |------+------+------+------+------+--------|
 * |    ;    |   #  |   $  |   (  |   )  |   `  |------|           |------| End  |   4  |   5  |   6  |   +  |   -    |
 * |---------+------+------+------+------+------|      |           | Page |------+------+------+------+------+--------|
 * |    :    |   %  |   ^  |   [  |   ]  |   ~  |  L0  |           | Down |   &  |   1  |   2  |   3  |   /  |   _    |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |   "  |   '  |   <  |   >  |                                       |   ,  |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Alt | Copy |       |  Å©  |  Å®  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Space |  Bs  |Paste |       |  Å™  |Del   |Enter |
 *                                 |/Ctrl |      |------|       |------|      |/Shift|
 *                                 |      |      |  Tab |       |  Å´  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  XXXXXXX,
  JP_QUES, JP_EXLM,   JP_AT, JP_LCBR, JP_RCBR, JP_PIPE, KC_PSCR,     KC_PGUP, KC_HOME, KC_7,    KC_8,    KC_9,    JP_ASTR,  JP_EQL,
  JP_SCLN, JP_HASH,  JP_DLR, JP_LPRN, JP_RPRN,  JP_GRV,                        KC_END, KC_4,    KC_5,    KC_6,    JP_PLUS, JP_MINS,
  JP_COLN, JP_PERC, JP_CIRC, JP_LBRC, JP_RBRC, JP_TILD, KC_TRNS,     KC_PGDN, JP_AMPR, KC_1,    KC_2,    KC_3,    JP_SLSH, JP_UNDS,
  XXXXXXX, JP_DQUO, JP_QUOT, JP_LABK, JP_RABK,                                         JP_COMM, JP_DOT,  KC_0,    JP_EQL,  XXXXXXX,
                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
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
 *   |      |      |      | Lclk | Rclk |                                       |      |  L0  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F1  |  F2  |       |Vol Dw|Vol Up|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, LCTL(KC_A), LCTL(KC_E), XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                       KC_LEFT, KC_DOWN,    KC_UP,      KC_RIGHT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2,                                         XXXXXXX,    KC_TRNS,    XXXXXXX, XXXXXXX, XXXXXXX,

                                                   KC_F1, KC_F2,     KC__VOLDOWN, KC__VOLUP,
                                                        XXXXXXX,     XXXXXXX,
                                      XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};
