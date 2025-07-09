#include QMK_KEYBOARD_H
#include "features/achordion.h"

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

#define GUI(KEY) LGUI_T(KEY)
#define ALT(KEY) LALT_T(KEY)
#define CTL(KEY) LCTL_T(KEY)
#define SFT(KEY) LSFT_T(KEY)
// end convenience definitions

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_BASE] = LAYOUT(
    KC_GRV,        KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_Y,          KC_U,          KC_I,          KC_O,          KC_P,          KC_EQL,       \
    XXXXX,         CTL(KC_A),     ALT(KC_S),     GUI(KC_D),     SFT(KC_F),     KC_G,          KC_H,          SFT(KC_J),     GUI(KC_K),     ALT(KC_L),     CTL(KC_SCLN),  KC_QUOT,      \
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
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_7,          KC_8,          KC_9,          XXXXX,        XXXXX,         \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         XXXXX,         KC_4,          KC_5,          KC_6,          XXXXX,        XXXXX,         \
    XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         XXXXX,         KC_1,          KC_2,          KC_3,          XXXXX,        XXXXX,         \
                                                 XXXXX,         XXXXX,         XXXXX,         KC_COMM,       KC_0,          KC_DOT
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

// start achordion
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_eager_mod(uint8_t mod) {
    // we're eagerly applying for all the mod keys
    return true;
}

// exclude thumb keys from the same-hand rule
bool achordion_chord(uint16_t tap_hold_keycode,
                    keyrecord_t* tap_hold_record,
                    uint16_t other_keycode,
                    keyrecord_t* other_record) {

    // MATRIX_ROWS is 8 for this keyboard, and the thumb keys are at rows 3 and 7
    bool is_thumb_key = (other_record->event.key.row % (MATRIX_ROWS / 2)) == 3;

    if (is_thumb_key) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}
// end achordion
