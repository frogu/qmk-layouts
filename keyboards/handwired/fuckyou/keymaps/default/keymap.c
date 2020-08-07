#include "kb.h"

#define _MAIN 0 
#define _STRING 1
#define _FCK 2

#define KC_SPC_STR LT(_STRING, KC_SPC)
#define KC_ENT_FCK LT(_FCK, KC_ENT)

enum custom_keycodes {
	SOA1 = SAFE_RANGE, 
	SOA2 , 
	SOA4 , 
	SOA8 , 
	SOA16 , 
	SOA0 , 
	SOAR,
        FUU,
	FOF,
	FG0,
	MBANK,
	PRO,
	SKA,
	OPEL,
	OKON
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
	switch (keycode) {
		case MBANK:
			if (record->event.pressed) { SEND_STRING(SS_RALT("e")SS_RALT("s")SS_RALT("a")SS_RALT("c")SS_RALT("z")); } else {
				SEND_STRING(" "SS_RALT("Z")"yczymy mi"SS_RALT("l")"ego dnia!");}   
			break;
		case PRO:
			if (record->event.pressed) { SEND_STRING("To fekaloplastyka artysty Proszka. Nie dotyka"SS_RALT("c")"!"); }   
			break;
		case SKA:
			if (record->event.pressed) { SEND_STRING("To jeszcze Skarbek zjeba"SS_RALT("l")"!"); }   
			break;
		case OPEL:
			if (record->event.pressed) { SEND_STRING("Kupi"SS_RALT("e")" Opla!"); }   
			break;
		case OKON:
			if (record->event.pressed) { SEND_STRING("Zgaduj"SS_RALT("e")" has"SS_RALT("l")"o: "); } else { SEND_STRING("oko"SS_RALT("n"));}   
			break;
		case FUU:
			if (record->event.pressed) { SEND_STRING("Fuck you!"); }   
			break;
		case FOF:
			if (record->event.pressed) { SEND_STRING("Fuck off!"); }   
			break;
		case FG0:
			if (record->event.pressed) { SEND_STRING("Number of fucks given? "); } else {SEND_STRING("ZERO!");}   
			break;
		case SOA1:
			if (record->event.pressed) { SEND_STRING("SOA1: U mnie dzia"SS_RALT("l")"a."); }   
			break;
		case SOA2:
			if (record->event.pressed) { SEND_STRING("SOA2: U mnie TE"SS_RALT("Z")" nie dzia"SS_RALT("l")"a.");}   
			break;
		case SOA4:
			if (record->event.pressed) { SEND_STRING("SOA4: Sie"SS_RALT("e")" naprawi!");} 
		       	break;
		case SOA8:
			if (record->event.pressed) { SEND_STRING("SOA8: RTFM!");	} 
		       	break;
		case SOA16:
			if (record->event.pressed) { SEND_STRING("SOA16: Google twoim przyjacielem.");}
		      	break;
		case SOA0:
			if (record->event.pressed) { SEND_STRING("SOA0: W logi patrzy"SS_RALT("l")"es?"); }
		      	break;
		case SOAR:
			if (record->event.pressed) { SEND_STRING("SOAR: Pr"SS_RALT("o")"bowa"SS_RALT("l")"e"SS_RALT("s")" wy"SS_RALT("l")SS_RALT("a")"czy"SS_RALT("c")" i w"SS_RALT("l")SS_RALT("a")"czy"SS_RALT("c")" ponownie?"); } 
		       	break;
	} return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_MAIN] = KEYMAP(
		KC_F, KC_U, KC_C, 
		KC_Y, KC_O, KC_U, 
		KC_SPC_STR, KC_ENT_FCK, KC_K),
 [_STRING] = KEYMAP(
		SOA1, SOA2, SOA4, 
		SOA8, SOA16, SOA0, 
		_______, MBANK, SOAR),
 [_FCK] = KEYMAP(
		FUU, FOF, FG0, 
		PRO, SKA, OPEL, 
		MBANK, _______, OKON),
};

