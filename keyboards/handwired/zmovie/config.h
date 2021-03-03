#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    devops.best
#define PRODUCT         z-movie
#define DESCRIPTION     Movie editing keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 8

/* key matrix pins */
#define MATRIX_COL_PINS { B3, B2, B6, C6, D7, E6, B4, B5}
#define MATRIX_ROW_PINS { B1, F7, D3, F6, D4 }
#define UNUSED_PINS

#define ENCODERS_PAD_A { F5 }
#define ENCODERS_PAD_B { F4 }
#define ENCODER_RESOLUTION 4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW


/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS


#endif

//#define SPLIT_HAND_PIN B7
//#define USE_I2C
//#define SPLIT_USB_DETECT

