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
// qmk c2json -km default -kb bm40hsrgb --no-cpp  /e/tolga/Repos/qmk_firmware/keyboards/bm40hsrgb/keymaps/tolahs/keymap.c
//  qmk format-json /e/tolga/Repos/qmk_firmware/keyboards/bm40hsrgb/keymaps/tolahs/keymap.json
#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_turkish_q.h"

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV,
  _NUMPAD,
  _SC
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAV MO(_NAV)
#define NPAD  LT(5,KC_HOME)
#define SC  MO(_SC)

// Left-hand home row mods
#define HOME_A LGUI_T(TR_A)
#define HOME_S LALT_T(TR_S)
#define HOME_D LSFT_T(TR_D)
#define HOME_F LCTL_T(TR_F)
// Right-hand home row mods
#define HOME_J RCTL_T(TR_J)
#define HOME_K RSFT_T(TR_K)
#define HOME_L LALT_T(TR_L)
#define HOME_SCED RGUI_T(TR_SCED)

// Left-hand home row mods for symboals
#define HOME_COLN   LGUI_T(MT_COLN)
#define HOME_EQL    LALT_T(MT_EQL)
#define HOME_LCBR   LSFT_T(MT_LCBR)
#define HOME_RCBR   LCTL_T(MT_RCBR)
// Right-hand home row mods symboals
#define HOME_LPRN   RCTL_T(MT_LPRN)
#define HOME_RPRN   RSFT_T(MT_RPRN)
#define HOME_PLUS   LALT_T(MT_PLUS)
#define HOME_SCLN   RGUI_T(MT_SCLN)

// #define FIXI M(0)
enum custom_keycodes {
    MT_COLN = SAFE_RANGE,
    MT_EQL,
    MT_LCBR,
    MT_RCBR ,
    MT_LPRN,
    MT_RPRN,
    MT_PLUS,
    MT_SCLN,
    FIX_I,
    COLUMNSL,
    NEXTWIN,
    PREVWIN
    // FIX_CIRC,
    // FIX_TILD,
    // FIX_GRV,
    // FIX_ACUT
};
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool is_column_select_active = false;
uint16_t column_select_timer = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
 * ,----------------------------------------------------------------------------------------.
 * | Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |(i) I |   O  |   P  | Bksp    |
 * |-------+------+------+------+------+------+------+------+------+------+------+---------|
 * | Esc   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ş  | Enter   |
 * |-------+------+------+------+------+------+------+------+------+------+------+---------|
 * | SC    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   Ö  |   Ç  |   .  |   i     |
 * |-------+------+------+------+------+------+------+------+------+------+------+---------|
 * | Npad | PgDn | PgUp | GUI  |Lower |  NAV-Space  |Raise | GUI  |PWin  | NWin  |CtlTab   |
 * `---------------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    KC_TAB,   TR_Q,    TR_W,    TR_E,    TR_R,    TR_T,    TR_Y,   TR_U,     FIX_I,   TR_O,     TR_P,        KC_BSPC,
    KC_ESC,   HOME_A,  HOME_S,  HOME_D,  HOME_F,  TR_G,    TR_H,   HOME_J,   HOME_K,  HOME_L,   HOME_SCED,   KC_ENT,
    SC,       TR_Z,    TR_X,    TR_C,    TR_V,    TR_B,    TR_N,   TR_M,     TR_ODIA, TR_CCED,  TR_DOT,      TR_I,
    NPAD,     KC_PGDN, KC_PGUP, KC_LGUI, LOWER,     LT(4,KC_SPC),  RAISE,    KC_RGUI, PREVWIN,  NEXTWIN,     LCTL(KC_TAB)
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  Del |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   Ğ  |  Ü   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  "   |   :  |  =   |  {   |  }   |  \   |  /   |    ( |   )  |   +  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  ~   |   ?  |  `   |  <   |   >  |   -  |  _   |   [  |   ]  |   ,  |   .  |  "|" |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   ´  |      |      |     space   |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_DEL,  TR_EXLM,   TR_AT,     TR_HASH,   TR_DLR,    TR_PERC, TR_CIRC, TR_AMPR,   TR_ASTR,   TR_GBRV,   TR_UDIA,   KC_BSPC,
    TR_DQUO, HOME_COLN, HOME_EQL,  HOME_LCBR, HOME_RCBR, TR_BSLS, TR_SLSH, HOME_LPRN, HOME_RPRN, HOME_PLUS, HOME_SCLN, TR_QUOT,
    TR_TILD, TR_QUES,   TR_GRV,    TR_LABK,   TR_RABK,   TR_MINS, TR_UNDS, TR_LBRC,   TR_RBRC,   TR_COMM,   TR_DOT,    TR_PIPE,
    _______, _______,   TR_ACUT,   _______, _______,      KC_SPC,      _______,       KC_MNXT,   KC_VOLD,   KC_VOLU,   KC_MPLY
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  Del |   1  |   2  |  3   |   4  |   5  |  6   |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  Ctl  | Sft | Alt  |  GUI |  ?   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | é    |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_DEL,  TR_1,    TR_2,    TR_3,    TR_4,    TR_5,    TR_6,       TR_7,       TR_8,       TR_9,    TR_0,     KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_RCTL,    KC_RSFT,    KC_RALT, KC_RGUI,  TR_QUES,
    TR_EACU, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     _______,    _______,    _______,  _______, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD,    KC_VOLU, KC_MPLY
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
/*Navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |ColSel|      |      |      | PgUp |   ▲  | PgDn | Ins  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | CLk  |  GUI |  Alt |  Sft | Ctl  |      |      |  ◀  |   ▼  |   ▶  |PrtSc |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | home | Del  |  end |ScLk  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |     |       |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_mit(
    _______,_______, _______, COLUMNSL, _______, _______, _______, KC_PGUP, KC_UP,    KC_PGDOWN, KC_INS,   _______,
    KC_CAPS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,  _______, _______, KC_LEFT, KC_DOWN,  KC_RIGHT,  KC_PSCR,  _______,
    _______, _______, _______,  _______, _______, _______, _______, KC_HOME, KC_DEL,   KC_END,    KC_SLCK,  _______,
    _______, _______, _______, _______, _______,      _______,      _______,  _______, _______,   _______,  _______
),
/* Numpad Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |  1   |  2   |   3  |   4  |  5   |  6   |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Enter|   4  |   5  |   6  |   +  |   *  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Enter|   1  |   2  |   3  |   +  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |     |   RGBTogl   |   0  |   0  |   .  |   ,  |   =   |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_mit(
    _______, KC_P1 ,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_P6,   KC_P7, KC_P8, KC_P9, KC_PMNS, KC_BSPC,
    _______, _______, _______, _______, _______, _______, KC_PENT, KC_P4, KC_P5, KC_P6, KC_PPLS, KC_PAST,
    _______, _______, _______, _______, _______, _______, KC_PENT, KC_P1, KC_P2, KC_P3, KC_PPLS, KC_PSLS,
    _______, _______, _______, _______, _______,        RGB_TOG,   KC_P0, KC_P0, KC_SLSH, KC_PDOT, KC_PEQL
),
[_SC] = LAYOUT_planck_mit(
    _______, _______, _______, _______, _______, _______, _______, MEH(TR_1),  MEH(TR_2),  MEH(TR_3),   MEH(TR_4),   _______,
    _______, _______, _______, _______, _______, _______, _______, MEH(TR_5),  MEH(TR_6),  MEH(TR_7),   MEH(TR_8),   _______,
    _______, _______, _______, _______, _______, _______, _______, MEH(TR_9),  MEH(KC_FN15),MEH(KC_F16), MEH(KC_F17), _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_COLN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_COLN);
                }
                return false;
            }
            break;
        case HOME_EQL:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_EQL);
                }
                return false;
            }
            break;
        case HOME_LCBR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_LCBR);
                }
                return false;
            }
            break;
        case HOME_RCBR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_RCBR);
                }
                return false;
            }
            break;
        case HOME_LPRN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_LPRN);
                }
                return false;
            }
            break;
        case HOME_RPRN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_RPRN);
                }
                return false;
            }
            break;
        case HOME_PLUS:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_PLUS);
                }
                return false;
            }
            break;
        case HOME_SCLN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                   tap_code16(TR_SCLN);
                }
                return false;
            }
            break;
        // Fix i & I issue
        case FIX_I: {
            static uint8_t code;
            if (record->event.pressed) {
                code = (keyboard_report->mods & (MOD_BIT(KC_CAPS) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) ? TR_I : TR_IDOT;
                register_code(code);
            } else {
                unregister_code(code);
            }
            break;
        }
        case NEXTWIN:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case PREVWIN:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_LSFT);
                register_code(KC_TAB);
                unregister_code(KC_LSFT);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case COLUMNSL:
            if (!is_column_select_active) {
                is_column_select_active = true;
                register_code(KC_LCTRL);
                register_code(KC_LSFT);
                register_code(KC_LALT);
            }
            column_select_timer = timer_read();
            break;
        case KC_UP:
        case KC_DOWN:
        case KC_LEFT:
        case KC_RIGHT:
            if (record->event.pressed) {
                if (is_column_select_active) {
                    column_select_timer = timer_read();
                }
            }
            break;
            // case FIX_CIRC:
            //     // fix dead key for '^'
            //     if (record->event.pressed) {
            //         // when keycode QMKURL is pressed
            //         SEND_STRING(TR_CIRC);
            //     } else {
            //         // when keycode QMKURL is released
            //     }
            //     break;

            // case FIX_TILD:
            //     // fix dead key for '~'
            //     if (record->event.pressed) {
            //        SEND_STRING(TR_TILD);
            //     }
            //     break;
            // case FIX_GRV:
            //     // fix dead key for '`'
            //     if (record->event.pressed) {
            //         SEND_STRING(TR_GRV);
            //     }
            //     break;
            // case FIX_ACUT:
            //     // fix dead key for '´'
            //     if (record->event.pressed) {
            //         SEND_STRING(TR_ACUT);
            //     }
            //     break;
            return false;
    }
    return true;
};
void matrix_scan_user(void) {  // The very important timer.
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 800) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
    if (is_column_select_active) {
        if (timer_elapsed(column_select_timer) > 1500) {
                unregister_code(KC_LCTRL);
                unregister_code(KC_LSFT);
                unregister_code(KC_LALT);
            is_column_select_active = false;
        }
    }
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_SPC):
            return false;
        case RCTL_T(KC_ENT):
            return false;
        case NEXTWIN:
        case PREVWIN:
        case LCTL(KC_TAB):
            return false;
        default:
            return true;
    }
};
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_SCED:
            // Recommended
            return TAPPING_TERM + 200;
        case HOME_A:
            // Recommended
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
};
