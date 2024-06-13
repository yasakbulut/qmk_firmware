#include QMK_KEYBOARD_H
#include <stdio.h>

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}


void oled_render_logo(void) {
    static const char PROGMEM cacaw_logo[] = {
        0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x80,
        0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xa0,
        0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xc0,
        0};
    oled_write_P(cacaw_logo, false);
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
    LAYER_GAME=128,
};

static oled_rotation_t current_rotation = OLED_ROTATION_0;

void rotate_if_needed(oled_rotation_t rotation) {
    if (current_rotation != rotation) {
        current_rotation = rotation;
        oled_init(rotation);
    }
}

void render_layer_name(const char *data, bool invert) {
    rotate_if_needed(OLED_ROTATION_0);
    oled_write_ln_P(data, invert);
}

void oled_render_layer_state(void) {
    oled_clear();
    switch (layer_state) {
        case LAYER_BASE:
            render_layer_name(PSTR("Layer: Base"), false);
            break;
        case LAYER_NAV:
            render_layer_name(PSTR("Layer: Nav"), false);
            break;
        case LAYER_MOUSE:
            render_layer_name(PSTR("Layer: Mouse"), false);
            break;
        case LAYER_MEDIA:
            render_layer_name(PSTR("Layer: Media"), false);
            break;
        case LAYER_NUM:
            render_layer_name(PSTR("Layer: Num"), false);
            break;
        case LAYER_SYM:
            render_layer_name(PSTR("Layer: Sym"), false);
            break;
        case LAYER_FUN:
            render_layer_name(PSTR("Layer: Fun"), false);
            break;
        case LAYER_GAME:
            rotate_if_needed(OLED_ROTATION_180);
            oled_render_logo();
            break;
    }
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
