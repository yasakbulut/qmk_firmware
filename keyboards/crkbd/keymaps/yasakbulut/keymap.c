#include QMK_KEYBOARD_H

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
};

// convenience definitions
#define XXXXX KC_NO

#define NAV(KEY) LT(LAYER_NAV, KEY)
#define MOUSE(KEY) LT(LAYER_MOUSE, KEY)
#define MEDIA(KEY) LT(LAYER_MEDIA, KEY)
#define NUM(KEY) LT(LAYER_NUM, KEY)
#define SYM(KEY) LT(LAYER_SYM, KEY)
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
                                                 MEDIA(KC_ESC), NAV(KC_BSPC),  MOUSE(KC_TAB), SYM(KC_ENT),   NUM(KC_SPC),   FUN(KC_DEL)
    ),

    [LAYER_NAV] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_LPRN,       KC_LCBR,       KC_RCBR,       KC_LBRC,       KC_RBRC,       KC_RPRN,      \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         KC_LEFT,       KC_DOWN,       KC_UP,         KC_RGHT,       CW_TOGG,       XXXXX,        \
    XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         KC_BSLS,       KC_PIPE,      \
                                                 XXXXX,         XXXXX,         XXXXX,         KC_ENT,        KC_BSPC,       KC_DEL
    ),

    [LAYER_MOUSE] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         KC_MS_L,       KC_MS_D,       KC_MS_U,       KC_MS_R,       XXXXX,         XXXXX,        \
    XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         XXXXX,         KC_WH_R,       KC_WH_U,       KC_WH_D,       KC_WH_L,       XXXXX,         XXXXX,        \
                                                 XXXXX,         XXXXX,         XXXXX,         KC_BTN2,       KC_BTN1,       KC_BTN3
    ),

    [LAYER_MEDIA] = LAYOUT(
    XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         RGB_MOD,       RGB_HUI,       RGB_SAI,       RGB_VAI,       RGB_TOG,       XXXXX,        \
    XXXXX,         KC_LCTL,       KC_LALT,       KC_LGUI,       KC_LSFT,       XXXXX,         KC_MPRV,       KC_VOLD,       KC_VOLU,       KC_MNXT,       XXXXX,         XXXXX,        \
    XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
                                                 XXXXX,         XXXXX,         XXXXX,         KC_MSTP,       KC_MPLY,       KC_MUTE
    ),

    [LAYER_NUM] = LAYOUT(
    XXXXX,         KC_LBRC,       KC_7,          KC_8,          KC_9,          KC_RBRC,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         KC_SCLN,       KC_4,          KC_5,          KC_6,          KC_EQL,        XXXXX,         KC_LSFT,       KC_LGUI,       KC_LALT,       KC_LCTL,       XXXXX,        \
    XXXXX,         KC_GRV,        KC_1,          KC_2,          KC_3,          KC_BSLS,       XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,        \
                                                 KC_DOT,        KC_0,          KC_MINS,       XXXXX,         XXXXX,         XXXXX
   ),
    [LAYER_SYM] = LAYOUT(
    XXXXX,         KC_LCBR,       KC_AMPR,       KC_ASTR,       KC_LPRN,       KC_RCBR,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         KC_COLN,       KC_DLR,        KC_PERC,       KC_CIRC,       KC_PLUS,       XXXXX,         KC_LSFT,       KC_LGUI,       KC_LALT,       KC_LCTL,       XXXXX,        \
    XXXXX,         KC_TILD,       KC_EXLM,       KC_AT,         KC_HASH,       KC_PIPE,       XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,        \
                                                 KC_LPRN,       KC_RPRN,       KC_UNDS,       XXXXX,         XXXXX,         XXXXX
   ),
    [LAYER_FUN] = LAYOUT(
    XXXXX,         KC_F12,        KC_F7,         KC_F8,         KC_F9,         KC_PSCR,       XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,         XXXXX,        \
    XXXXX,         KC_F11,        KC_F4,         KC_F5,         KC_F6,         KC_SCRL,       XXXXX,         KC_LSFT,       KC_LGUI,       KC_LALT,       KC_LCTL,       XXXXX,        \
    XXXXX,         KC_F10,        KC_F1,         KC_F2,         KC_F3,         KC_PAUS,       XXXXX,         XXXXX,         XXXXX,         KC_ALGR,       XXXXX,         XXXXX,        \
                                                 KC_APP,        KC_SPC,        KC_TAB,        XXXXX,         XXXXX,         XXXXX
   ),
};
