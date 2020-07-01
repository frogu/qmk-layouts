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
	K000, K001, K002, K003, K004, K005, K006,       K008, K009, K010, K011, K012, K013, K014, K015, \
	K100, K101, K102, K103, K104, K105,       K107, K108, K109, K110, K111, K112, K113, K114, K115, \
	K200, K201, K202, K203, K204, K205,       K207, K208, K209, K210, K211, K212,       K214, K215, \
	K300, K301, K302, K303, K304, K305,       K307, K308, K309, K310, K311,       K313, K314, K315, \
	K400, K401, K402, K403, K404,             K407,       K409, K410, K411,       K413, K414, K415  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  KC_NO, K008,  K009,  K010,  K011,  K012,  K013,  K014,  K015 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  KC_NO, K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  KC_NO, K207,  K208,  K209,  K210,  K211,  K212,  KC_NO, K214,  K215 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  KC_NO, K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  K314,  K315 }, \
	{ K400,  K401,  K402,  K403,  K404,  KC_NO, KC_NO, K407,  KC_NO, K409,  K410,  K411,  KC_NO, K413,  K414,  K415 }  \
}

#endif
