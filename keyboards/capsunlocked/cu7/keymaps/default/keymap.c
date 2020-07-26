/* Copyright 2020 aHolland
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define MEDIA_KEY_DELAY 10


// Defines the keycodes used by our macros in process_record_user


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
             KC_MUTE,	
    MO(1),   _______, _______, 
	  KC_MPLY, KC_MPRV,  KC_MNXT
  ),
  [1] = LAYOUT(
             _______,	
    _______, KC_UP,   RESET, 
	  KC_LEFT, KC_DOWN, KC_RGHT
  ),
};

void encoder_update(bool clockwise) { 
  uint16_t held_keycode_timer = timer_read(); 
  if (clockwise) { 
    register_code(KC_VOLU); 
    while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) { 
      // no-op 
      } 
      unregister_code(KC_VOLU); 
    } 
  else { 
    register_code(KC_VOLD); 
    while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY) { 
      // no-op 
    } 
    unregister_code(KC_VOLD); 
  } 
}



void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
