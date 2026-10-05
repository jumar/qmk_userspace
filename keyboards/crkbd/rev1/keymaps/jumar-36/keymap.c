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
  _2_MOUSE_MEDIA,
  _3_NAV,
  _4_GAM,
  _5_RGB,
  _6_FN,
};

enum custom_keycodes {
  RGB_LYR = SAFE_RANGE, // can always be here
  E_AIGU_MACRO,
  C_CEDILLE_MACRO
};

// Home row and modifiers
#define LT2_A    LT(2,KC_A)
#define LSFT_S   LSFT_T(KC_S)
#define LSFT_W   LSFT_T(KC_W)
#define ALT_BSP  LALT_T(KC_BSPC)
#define LT3_D    LT(3,KC_D)
#define LCTL_F   LCTL_T(KC_F)
#define LCTL_R   LCTL_T(KC_R)
#define RCTL_J   RCTL_T(KC_J)
#define LT5_K    LT(5,KC_K)
#define RSFT_L   RSFT_T(KC_L)
#define LSFT_KP  LSFT_T(KC_CAPS)
#define LCTL_SP  LCTL_T(KC_SPC)
#define LT3_SPC  LT(3,KC_SPC)
#define LT3_ENT  LT(3,KC_ENT)
#define LT1_DEL  LT(1,KC_DEL)
#define LT6_GRV  LT(6,KC_GRV)
#define LGU_ESC  LGUI_T(KC_ESC)
#define ALT_BSP  LALT_T(KC_BSPC)

enum combos {
  QW_TAB,
  ER_TAB,
  WE_EAIGU,
  XC_CCEDILLE,
  SL_CAPS,
  YU_BSP,
  UI_BSP,
  DOTSLASH_BACKSLASH,
  MCOMMA_BACKSLASH,
  IO_NUMLCK,
  LSEMICOLON_SINGLEQUOTE,
  JK_SINGLEQUOTE,
  DC_CCEDILLE
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM eaigu_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM ccedille_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM sl_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM DOTSLASH_COMBO[] = {KC_DOT, KC_SLSH, COMBO_END};
const uint16_t PROGMEM MCOMMA_BACKSLASH_COMBO[] = {KC_COMM, KC_BSLS, COMBO_END};
const uint16_t PROGMEM io_numlck_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM lsemicolon_singlequote_combo[] = {KC_SCLN, KC_QUOT, COMBO_END};
const uint16_t PROGMEM jk_singlequote_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM dc_ccedille_combo[] = {KC_D, KC_C, COMBO_END};

combo_t key_combos[] = {
  [QW_TAB] = COMBO(qw_combo, KC_TAB),
  [ER_TAB] = COMBO(er_combo, KC_TAB),
  [WE_EAIGU] = COMBO(eaigu_combo, E_AIGU_MACRO),
  [XC_CCEDILLE] = COMBO(ccedille_combo, C_CEDILLE_MACRO),
  [SL_CAPS] = COMBO(sl_combo, KC_CAPS),
  [YU_BSP] = COMBO(yu_combo, KC_BSPC),
  [UI_BSP] = COMBO(ui_combo, KC_BSPC),
  [DOTSLASH_BACKSLASH] = COMBO(DOTSLASH_COMBO, KC_BSLS),
  [MCOMMA_BACKSLASH] = COMBO(MCOMMA_BACKSLASH_COMBO, KC_BSLS),
  [IO_NUMLCK] = COMBO(io_numlck_combo, KC_NUM),
  [LSEMICOLON_SINGLEQUOTE] = COMBO(lsemicolon_singlequote_combo, KC_QUOT),
  [JK_SINGLEQUOTE] = COMBO(jk_singlequote_combo, KC_QUOT),
  [DC_CCEDILLE] = COMBO(dc_ccedille_combo, C_CEDILLE_MACRO)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0_QWERTY] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
               KC_TAB   ,     KC_Q    ,     KC_W    ,     KC_E    ,     KC_R    ,     KC_T    ,      KC_Y     ,    KC_U     ,     KC_I    ,     KC_O    ,     KC_P    ,    KC_BSPC  ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┬─────────────┼─────────────┤
               KC_CAPS  ,     KC_A    ,     KC_S    ,     KC_D    ,     KC_F    ,     KC_G    ,      KC_H     ,    KC_J     ,     KC_K    ,     KC_L    ,    KC_SCLN  ,    KC_QUOT  ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
               KC_LSFT  ,     KC_Z    ,     KC_X    ,     KC_C    ,     KC_V    ,     KC_B    ,      KC_N     ,    KC_M     ,   KC_COMM   ,    KC_DOT   ,    KC_SLSH  ,    KC_SLSH  ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┴─────────────┴───────────────────────────╯
                                                         KC_ESC   ,    KC_BSPC  ,    KC_SPC   ,     KC_ENT    ,    KC_DEL   ,   KC_GRV
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
	[_1_SYMBOLS_NUMPAD] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              _______   ,   KC_EXLM   ,    KC_EQL   ,   KC_LPRN   ,   KC_RPRN   ,   KC_PIPE   ,     KC_UNDS   ,     KC_7    ,     KC_8    ,     KC_9    ,   KC_PLUS   ,   _______   ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┬─────────────┼─────────────┤
              _______   ,   KC_PERC   ,    KC_ASTR  ,   KC_LCBR   ,   KC_RCBR   ,   KC_AMPR   ,     KC_AT     ,     KC_4    ,     KC_5    ,     KC_6    ,   KC_MINS   ,   _______   ,
        //├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              _______   ,   KC_HASH   ,    KC_CIRC  ,   KC_LBRC   ,   KC_RBRC   ,   KC_TILD   ,     KC_DLR    ,     KC_1    ,     KC_2    ,     KC_3    ,   KC_ASTR   ,   _______   ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┴─────────────┴───────────────────────────╯
                                                      TG(_5_RGB)  , TG(_4_GAM)  ,   _______   ,     _______   ,   _______   ,     KC_0
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
	[_2_MOUSE_MEDIA] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,     MS_WHLU   ,   XXXXXXX   ,   MS_UP     ,   XXXXXXX   ,   MS_WHLU   ,   MS_ACL0   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              XXXXXXX   ,   _______   ,   _______   ,   XXXXXXX   ,   KC_LCTL   ,   XXXXXXX   ,     MS_WHLD   ,   MS_LEFT   ,   MS_DOWN   ,   MS_RGHT   ,   MS_WHLD   ,   MS_ACL1   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              _______   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,     XXXXXXX   ,   KC_VOLD   ,   KC_MUTE   ,   KC_VOLU   ,   XXXXXXX   ,   MS_ACL2   ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,   _______   ,     MS_BTN1    ,  KC_MPLY   ,   KC_MFFD
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
	[_3_NAV] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              KC_PSCR   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,     KC_PGUP   ,   KC_HOME   ,   KC_UP     ,   KC_END    ,   XXXXXXX   ,   KC_PSCR   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              XXXXXXX   ,   XXXXXXX   ,   KC_LSFT   ,   _______   ,   _______   ,   XXXXXXX   ,     KC_PGDN   ,   KC_LEFT   ,   KC_DOWN   ,   KC_RGHT   ,   KC_APP    ,   XXXXXXX   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,     KC_INS    ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,   _______   ,     _______    ,  KC_APP    ,   XXXXXXX
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
   [_5_RGB] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,     XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              UG_TOGG   ,   UG_NEXT   ,   UG_SATU   ,   UG_HUEU   ,   UG_VALU   ,   UG_SPDU   ,     QK_RBT    ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              XXXXXXX   ,   UG_PREV   ,   UG_SATD   ,   UG_HUED   ,   UG_VALD   ,   UG_SPDD   ,     QK_BOOT   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,    RGB_LYR  ,     UG_TOGG    ,  XXXXXXX   ,  TG(_5_RGB)
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    ),
   [_6_FN] = LAYOUT_split_3x6_3(
        //╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮ ╭─────────────┬─────────────┬─────────────┬─────────────┬─────────────┬─────────────╮
              XXXXXXX   ,   XXXXXXX   ,    KC_F7    ,    KC_F8    ,    KC_F9    ,   KC_F10    ,     XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              XXXXXXX   ,   XXXXXXX   ,    KC_F4    ,    KC_F5    ,    KC_F6    ,   KC_F11    ,     XXXXXXX   ,   _______   ,   XXXXXXX   ,   _______   ,    KC_UP    ,   XXXXXXX   ,
        //├─────────────├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┤
              XXXXXXX   ,   XXXXXXX   ,    KC_F1    ,    KC_F2    ,    KC_F3    ,   KC_F12    ,     XXXXXXX   ,   XXXXXXX   ,   XXXXXXX   ,   KC_LEFT   ,   KC_DOWN   ,   KC_RGHT   ,
        //╰─────────────┴─────────────┴─────────────┼─────────────┼─────────────┼─────────────┤ ├─────────────┼─────────────┼─────────────┼─────────────┴───────────────────────────╯
                                                        _______   ,   _______   ,   _______   ,     _______   ,   _______   ,   _______
        //                                          ╰─────────────┴─────────────┴─────────────╯ ╰─────────────┴─────────────┴─────────────╯
    )
};

// https://github.com/stasmarkin/sm_td
smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // home row mods
        SMTD_MT(KC_F, KC_LEFT_CTRL)
        SMTD_MT(KC_J, KC_RIGHT_CTRL)
        SMTD_MT(KC_S, KC_LSFT)
        SMTD_MT(KC_L, KC_RSFT)
        // home row Layer Toggles
        SMTD_LT(KC_A, 2)
        SMTD_LT(KC_D, 3)
        SMTD_LT(KC_K, 5)
        // Thumb keys mods/layer toggles
        SMTD_MT(KC_ESC, KC_LEFT_GUI)
        SMTD_MT(KC_BSPC, KC_LEFT_ALT)
        SMTD_MT(KC_SPC, KC_LEFT_CTRL)
        SMTD_LT(KC_ENT, 3)
        SMTD_LT(KC_DEL, 1)
        SMTD_LT(KC_GRV, 6)

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
        case _2_MOUSE_MEDIA:
            oled_write_P(PSTR("MoMed\n"), true);
        break;
        case _3_NAV:
            oled_write_P(PSTR("Nav\n"), true);
        break;
        case _4_GAM:
            oled_write_P(PSTR("Game\n"), true);
        break;
        case _5_RGB:
            oled_write_P(PSTR("RGB\n"), true);
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case E_AIGU_MACRO:
                SEND_STRING("é");
                return false;
            case C_CEDILLE_MACRO:
                SEND_STRING("ç");
                return false;
        }
        //add_keylog(keycode);
    }
    return true;
}
#endif
