/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define THREE_TRNS _______, _______, _______
#define FOUR_TRNS  _______, _______, _______, _______
#define SIX_TRNS   _______, _______, _______, _______, _______, _______

// Layer definition
enum layer_names {
  _0_QWERTY = 0,
  _1_SYMBOLS_NUMPAD,
  _2_MOUSE,
  _3_NAV,
  _4_GAM,
  _5_SYS,
  _6_FN,
};

enum custom_keycodes {
  E_AIGU_MACRO = SAFE_RANGE,
  C_CEDILLE_MACRO,
  NAV_Q,
  NAV_W,
  NAV_E,
  NAV_R,
  NAV_X,
  NAV_C,
  NAV_M,
  NAV_COMMA,
  NAV_DOT,
  NAV_SLASH
};

// Home row and modifiers
#define LT2_A    LT(2,KC_A)
#define LSFT_S   LSFT_T(KC_S)
#define LSFT_W   LSFT_T(KC_W)
#define LT3_D    LT(3,KC_D)
#define LCTL_F   LCTL_T(KC_F)
#define LCTL_R   LCTL_T(KC_R)
#define RCTL_J   RCTL_T(KC_J)
#define RSFT_L   RSFT_T(KC_L)
#define LCTL_SP  LCTL_T(KC_SPC)

enum combos {
  QW_TAB_DEF, QW_TAB_NUM, QW_TAB_NAV,
  ER_TAB_DEF, ER_TAB_NUM, ER_TAB_NAV,
  WE_EAIGU_DEF, WE_EAIGU_NUM, WE_EAIGU_NAV,
  XC_CCEDILLE_DEF, XC_CCEDILLE_NUM, XC_CCEDILLE_NAV,
  SL_CAPS_DEF, SL_CAPS_NUM, SL_CAPS_NAV,
  YU_BSP_DEF, YU_BSP_NUM, YU_BSP_NAV,
  UI_BSP_DEF, UI_BSP_NUM, UI_BSP_NAV,
  DOTSLASH_DEF, DOTSLASH_NUM, DOTSLASH_NAV,
  MCOMMA_DEF, MCOMMA_NUM, MCOMMA_NAV,
  OP_NUMLCK_NUM,
  LSEMICOLON_SINGLEQUOTE,
  JK_SINGLEQUOTE_DEF, JK_SINGLEQUOTE_NUM,
  KL_GRAVE_DEF, KL_GRAVE_NUM
};

const uint16_t PROGMEM qw_def_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM qw_num_combo[] = {KC_EXLM, KC_EQL, COMBO_END};
const uint16_t PROGMEM qw_nav_combo[] = {NAV_Q, NAV_W, COMBO_END};
const uint16_t PROGMEM er_def_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM er_num_combo[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM er_nav_combo[] = {NAV_E, NAV_R, COMBO_END};
const uint16_t PROGMEM we_def_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM we_num_combo[] = {KC_EQL, KC_LPRN, COMBO_END};
const uint16_t PROGMEM we_nav_combo[] = {NAV_W, NAV_E, COMBO_END};
const uint16_t PROGMEM xc_def_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM xc_num_combo[] = {KC_CIRC, KC_LBRC, COMBO_END};
const uint16_t PROGMEM xc_nav_combo[] = {NAV_X, NAV_C, COMBO_END};
const uint16_t PROGMEM sl_def_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM sl_num_combo[] = {KC_ASTR, KC_P6, COMBO_END};
const uint16_t PROGMEM sl_nav_combo[] = {KC_S, KC_RGHT, COMBO_END};
const uint16_t PROGMEM yu_def_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM yu_num_combo[] = {KC_UNDS, KC_P7, COMBO_END};
const uint16_t PROGMEM yu_nav_combo[] = {KC_PGUP, KC_HOME, COMBO_END};
const uint16_t PROGMEM ui_def_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM ui_num_combo[] = {KC_P7, KC_P8, COMBO_END};
const uint16_t PROGMEM ui_nav_combo[] = {KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM dot_slash_def_combo[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM dot_slash_num_combo[] = {KC_P3, KC_PAST, COMBO_END};
const uint16_t PROGMEM dot_slash_nav_combo[] = {NAV_DOT, NAV_SLASH, COMBO_END};
const uint16_t PROGMEM m_comma_def_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM m_comma_num_combo[] = {KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM m_comma_nav_combo[] = {NAV_M, NAV_COMMA, COMBO_END};
const uint16_t PROGMEM op_numlck_combo[] = {KC_P9, KC_PPLS, COMBO_END};
const uint16_t PROGMEM l_semicolon_quote_combo[] = {KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM jk_def_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM jk_num_combo[] = {KC_P4, KC_P5, COMBO_END};
const uint16_t PROGMEM kl_def_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM kl_num_combo[] = {KC_P5, KC_P6, COMBO_END};

combo_t key_combos[] = {
  [QW_TAB_DEF] = COMBO_ACTION(qw_def_combo),
  [QW_TAB_NUM] = COMBO_ACTION(qw_num_combo),
  [QW_TAB_NAV] = COMBO_ACTION(qw_nav_combo),
  [ER_TAB_DEF] = COMBO_ACTION(er_def_combo),
  [ER_TAB_NUM] = COMBO_ACTION(er_num_combo),
  [ER_TAB_NAV] = COMBO_ACTION(er_nav_combo),
  [WE_EAIGU_DEF] = COMBO_ACTION(we_def_combo),
  [WE_EAIGU_NUM] = COMBO_ACTION(we_num_combo),
  [WE_EAIGU_NAV] = COMBO_ACTION(we_nav_combo),
  [XC_CCEDILLE_DEF] = COMBO_ACTION(xc_def_combo),
  [XC_CCEDILLE_NUM] = COMBO_ACTION(xc_num_combo),
  [XC_CCEDILLE_NAV] = COMBO_ACTION(xc_nav_combo),
  [SL_CAPS_DEF] = COMBO_ACTION(sl_def_combo),
  [SL_CAPS_NUM] = COMBO_ACTION(sl_num_combo),
  [SL_CAPS_NAV] = COMBO_ACTION(sl_nav_combo),
  [YU_BSP_DEF] = COMBO_ACTION(yu_def_combo),
  [YU_BSP_NUM] = COMBO_ACTION(yu_num_combo),
  [YU_BSP_NAV] = COMBO_ACTION(yu_nav_combo),
  [UI_BSP_DEF] = COMBO_ACTION(ui_def_combo),
  [UI_BSP_NUM] = COMBO_ACTION(ui_num_combo),
  [UI_BSP_NAV] = COMBO_ACTION(ui_nav_combo),
  [DOTSLASH_DEF] = COMBO_ACTION(dot_slash_def_combo),
  [DOTSLASH_NUM] = COMBO_ACTION(dot_slash_num_combo),
  [DOTSLASH_NAV] = COMBO_ACTION(dot_slash_nav_combo),
  [MCOMMA_DEF] = COMBO_ACTION(m_comma_def_combo),
  [MCOMMA_NUM] = COMBO_ACTION(m_comma_num_combo),
  [MCOMMA_NAV] = COMBO_ACTION(m_comma_nav_combo),
  [OP_NUMLCK_NUM] = COMBO_ACTION(op_numlck_combo),
  [LSEMICOLON_SINGLEQUOTE] = COMBO_ACTION(l_semicolon_quote_combo),
  [JK_SINGLEQUOTE_DEF] = COMBO_ACTION(jk_def_combo),
  [JK_SINGLEQUOTE_NUM] = COMBO_ACTION(jk_num_combo),
  [KL_GRAVE_DEF] = COMBO_ACTION(kl_def_combo),
  [KL_GRAVE_NUM] = COMBO_ACTION(kl_num_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) {
        return;
    }

    switch (combo_index) {
        case QW_TAB_DEF:
        case QW_TAB_NUM:
        case QW_TAB_NAV:
        case ER_TAB_DEF:
        case ER_TAB_NUM:
        case ER_TAB_NAV:
            tap_code(KC_TAB);
            break;
        case WE_EAIGU_DEF:
        case WE_EAIGU_NUM:
        case WE_EAIGU_NAV:
            tap_code(KC_QUOT);
            tap_code(KC_E);
            break;
        case XC_CCEDILLE_DEF:
        case XC_CCEDILLE_NUM:
        case XC_CCEDILLE_NAV:
            tap_code(KC_QUOT);
            tap_code(KC_C);
            break;
        case SL_CAPS_DEF:
        case SL_CAPS_NUM:
        case SL_CAPS_NAV:
            tap_code(KC_CAPS);
            break;
        case YU_BSP_DEF:
        case YU_BSP_NUM:
        case YU_BSP_NAV:
        case UI_BSP_DEF:
        case UI_BSP_NUM:
        case UI_BSP_NAV:
            tap_code(KC_BSPC);
            break;
        case DOTSLASH_DEF:
        case DOTSLASH_NUM:
        case DOTSLASH_NAV:
        case MCOMMA_DEF:
        case MCOMMA_NUM:
        case MCOMMA_NAV:
            tap_code(KC_BSLS);
            break;
        case OP_NUMLCK_NUM:
            tap_code(KC_NUM);
            break;
        case LSEMICOLON_SINGLEQUOTE:
        case JK_SINGLEQUOTE_DEF:
        case JK_SINGLEQUOTE_NUM:
            tap_code(KC_QUOT);
            break;
        case KL_GRAVE_DEF:
        case KL_GRAVE_NUM:
            tap_code(KC_GRV);
            break;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0_QWERTY] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
               KC_NO    ,     KC_Q    ,     KC_W    ,     KC_E    ,     KC_R    ,     KC_T    ,      KC_Y     ,    KC_U     ,     KC_I    ,     KC_O    ,     KC_P    ,    KC_NO     ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┬─────────────┼─────────────┤
               KC_NO    ,     KC_A    ,     KC_S    ,     KC_D    ,     KC_F    ,     KC_G    ,      KC_H     ,    KC_J     ,     KC_K    ,     KC_L    ,    KC_SCLN  ,    KC_NO     ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
               KC_NO    ,     KC_Z    ,     KC_X    ,     KC_C    ,     KC_V    ,     KC_B    ,      KC_N     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,    KC_SLSH  ,    KC_NO     ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┴─────────────┴───────────────────────────╯
                                                         KC_ESC   ,    KC_TAB   ,    KC_SPC   ,     KC_ENT    ,    KC_DEL   ,   KC_GRV
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
	[_1_SYMBOLS_NUMPAD] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              KC_NO     ,   KC_EXLM   ,    KC_EQL   ,   KC_LPRN   ,   KC_RPRN   ,   KC_PIPE   ,     KC_UNDS   ,     KC_P7   ,     KC_P8   ,     KC_P9   ,   KC_PPLS   ,   KC_NO     ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┬─────────────┼─────────────┤
              KC_NO     ,   KC_PERC   ,    KC_ASTR  ,   KC_LCBR   ,   KC_RCBR   ,   KC_AMPR   ,     KC_AT     ,     KC_P4   ,     KC_P5   ,     KC_P6   ,   KC_PMNS   ,   KC_NO     ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_HASH   ,    KC_CIRC  ,   KC_LBRC   ,   KC_RBRC   ,   KC_TILD   ,     KC_DLR    ,     KC_P1   ,     KC_P2   ,     KC_P3   ,   KC_PAST   ,   KC_NO     ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┴─────────────┴───────────────────────────╯
                                                      KC_NO       , TG(_5_SYS)  ,   _______   ,     _______   ,   _______   ,     KC_P0
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
	[_2_MOUSE] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              KC_NO     ,   _______   ,   _______   ,   _______   ,   _______   ,   _______   ,     MS_WHLU   ,   MS_WHLL   ,   MS_UP     ,   MS_WHLR   ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   _______   ,   _______   ,   _______   ,   _______   ,   _______   ,     MS_WHLD   ,   MS_LEFT   ,   MS_DOWN   ,   MS_RGHT   ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   _______   ,   _______   ,   _______   ,   _______   ,   _______   ,     KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,   _______   ,     MS_BTN1    ,  MS_BTN2   ,   MS_BTN3
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
	[_3_NAV] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              KC_NO     ,   NAV_Q     ,   NAV_W     ,   NAV_E     ,   NAV_R     ,   KC_NO     ,     KC_PGUP   ,   KC_HOME   ,   KC_UP     ,   KC_END    ,   KC_PSCR   ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_NO     ,   _______   ,   _______   ,   _______   ,   _______   ,     KC_PGDN   ,   KC_LEFT   ,   KC_DOWN   ,   KC_RGHT   ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_NO     ,   NAV_X     ,   NAV_C     ,   KC_NO     ,   KC_NO     ,     KC_INS    ,   NAV_M     ,   NAV_COMMA ,   NAV_DOT   ,   NAV_SLASH ,   KC_NO     ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,   _______   ,     _______    ,  KC_APP    ,   KC_NO
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
    [_4_GAM] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
               KC_GRV   ,     KC_1    ,     KC_2    ,     KC_3    ,     KC_4    ,     KC_5    ,      KC_Y     ,    KC_U     ,     KC_I    ,     KC_O    ,     KC_P    ,   _______   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
          LSFT_T(KC_TAB),     KC_Q    ,     KC_W    ,     KC_E    ,     KC_R    ,     KC_T    ,      KC_H     ,    KC_J     ,     KC_K    ,    KC_L     ,    KC_UP    ,   _______   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_LCTL   ,     KC_Z    ,     KC_X    ,     KC_C    ,     KC_V    ,     KC_B    ,      KC_N     ,    KC_M     ,    KC_COMM  ,   KC_LEFT   ,    KC_DOWN  ,   KC_RGHT   ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                         KC_GRV   ,    KC_LALT  ,    KC_SPC   ,     KC_ENT    ,    KC_DEL   ,  TG(_4_GAM)
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
   [_5_SYS] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,     KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,     QK_RBT    ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,     QK_BOOT   ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        KC_NO     ,   KC_NO     ,    KC_NO    ,     KC_NO      ,  KC_NO     ,  TG(_5_SYS)
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
   [_6_FN] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              KC_NO     ,   KC_NO     ,    KC_F7    ,    KC_F8    ,    KC_F9    ,   KC_F10    ,     KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_NO     ,    KC_F4    ,    KC_F5    ,    KC_F6    ,   KC_F11    ,     KC_NO     ,   KC_NO     ,   KC_NO     ,    KC_UP    ,   KC_NO     ,   KC_NO     ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              KC_NO     ,   KC_NO     ,    KC_F1    ,    KC_F2    ,    KC_F3    ,   KC_F12    ,     KC_NO     ,   KC_NO     ,   KC_LEFT   ,   KC_DOWN   ,   KC_RGHT   ,   KC_NO     ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,   _______   ,     _______   ,   _______   ,   _______
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    )
};

// https://github.com/stasmarkin/sm_td
smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // home row mods
        SMTD_MT(KC_F, KC_LEFT_CTRL, 280)
        SMTD_MT(KC_J, KC_RIGHT_CTRL, 280)
        SMTD_MT(KC_S, KC_LSFT, 280)
        SMTD_MT(KC_L, KC_RSFT, 280)
        SMTD_MT(KC_ASTR, KC_LEFT_SHIFT, 280)
        // home row Layer Toggles
        SMTD_LT(KC_A, 2, 200)
        SMTD_LT(KC_D, 3, 200)
        // Thumb keys mods/layer toggles
        SMTD_MT(KC_ESC, KC_LEFT_GUI, 200)
        SMTD_MT(KC_TAB, KC_LEFT_ALT, 200)
        SMTD_MT(KC_SPC, KC_LEFT_CTRL, 200)
        SMTD_LT(KC_ENT, 3, 200)
        SMTD_LT(KC_DEL, 1, 200)
        SMTD_LT(KC_GRV, 6, 200)

    }

    return SMTD_RESOLUTION_UNHANDLED;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return rotation;
    }
}
/*
void render_crkbd_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}
*/
/*
#define KEYLOG_LEN 5
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}
*/

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _0_QWERTY:
            oled_write_P(PSTR(" QRTY"), false);
            break;
        case _1_SYMBOLS_NUMPAD:
            oled_write_P(PSTR("SymNum"), false);
            break;
    }
}

void render_layer_state(void) {
    uint8_t layer = biton32(layer_state);
    oled_write_P(PSTR("Layr:\n"), false);
    switch (layer)
    {
        case _0_QWERTY:
            oled_write_P(PSTR("QWRTY\n"), true);
        break;
        case _1_SYMBOLS_NUMPAD:
            oled_write_P(PSTR("SyNum\n"), true);
        break;
        case _2_MOUSE:
            oled_write_P(PSTR("Mouse\n"), true);
        break;
        case _3_NAV:
            oled_write_P(PSTR("Nav\n"), true);
        break;
        case _4_GAM:
            oled_write_P(PSTR("Game\n"), true);
        break;
        case _5_SYS:
            oled_write_P(PSTR("Sys\n"), true);
        break;
        case _6_FN:
            oled_write_P(PSTR("FN\n"), true);
        break;
        default:
            oled_write_P(PSTR("???\n"), true);
    }
    oled_write_P(PSTR("\n"), true);
}

void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("\nLock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S\n"), led_state.scroll_lock);
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("\nMods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G\n"), (modifiers & MOD_MASK_GUI));
}

void render_bootmagic_status(void) {
    /* Show Ctrl-Gui Swap options */
    /*static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };*/
    oled_write_P(PSTR("BTMGK"), false);
    /*oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][0], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][0], keymap_config.swap_lctl_lgui);
    oled_write_P(PSTR(" "), false);
    oled_write_P(logo[0][1], !keymap_config.swap_lctl_lgui);
    oled_write_P(logo[1][1], keymap_config.swap_lctl_lgui);*/
    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    //render_default_layer_state();
    render_layer_state();
    render_keylock_status(host_keyboard_led_state());
    render_mod_status(get_mods());
    //render_bootmagic_status();
    //render_keylogger_status();
}

bool oled_task_user(void) {
    //update_log();
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        //render_crkbd_logo();
    }
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= NAV_Q && keycode <= NAV_SLASH) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case E_AIGU_MACRO:
                tap_code(KC_QUOT);
                tap_code(KC_E);
                return false;
            case C_CEDILLE_MACRO:
                tap_code(KC_QUOT);
                tap_code(KC_C);
                return false;
        }
        //add_keylog(keycode);
    }
    return true;
}
