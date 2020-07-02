#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    _QWERTY, // default layer
    _SYMB, // symbols
    _NAV,  // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

// Shortcut to make keymap more readable
#define SYM_L   MO(_SYMB)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_SYEN LT(_SYMB, KC_END)
#define KC_SYPU LT(_SYMB, KC_PGUP)

#define KC_NAPD LT(_NAV, KC_PGDN)
#define KC_NAHO LT(_NAV, KC_HOME)

#define KC_RCMN RCTL_T(KC_MINS)
#define KC_RASP RALT_T(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ergodox_pretty(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
   KC_NAGR ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,SYM_L   ,          SYM_L   ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_NAMI ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_SYPU ,          KC_NAHO ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        |         |        ├────────┼────────┼────────┼────────┼────────┼────────┤
   KC_ESC  ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                            KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   KC_LSPO ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_NAPD ,          KC_SYEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSPC ,
//├────────┼────────┼────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┼────────┼────────┤
   KC_DEL  ,KC_LGUI ,KC_INS  ,KC_ALAS , KC_CTPL,                                              KC_RASP ,KC_RCMN ,KC_LBRC ,KC_RBRC ,KC_APP  ,
//└────────┴────────┴────────┴────────┴────────┘                                             └────────┴────────┴────────┴────────┴────────┘
//                                               ┌────────┬────────┐     ┌────────┬────────┐ 
                                                  KC_SYPU ,KC_NAPD ,      KC_NAHO ,KC_SYEN ,
//                                      ┌────────┼────────┼────────┤     ├────────┼────────┼────────┐
                                                           XXXXXXX ,      XXXXXXX ,
//                                      |        |        ├────────┤     ├────────┤        |        |
                                         KC_SPC  ,KC_BSPC ,XXXXXXX ,      XXXXXXX ,KC_ENT  , KC_SPC
//                                      └────────┴────────┴────────┘     └────────┴────────┴────────┘                                           
),

[_SYMB] = LAYOUT_ergodox_pretty(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,_______ ,          _______ ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,_______ ,          _______ ,KC_PSLS ,KC_7    ,KC_8    ,KC_9    ,KC_PMNS ,KC_F12  ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        |         |        ├────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,                            KC_PAST ,KC_4    ,KC_5    ,KC_6    ,KC_PPLS ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,KC_PERC ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,          _______ ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,KC_PENT ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,_______ ,_______ ,_______ ,_______ ,                                              KC_0    ,KC_0    ,KC_PDOT ,KC_PENT ,XXXXXXX ,
//└────────┴────────┴────────┴────────┴────────┘                                             └────────┴────────┴────────┴────────┴────────┘
//                                               ┌────────┬────────┐     ┌────────┬────────┐ 
                                                  _______ ,_______ ,      _______ ,_______ ,
//                                      ┌────────┼────────┼────────┤     ├────────┼────────┼────────┐
                                                           _______ ,      _______ ,                                                      
//                                      |        |        ├────────┤     ├────────┤        |        |
                                         _______ ,_______ ,_______ ,      _______ ,_______ ,_______  
//                                      └────────┴────────┴────────┘     └────────┴────────┴────────┘                                           

),


[_NAV] = LAYOUT_ergodox_pretty(
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐         ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
   _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MS_U ,XXXXXXX ,KC_WH_U ,_______ ,          _______ ,KC_PSCR ,KC_PGUP ,KC_UP   ,KC_PGDN ,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┤        |         |        ├────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX ,XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,                            XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
   _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,
//├────────┼────────┼────────┼────────┼────────┼────────┴────────┘         └────────┴────────┼────────┼────────┼────────┼────────┼────────┤
   XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BTN3 ,                                              XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//└────────┴────────┴────────┴────────┴────────┘                                             └────────┴────────┴────────┴────────┴────────┘
//                                               ┌────────┬────────┐     ┌────────┬────────┐ 
                                                  _______ ,_______ ,      _______ ,_______ ,
//                                      ┌────────┼────────┼────────┤     ├────────┼────────┼────────┐
                                                           _______ ,      _______ ,                                                      
//                                      |        |        ├────────┤     ├────────┤        |        |
                                         KC_BTN1 ,KC_BTN2 ,_______ ,      _______ ,_______ ,_______  
//                                      └────────┴────────┴────────┘     └────────┴────────┴────────┘                                           


),
};



// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
