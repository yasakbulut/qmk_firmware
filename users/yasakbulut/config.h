#define OLED_FONT_H "users/yasakbulut/glcdfont.c"

// 42 keys per-key leds, and 12 underglow leds = 54 leds
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 54
#define RGBLIGHT_SPLIT 27

// If defined, the RGB lighting will be switched off when the host goes to sleep
#define RGBLIGHT_SLEEP

#define RGBLIGHT_EFFECT_RAINBOW_SWIRL

#define RGBLIGHT_DEFAULT_ON true
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 128
#define RGBLIGHT_DEFAULT_VAL 64

