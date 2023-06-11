#include QMK_KEYBOARD_H

#define LED_INTENSITY 25

void keyboard_pre_init_user(void) {
  // Disable power led of MCU
  setPinOutput(24);
  writePinHigh(24);
  // Initialize RGB to static black
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_BLACK);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  uint8_t layer = get_highest_layer(state);
  switch (layer) {
  case 0:
    // Default layer
    rgblight_setrgb_at(0, 0, 0, 0);
    break;
  case 1:
    // Symbols
    rgblight_setrgb_at(0, 0, LED_INTENSITY, 0);
    break;
  case 2:
    // French macros
    rgblight_setrgb_at(0, LED_INTENSITY, 0, 0);
    break;
  case 3:
    // Nav
    rgblight_setrgb_at(LED_INTENSITY, 0, 0, 0);
    break;
  case 4:
    // Numpad
    rgblight_setrgb_at(LED_INTENSITY, 0, LED_INTENSITY, 0);
    break;
  default:
    break;
  }

  return state;
}

