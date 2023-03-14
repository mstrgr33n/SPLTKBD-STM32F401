#include <stdio.h>
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};


enum custom_keycodes {
    RGBRST = SAFE_RANGE
};

#define RBR_RGU MT(MOD_RGUI, KC_RBRC)
#define F12_RGU MT(MOD_RGUI, KC_F12)
#define PLS_LCT MT(MOD_LCTL, KC_PPLS)
#define EQL_LCT MT(MOD_LCTL, KC_EQL)
#define APP_LCT MT(MOD_LCTL, KC_APP)
#define EQL_RCT MT(MOD_RCTL, KC_EQL)
#define QUO_RCT MT(MOD_RCTL, KC_QUOT)
#define APP_RCT MT(MOD_RCTL, KC_APP)
#define MIN_RCT MT(MOD_RCTL, KC_MINS)
#define EQL_LAL MT(MOD_LALT, KC_EQL)
#define BSL_RAL MT(MOD_RALT, KC_BSLS)
#define BSP_LSH MT(MOD_LSFT, KC_BSPC)
#define SPC_RSH MT(MOD_RSFT, KC_SPC)
#define DEL_RSE LT(_RAISE, KC_DEL)
#define TAB_RSE LT(_RAISE, KC_TAB)
#define ENT_LWR LT(_LOWER, KC_ENT)
#define ESC_LWR LT(_LOWER, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  KC_LGUI, KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, RGUI_T(KC_RBRC),
           KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
           KC_LALT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, BSL_RAL,
                                      TAB_RSE, SPC_RSH, ENT_LWR,      ESC_LWR, BSP_LSH, DEL_RSE
),

[_LOWER] = LAYOUT(
  _______, KC_UNDS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  F12_RGU,
           PLS_LCT, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, MIN_RCT,
           EQL_LAL, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
                                      _______, _______, _______,      _______, _______, _______
),

[_RAISE] = LAYOUT(
  KC_CALC, KC_NLCK, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS,      KC_VOLU, KC_HOME, KC_PSCR, KC_PGUP, KC_SLCK, KC_CAPS, KC_MYCM,
           EQL_LCT, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PPLS,      KC_MUTE, KC_LEFT, KC_UP,   KC_RGHT, KC_INS,  APP_RCT,
            KC_EQL, KC_P0,   KC_P1,   KC_P2,   KC_P3,   KC_PDOT,      KC_VOLD, KC_END,  KC_DOWN, KC_PGDN, KC_PAUS, _______,
                                      _______, _______, _______,      _______, _______, _______
),

[_ADJUST] = LAYOUT(
  QK_BOOT,   RGBRST,  KC_ASUP, KC_ASTG, KC_ASDN, _______, _______,      _______, _______, KC_ASDN, KC_ASTG, KC_ASUP, RGBRST,  QK_BOOT,
           RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,      _______, _______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
           RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,      _______, _______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD,
                                      _______, SH_TG,   _______,      _______, SH_TG,   _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,224,240,248,168, 28,  6,  2,  6,  6, 10, 12, 12,252,  8,152, 48,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192, 96, 32, 48, 16, 16, 16, 16, 16, 48, 32,224,192,128,  0,  0,  0,  0,  0,  0,128,192,112, 16, 24,  8,  8,  8, 24, 16, 48,240,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,160,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,125,255, 94,255,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 28, 51, 16, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,129,231,127, 63,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,128,224,113, 63, 31,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 32, 96,128,  0,120,  0,123,  0,120,  0,240,  0,  0,  0,
        0,  0,  0,  0,254,254, 16, 24,  4,  4, 60,240, 28,  4,  4, 12,248,  0,  0,252,252, 16, 24,  6,  2,  2,  6, 14, 12,  0,  0,  0,  0,255, 81,134, 73,255,  0,  0,  0,  0,  0, 28, 28,  4,  4,  4,  4,  4,244, 12,252, 28,  0,  0,252,252, 16, 24,  6,  2,  2,  6, 14, 12,  0,  0,  0,  0,  0,  5,  7,  0,  2,  2,  2,  2,  2,  1,  3,  6, 12,184,240,  0,  0,  0,  0,  0,  2,  3,  0,  1,  1,  1,  1,  1,  1,  1,  3, 14,188,248,  0,  0,252,252, 48, 24,  4,  4, 12,248,240,  0,  1,  3,  7,  2,  1,  2,  7,  3,  1,  0,  0,  0,
        0,  0,  0, 48, 63, 63,  0,  0,  0,  0, 56, 63, 56,  0,  0, 56, 63, 56,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0, 96, 96,  0,  0,  1,  7, 12, 16, 51, 96, 64, 64,128,128, 64,192,192,  0,192, 64, 96, 63, 60,  7,  0,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6, 24, 48, 32, 64, 64, 64, 64, 64, 96, 32, 48, 48, 24, 28, 14,  3,  0,  0,  0,  4,  4, 28, 48, 96, 64, 64, 64, 64, 64, 96, 32, 48, 24, 13,  7,  0, 48, 63, 63,  0,  0,  0,  0, 48, 63, 63, 48,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUML * ") : PSTR("NUML   "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAPS * ") : PSTR("CAPS   "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCRL * ") : PSTR("SCRL   "), false);
}

char keylog_str[24] = {};

const char code_to_name[0xFF] = {
//   0    1    2    3    4    5    6    7    8    9    A    B    c    D    E    F
    182, ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',  // 0x
    'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2',  // 1x
    '3', '4', '5', '6', '7', '8', '9', '0',  20,  19,  17,  29,  22, '-', '=', '[',  // 2x
    ']','\\', '#', ';','\'', '`', ',', '.', '/', 188, 149, 150, 151, 152, 153, 154,  // 3x
    155, 156, 157, 158, 159, 181, 191, 190, ' ', ' ', 185, 183,  16, 186, 184,  26,  // 4x
     27,  25,  24, 189, '/', '*', '-', '+', ' ', '1', '2', '3', '4', '5', '6', '7',  // 5x
    '8', '9', '0', '.', ' ', 187, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 6x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 7x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 8x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // 9x
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 214, 215, 216, 217, 218, 219, 220, 221,  // Ax
    ' ', ' ', 213, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Bx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Cx
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Dx
    'C', 'S', 'A', 'W', ' ', 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',  // Ex
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '        // Fx
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
            keycode = keycode & 0xFF;
            } else if (keycode > 0xFF)
            {
                keycode = 0;
            }
    name = code_to_name[keycode];
  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%3d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}

bool oled_task_kb(void) {
  if (!oled_task_user()) { return false; }
  if (is_keyboard_master()) {
        render_status();
        oled_render_keylog();
    } else {
        render_logo();
    }
    return true;
}
#endif
