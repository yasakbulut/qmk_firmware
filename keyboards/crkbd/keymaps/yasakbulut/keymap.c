#include QMK_KEYBOARD_H

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A,
    CKC_S,
    CKC_D,
    CKC_F,
    CKC_J,
    CKC_K,
    CKC_L,
    CKC_SCLN,
    SMTD_KEYCODES_END,
};

#include "features/sm_td.h"


#define LAYOUT LAYOUT_split_3x6_3

// layers
enum {
    LAYER_BASE,
    LAYER_NAV,
    LAYER_MOUSE,
    LAYER_MEDIA,
    LAYER_NUM,
    LAYER_SYM,
    LAYER_FUN,
    LAYER_GAME,
};

// convenience definitions
#define XXXXX KC_NO

#define NAV(KEY) LT(LAYER_NAV, KEY)
#define MOUSE(KEY) LT(LAYER_MOUSE, KEY)
#define MEDIA(KEY) LT(LAYER_MEDIA, KEY)
#define NUM(KEY) LT(LAYER_NUM, KEY)
#define GAME(KEY) LT(LAYER_GAME, KEY)
#define FUN(KEY) LT(LAYER_FUN, KEY)

// end convenience definitions

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
    KC_GRV,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_EQL,       \
    XXXXX,         CKC_A,         CKC_S,         CKC_D,         CKC_F,         KC_G,          KC_H,          CKC_J,         CKC_K,         CKC_L,         CKC_SCLN,      KC_QUOT,      \
    XXXXX,         KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_N,          KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,       KC_MINS,      \
                                                 FUN(KC_ESC),   NAV(KC_BSPC),  NUM(KC_TAB),   MOUSE(KC_ENT), GAME(KC_SPC),  MEDIA(KC_DEL)
    ),

    [LAYER_NAV] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_LPRN,       KC_LCBR,       KC_RCBR,       KC_LBRC,       KC_RBRC,       KC_RPRN,      \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       CW_TOGG,       XXXXX,        \
    XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_LPRN,       KC_RPRN,       KC_PIPE,       KC_BSLS,       KC_PIPE,      \
                                                 XXXXX,         XXXXX,         XXXXX,         KC_ENT,        KC_BSPC,       KC_DEL
    ),

    [LAYER_MOUSE] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         XXXXX,         KC_MS_L,       KC_MS_U,       KC_MS_D,       KC_MS_R,       XXXXX,         KC_LSFT,       KC_LGUI,       KC_LALT,       KC_LCTL,       XXXXX,        \
    XXXXX,         XXXXX,         KC_WH_R,       KC_WH_D,       KC_WH_U,       KC_WH_L,       XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,        \
                                                 KC_BTN3,       KC_BTN1,       KC_BTN2,       XXXXX,         XXXXX,         XXXXX
    ),

    [LAYER_MEDIA] = LAYOUT(
    RGB_SPD,       RGB_MOD,       RGB_HUI,       RGB_SAI,       RGB_VAI,       RGB_TOG,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         XXXXX,         KC_MPRV,       KC_VOLU,       KC_VOLD,       KC_MNXT,       XXXXX,         KC_LSFT,       KC_LGUI,       KC_LALT,       KC_LCTL,       XXXXX,        \
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         XXXXX,        \
                                                 KC_MSTP,       KC_MPLY,       KC_MUTE,       XXXXX,         XXXXX,         XXXXX         
    ),

    [LAYER_NUM] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_LBRC,       KC_7,          KC_8,          KC_9,          KC_RBRC,      XXXXX,         \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         KC_SCLN,       KC_4,          KC_5,          KC_6,          KC_EQL,       XXXXX,         \
    XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         KC_GRV,        KC_1,          KC_2,          KC_3,          KC_BSLS,      XXXXX,         \
                                                 XXXXX,         XXXXX,         XXXXX,         KC_DOT,        KC_0,          KC_MINS       
    ),

    [LAYER_SYM] = LAYOUT(
    XXXXX,         KC_LCBR,       KC_AMPR,       KC_ASTR,       KC_LPRN,       KC_RCBR,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         KC_COLN,       KC_DLR,        KC_PERC,       KC_CIRC,       KC_PLUS,       XXXXX,         KC_LSFT,       KC_LGUI,       KC_LALT,       KC_LCTL,       XXXXX,        \
    XXXXX,         KC_TILD,       KC_EXLM,       KC_AT,         KC_HASH,       KC_PIPE,       XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,        \
                                                 KC_LPRN,       KC_RPRN,       KC_UNDS,       XXXXX,         XXXXX,         XXXXX
    ),

    [LAYER_FUN] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_PSCR,       KC_F7,         KC_F8,         KC_F9,         KC_F12,        XXXXX,         \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         KC_SCRL,       KC_F4,         KC_F5,         KC_F6,         KC_F11,        TG(LAYER_GAME),\
    XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         KC_PAUS,       KC_F1,         KC_F2,         KC_F3,         KC_F10,        XXXXX,         \
                                                 XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX
    ),

    [LAYER_GAME] = LAYOUT(
    KC_LEFT_CTRL,  KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_EQL,       \
    KC_LEFT_SHIFT, KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_H,          KC_J,          KC_K,          KC_L,          KC_SCLN,       KC_QUOT,      \
    KC_LEFT_ALT,   KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_N,          KC_M,          KC_COMM,       KC_DOT,        KC_SLSH,       KC_MINS,      \
                                                 KC_ESC,        KC_BSPC,       KC_TAB,        KC_ENT,        KC_SPC,        TG(LAYER_GAME)
    ),
};
// end keymap

// start sm_td

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LEFT_CTRL)
        SMTD_MT(CKC_S, KC_S, KC_LEFT_ALT)
        SMTD_MT(CKC_D, KC_D, KC_LEFT_GUI)
        SMTD_MT(CKC_F, KC_F, KC_LSFT)
        SMTD_MT(CKC_J, KC_J, KC_LSFT)
        SMTD_MT(CKC_K, KC_K, KC_LEFT_GUI)
        SMTD_MT(CKC_L, KC_L, KC_LEFT_ALT)
        SMTD_MT(CKC_SCLN, KC_SCLN, KC_LEFT_CTRL)
    }
}

// end sm_td