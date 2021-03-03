#include "kb.h"

#define MAIN_LAYOUT 0

#define Z_TM KC_1
#define Z_NM KC_2
#define Z_STILL KC_3
#define Z_L KC_4
#define Z_Z KC_5
#define Z_VEC KC_6
#define Z_LEFT_C KC_7
#define Z_RGHT_C KC_8

#define Z_SPD KC_Q
#define Z_FF KC_W
#define Z_ALL KC_E
#define Z_O KC_R
#define Z_I KC_T
#define Z_RM KC_Y
#define Z_SGL KC_U
#define Z_RC KC_I

#define Z_LK KC_A
#define Z_ULK KC_S
#define Z_TRS KC_D
#define Z_LEFT KC_F
#define Z_ENCO KC_G
#define Z_RGHT KC_H


#define Z_IN KC_Z
#define Z_OUT KC_X
#define Z_NORM KC_V
#define Z_DEL KC_DEL

#define Z_CTRL KC_P
#define Z_ALT KC_O
#define Z_END KC_I
#define Z_UP KC_K
#define Z_SPC KC_SPC
#define Z_CUT KC_J

#define Z_F_BCK KC_9
#define Z_F_FWD KC_0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[MAIN_LAYOUT] = KEYMAP(
  //┌────────┬────────┬────────┐  ┌────────┬────────┬────────┬────────┬────────┐
     Z_TM    ,Z_NM    ,Z_STILL ,   Z_L     ,Z_Z     ,Z_VEC   ,Z_LEFT_C,Z_RGHT_C,
  //├────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     Z_SPD   ,Z_FF    ,Z_ALL   ,   Z_O     ,Z_I     ,Z_RM    ,Z_SGL   ,Z_RC    ,
  //├────────┼────────┼────────┤  ├────────┼────────┼────────┼────────┼────────┤
     Z_LK    ,Z_ULK   ,Z_TRS   ,   Z_LEFT  ,         Z_ENCO  ,         Z_RGHT  ,
  //├────────┼────────┼────────┤  └────────┘        └────────┘        ├────────┤
     Z_IN    ,Z_OUT   ,Z_NORM  ,                                       Z_DEL   ,
  //├────────┼────────┼────────┤  ┌────────┐    ┌─────────────────┐   ├────────┤
     Z_CTRL  ,Z_ALT   ,Z_END   ,   Z_UP    ,         Z_SPC        ,    Z_CUT
  //└────────┴────────┴────────┘  └────────┘    └─────────────────┘   └────────┘ 
  )

};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    //oled_write_P(PSTR("Layer: "), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif


void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(Z_F_BCK);
            oled_write_ln_P(PSTR(">>> >>>"),false);
        } else {
            tap_code(Z_F_FWD);
            oled_write_ln_P(PSTR("<<< <<<"),false);
        }
    } 
}
