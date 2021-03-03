#ifndef KB_H
#define KB_H

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif


#define KEYMAP( \
        K00, K01, K02, K03, K04, K05, K06, K07, \
        K10, K11, K12, K13, K14, K15, K16, K17, \
        K20, K21, K22, K23,      K25,      K27, \
        K30, K31, K32,                     K37, \
        K40, K41, K42, K43,      K45,      K47  \
) { \
        { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07 }, \
        { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17 }, \
        { K20,   K21,   K22,   K23,   KC_NO, K25,   KC_NO, K27 }, \
        { K30,   K31,   K32,   KC_NO, KC_NO, KC_NO, KC_NO, K37 }, \
        { K40,   K41,   K42,   K43,   KC_NO, K45,   KC_NO, K47 }  \
}             
#endif
