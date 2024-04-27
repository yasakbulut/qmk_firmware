#include QMK_KEYBOARD_H
#include <stdio.h>

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

// layers
enum {
    LAYER_BASE=0,
    LAYER_NAV=2,
    LAYER_MOUSE=4,
    LAYER_MEDIA=8,
    LAYER_NUM=16,
    LAYER_SYM=32,
    LAYER_FUN=64,
};

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case LAYER_BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case LAYER_NAV:
            oled_write_ln_P(PSTR("Nav"), false);
            break;
        case LAYER_MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        case LAYER_MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case LAYER_NUM:
            oled_write_ln_P(PSTR("Num"), false);
            break;
        case LAYER_SYM:
            oled_write_ln_P(PSTR("Sym"), false);
            break;
        case LAYER_FUN:
            oled_write_ln_P(PSTR("Fun"), false);
            break;
    }
}

void oled_render_logo(void) {
    static const char PROGMEM cacaw_logo[] = {
        0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x80,
        0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xa0,
        0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xc0,
        0};
    oled_write_P(cacaw_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE
