#include QMK_KEYBOARD_H
#include "debug.h"
#include "version.h"
#include "keymap_bepo.h"
#include "keymap_french.h"

// keymaps
#define BEPO 0	// default layer, for bepo compatible systems
#define FNAV 1	// function / navigation / mouse layer
#define NUMK 2	// numeric keypad layer

// macros
#define KP_00 0	// keypad "double 0"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: default layer
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |   $    |   "  |   <  |   >  |   (  |   )  |Delete|                                  |ScroLo|   @  |   +  |   -  |   /  |   *  |   =    |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |   %    |   B  |E_ACUT|   P  |   O  |E_GRAV|Backsp|                                  |CapsLo|   ^  |   V  |   D  |   L  |   J  |   Z    |
 * |--------+------+------+------+------+------|  ace |                                  |      |------+------+------+------+------+--------|
 * |   W    |   A  |   U  |   I  |   E  |   ,  |------|                                  |------|   C  |   T  |   S  |   R  |   N  |   M    |
 * |--------+------+------+------+------+------|  Tab |                                  | NumLo|------+------+------+------+------+--------|
 * | E_CIRC |A_GRAV|   Y  |   X  |   .  |   K  |      |                                  |      |   '  |   Q  |   G  |   H  |   F  | C_CEDIL|
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |Escape|Insert|LSuper| LCtrl|  LAlt|             | PLAY | Hyper|      | PREV | NEXT |             | AltGr| RCtrl|RSuper|  LAlt| Pause|
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |L_NumK|      |L_NumK|      |      |
 *                                             | Space|LShift|------|      |------|RShift|Enter |
 *                                             |      |      |L_FNav|      |L_FNav|      |      |
 *                                             `--------------------'      `--------------------'
 */
[BEPO] = LAYOUT_ergodox(
// Left hand
BP_DOLLAR,      BP_DQOT,	BP_LGIL,	BP_RGIL,	BP_LPRN,	BP_RPRN,	KC_DEL,
BP_PERCENT,	BP_B,		BP_E_ACUTE,	BP_P,		BP_O,		BP_E_GRAVE,	KC_BSPC,
BP_W,		BP_A,		BP_U,		BP_I,		BP_E,		BP_COMMA,
BP_ECRC,	BP_A_GRAVE,	BP_Y,		BP_X,		BP_DOT,		BP_K,		KC_TAB,
KC_ESC,		KC_INS,		KC_LGUI,	KC_LCTL,	KC_LALT,
						        	                	                        KC_MPLY,	KC_HYPR,
						        	                                                                TT(NUMK),
						        	        			KC_SPC,		KC_LSHIFT,	MO(FNAV),
// Right hand
				KC_SLCK,	BP_AT,		BP_PLUS,	BP_MINUS,	BP_SLASH,	BP_ASTR,	BP_EQUAL,
				KC_CAPSLOCK,	BP_DCRC,	BP_V,		BP_D,		BP_L,		BP_J,		BP_Z,
						BP_C,		BP_T,		BP_S,		BP_R,		BP_N,		BP_M,
				KC_NUMLOCK,	BP_APOS,	BP_Q,		BP_G,		BP_H,		BP_F,		BP_CCED,
						        	BP_ALGR,	KC_RCTL,	KC_RGUI,	KC_LALT,        KC_PAUSE,
KC_MPRV,  KC_MNXT,
TT(NUMK),
MO(FNAV),	KC_RSHIFT,	KC_ENTER),
/* Keymap 1: function / special characters / volume / navigation
 *
 * ,--------------------------------------------------.                                  ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |VolMut|                                  |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |VolDwn|                                  |      | PgUp | Home |  Up  |  End |  F11 |        |
 * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|                                  |------| PgDn | Left | Down | Right|  F12 |        |
 * |--------+------+------+------+------+------| VolUp|                                  |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |                                  |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |             |      |      |      |      |      |             |      |      |      |      |      |
 *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
 *                                             |      |      |      |      |      |      |      |
 *                                             |      |      |------|      |------|      |      |
 *                                             |      |      |      |      |      |      |      |
 *                                             `--------------------'      `--------------------'
 */
[FNAV] = LAYOUT_ergodox(
// Left hand
VRSN,           KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,	        KC_MUTE,
KC_NO,          BP_EXLM,        BP_AT,          BP_LCBR,        BP_RCBR,        BP_PIPE,        KC_VOLU,
KC_NO,          BP_HASH,        BP_DLR,         BP_LPRN,        BP_RPRN,        BP_GRV,
KC_NO,	        BP_PERC,        BP_CIRC,        BP_LBRC,        BP_RBRC,        BP_TILD,        KC_VOLD,
EPRM, 	        KC_NO,		KC_TRNS,	KC_TRNS,        KC_TRNS,
	        		                                                                                KC_TRNS,        KC_TRNS,
	                        		        				        		                KC_TRNS,
	        				        				        KC_TRNS,        KC_TRNS,        KC_TRNS,

// Right hand
	        		KC_NO,		KC_F6,		KC_F7,  	KC_F8,	        KC_F9,		KC_F10,		KC_NO,
	        		KC_NO,		KC_PGUP,	KC_HOME,	KC_UP,	        KC_END,		KC_F11,		KC_NO,
	        		        	KC_PGDOWN,	KC_LEFT,	KC_DOWN,        KC_RIGHT,	KC_F12,		KC_NO,
	        		KC_NO,		KC_NO,		KC_NO,  	KC_NO,	        KC_NO,		KC_NO,  	KC_NO,
	        		        	        	KC_TRNS,	KC_TRNS,        KC_TRNS,	KC_NO,  	KC_NO,
KC_TRNS,        KC_TRNS,
KC_TRNS,
KC_TRNS,	KC_TRNS,        KC_TRNS),

/* Keymap 2: mouse, numeric keypad layer, lighting, sends keypad codes
 *
  * ,--------------------------------------------------.                                  ,--------------------------------------------------.
  * |Version |      |      |      |      |      |      |                                  |      |      |   +  |   -  |   /  |   *  |        |
  * |--------+------+------+------+------+-------------|                                  |------+------+------+------+------+------+--------|
  * |        | Next |LClick|  Up  |RClick| WhUp |      |                                  |      |      |   7  |   8  |   9  |   +  |        |
  * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
  * |        | Prev | Left | Down | Right|WhDown|------|                                  |------|      |   4  |   5  |   6  |   +  |        |
  * |--------+------+------+------+------+------|      |                                  |      |------+------+------+------+------+--------|
  * |        | Undo |  Cut | Copy | Paste|      |      |                                  |      |      |   1  |   2  |   3  | Enter|        |
  * `--------+------+------+------+------+-------------,-------------.      ,-------------`-------------+------+------+------+------+--------'
  *   | EPRM |      |      |      |      |             |Animat|      |      |Toggle|Solid |             |   0  |   .  |  00  | Enter|      |
  *   `----------------------------------'      ,------|------|------|      |------+------+------.      `----------------------------------'
  *                                             |Bright|Bright|      |      |      |Hue-  |Hue+  |
  *                                             |ness- |ness+ |------|      |------|      |      |
  *                                             |      |      |      |      |      |      |      |
  *                                             `--------------------'      `--------------------'
 */
[NUMK] = LAYOUT_ergodox(

// Left hand
VRSN,           KC_NO,          KC_NO,	        KC_NO,          KC_NO,          KC_NO,	        KC_TRNS,
KC_NO,	        KC_MS_BTN5,     KC_MS_BTN1,     KC_MS_UP,	KC_MS_BTN2,	KC_MS_WH_UP,    KC_TRNS,
KC_NO,	        KC_MS_BTN4,	KC_MS_LEFT,     KC_MS_DOWN,	KC_MS_RIGHT,	KC_MS_WH_DOWN,
KC_NO,	        KC_UNDO,	KC_CUT,	        KC_COPY,	KC_PASTE,	KC_NO,	        KC_TRNS,
EPRM, 	        KC_NO,		KC_TRNS,        KC_TRNS,	KC_TRNS,
                                                                                                                RGB_MOD,        KC_TRNS,
                                                        	        		        			        KC_TRNS,
                		                        	        		        RGB_VAD,        RGB_VAI,        KC_TRNS,


// Right hand
                		KC_NO,		KC_NO,		KC_TRNS,        KC_TRNS,        KC_TRNS,       	KC_TRNS,    	KC_NO,
                		KC_NO,		KC_NO,		KC_KP_7,	KC_KP_8,	KC_KP_9,	KC_KP_PLUS,	KC_NO,
                				KC_NO,		KC_KP_4,	KC_KP_5,	KC_KP_6,	KC_KP_PLUS,	KC_NO,
                		KC_NO,	        KC_NO,          KC_KP_1,	KC_KP_2,	KC_KP_3,	KC_KP_ENTER,	KC_NO,
                				                KC_KP_0,        KC_KP_DOT,      M(KP_00),       KC_KP_ENTER,	KC_NO,
RGB_TOG,        RGB_SLD,
KC_TRNS,
KC_TRNS,        RGB_HUD,        RGB_HUI)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    // keypad "double 0"
    case KP_00:
      if (record->event.pressed) {
        return MACRO( T(KP_0), D(KP_0), END );
      } else {
        return MACRO( U(KP_0), END );
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  case KC_CAPSLOCK:
    break;
  }
  return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
