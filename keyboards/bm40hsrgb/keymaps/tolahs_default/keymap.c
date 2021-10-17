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
#include "muse.h"
#include "keymap_turkish_q.h"
#include "sendstring_turkish_q.h"



enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TR
};
#define HOME_QUOT   RCTL_T(FIX_QUOT)
enum custom_keycodes {
    FIX_I  = SAFE_RANGE,
    FIX_IDOT,
    FIX_G,//ğ, Ğ
    FIX_C, // ç , Ç
    FIX_S, //ş, Ş,
    FIX_U,//ü, Ü
    FIX_O, //ö, Ö
    FIX_SLSH,
    FIX_DOT,
    FIX_COMM,
    FIX_QUOT,
    FIX_SCLN

};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define TR  LT(_TR,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Gui  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,             TR_Q,    TR_W,    TR_E,    TR_R,    TR_T,    TR_Y,    TR_U,    FIX_I,   TR_O,    TR_P,    KC_BSPC,
    LCTL_T(KC_ESC),     TR_A,    TR_S,    TR_D,    TR_F,    TR_G,    TR_H,    TR_J,    TR_K,    TR_L,    FIX_SCLN,  HOME_QUOT,
    KC_LSFT,            KC_Z,    TR_X,    TR_C,    TR_V,    TR_B,    TR_N,    TR_M,    TR_COMM, TR_DOT,  FIX_SLSH, RSFT_T(KC_ENT) ,
    RGB_TOG, KC_LCTL,   KC_LGUI, KC_LALT, LOWER,   TR,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   <  |  >  | | Home | End  |     |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    TR_TILD, TR_EXLM, TR_AT,   TR_HASH, TR_DLR,  TR_PERC, TR_CIRC, TR_AMPR,    TR_ASTR,    TR_LPRN, TR_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   TR_UNDS,    TR_PLUS,    TR_LCBR, TR_RCBR, TR_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TR_LABK,    TR_RABK,     KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______,    _______,       _______,    KC_MNXT,     KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  ´   |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    TR_GRV,  TR_1,    TR_2,    TR_3,    TR_4,    TR_5,    TR_6,    TR_7,    TR_8,    TR_9,    TR_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   TR_MINS, TR_EQL,  TR_LBRC, TR_RBRC, TR_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TR_ACUT, _______, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
[_TR] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, FIX_G,     FIX_U,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______ ,  FIX_S,   FIX_IDOT,
    _______, _______, _______, _______, _______, _______, _______, _______,  FIX_O,   FIX_C,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FIX_C:
            if (record->event.pressed) {
                register_code16(TR_CCED);
            } else {
                unregister_code16(TR_CCED);
            }
            break;
        case FIX_G:
            if (record->event.pressed) {
                register_code16(TR_GBRV);
            } else {
                unregister_code16(TR_GBRV);
            }
            break;
        case FIX_O:
            if (record->event.pressed) {
                register_code16(TR_ODIA);
            } else {
                unregister_code16(TR_ODIA);
            }
            break;
        case FIX_S:
            if (record->event.pressed) {
                register_code16(TR_SCED);
            } else {
                unregister_code16(TR_SCED);
            }
            break;
        case FIX_U:
            if (record->event.pressed) {
                register_code16(TR_UDIA);
            } else {
                unregister_code16(TR_UDIA);
            }
            break;
        case FIX_I: {
            static uint16_t code;
            if (record->event.pressed) {
                code = (keyboard_report->mods & (MOD_BIT(KC_CAPS) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_I : TR_IDOT;
                register_code16(code);
            } else {
                unregister_code16(code);
            }
            break;
        }
        case FIX_IDOT: {
            static uint16_t code;
            if (record->event.pressed) {
                code = (keyboard_report->mods & (MOD_BIT(KC_CAPS) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_IDOT : TR_I;
                register_code16(code);
            } else {
                unregister_code16(code);
            }
            break;
        }
        case FIX_SLSH: {
            static uint16_t code;
            if (record->event.pressed) {
                code = (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_QUES : TR_SLSH;
                register_code16(code);
            } else {
                unregister_code16(code);
            }
            break;
        }
        case FIX_QUOT: {
            static uint16_t code;
            if (record->event.pressed) {
                code = (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_QUOT : TR_DQUO;
                register_code16(code);
            } else {
                unregister_code16(code);
            }
            break;
        }
        case HOME_QUOT: {
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16((keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_QUOT : TR_DQUO);
                }
                return false;
            }
            break;
        }
        case FIX_SCLN: {
            static uint16_t code;
            if (record->event.pressed) {
                code = (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_COLN : TR_SCLN;
                register_code16(code);
            } else {
                unregister_code16(code);
            }
            break;
        }
    }
    return true;
};
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_QUOT:
        case TR:
            return false;
        default:
            return true;
    }
};
