/*
	Port of
	Simple DirectMedia Layer rho_scancode.h
	From Sam Lantinga <slouken@libsdl.org>
*/

#pragma once
#include <rho.h>

typedef enum
{
    rho_SCANCODE_UNKNOWN = 0,

    rho_SCANCODE_A = 4,
    rho_SCANCODE_B = 5,
    rho_SCANCODE_C = 6,
    rho_SCANCODE_D = 7,
    rho_SCANCODE_E = 8,
    rho_SCANCODE_F = 9,
    rho_SCANCODE_G = 10,
    rho_SCANCODE_H = 11,
    rho_SCANCODE_I = 12,
    rho_SCANCODE_J = 13,
    rho_SCANCODE_K = 14,
    rho_SCANCODE_L = 15,
    rho_SCANCODE_M = 16,
    rho_SCANCODE_N = 17,
    rho_SCANCODE_O = 18,
    rho_SCANCODE_P = 19,
    rho_SCANCODE_Q = 20,
    rho_SCANCODE_R = 21,
    rho_SCANCODE_S = 22,
    rho_SCANCODE_T = 23,
    rho_SCANCODE_U = 24,
    rho_SCANCODE_V = 25,
    rho_SCANCODE_W = 26,
    rho_SCANCODE_X = 27,
    rho_SCANCODE_Y = 28,
    rho_SCANCODE_Z = 29,

    rho_SCANCODE_1 = 30,
    rho_SCANCODE_2 = 31,
    rho_SCANCODE_3 = 32,
    rho_SCANCODE_4 = 33,
    rho_SCANCODE_5 = 34,
    rho_SCANCODE_6 = 35,
    rho_SCANCODE_7 = 36,
    rho_SCANCODE_8 = 37,
    rho_SCANCODE_9 = 38,
    rho_SCANCODE_0 = 39,

    rho_SCANCODE_RETURN = 40,
    rho_SCANCODE_ESCAPE = 41,
    rho_SCANCODE_BACKSPACE = 42,
    rho_SCANCODE_TAB = 43,
    rho_SCANCODE_SPACE = 44,

    rho_SCANCODE_MINUS = 45,
    rho_SCANCODE_EQUALS = 46,
    rho_SCANCODE_LEFTBRACKET = 47,
    rho_SCANCODE_RIGHTBRACKET = 48,
    rho_SCANCODE_BACKSLASH = 49, /**< Located at the lower left of the return
                                  *   key on ISO keyboards and at the right end
                                  *   of the QWERTY row on ANSI keyboards.
                                  *   Produces REVERSE SOLIDUS (backslash) and
                                  *   VERTICAL LINE in a US layout, REVERSE
                                  *   SOLIDUS and VERTICAL LINE in a UK Mac
                                  *   layout, NUMBER SIGN and TILDE in a UK
                                  *   Windows layout, DOLLAR SIGN and POUND SIGN
                                  *   in a Swiss German layout, NUMBER SIGN and
                                  *   APOSTROPHE in a German layout, GRAVE
                                  *   ACCENT and POUND SIGN in a French Mac
                                  *   layout, and ASTERISK and MICRO SIGN in a
                                  *   French Windows layout.
                                  */
    rho_SCANCODE_NONUSHASH = 50, /**< ISO USB keyboards actually use this code
                                  *   instead of 49 for the same key, but all
                                  *   OSes I've seen treat the two codes
                                  *   identically. So, as an implementor, unless
                                  *   your keyboard generates both of those
                                  *   codes and your OS treats them differently,
                                  *   you should generate rho_SCANCODE_BACKSLASH
                                  *   instead of this code. As a user, you
                                  *   should not rely on this code because SDL
                                  *   will never generate it with most (all?)
                                  *   keyboards.
                                  */
    rho_SCANCODE_SEMICOLON = 51,
    rho_SCANCODE_APOSTROPHE = 52,
    rho_SCANCODE_GRAVE = 53, /**< Located in the top left corner (on both ANSI
                              *   and ISO keyboards). Produces GRAVE ACCENT and
                              *   TILDE in a US Windows layout and in US and UK
                              *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                              *   and NOT SIGN in a UK Windows layout, SECTION
                              *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                              *   layouts on ISO keyboards, SECTION SIGN and
                              *   DEGREE SIGN in a Swiss German layout (Mac:
                              *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                              *   DEGREE SIGN in a German layout (Mac: only on
                              *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                              *   French Windows layout, COMMERCIAL AT and
                              *   NUMBER SIGN in a French Mac layout on ISO
                              *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                              *   SIGN in a Swiss German, German, or French Mac
                              *   layout on ANSI keyboards.
                              */
    rho_SCANCODE_COMMA = 54,
    rho_SCANCODE_PERIOD = 55,
    rho_SCANCODE_SLASH = 56,

    rho_SCANCODE_CAPSLOCK = 57,

    rho_SCANCODE_F1 = 58,
    rho_SCANCODE_F2 = 59,
    rho_SCANCODE_F3 = 60,
    rho_SCANCODE_F4 = 61,
    rho_SCANCODE_F5 = 62,
    rho_SCANCODE_F6 = 63,
    rho_SCANCODE_F7 = 64,
    rho_SCANCODE_F8 = 65,
    rho_SCANCODE_F9 = 66,
    rho_SCANCODE_F10 = 67,
    rho_SCANCODE_F11 = 68,
    rho_SCANCODE_F12 = 69,

    rho_SCANCODE_PRINTSCREEN = 70,
    rho_SCANCODE_SCROLLLOCK = 71,
    rho_SCANCODE_PAUSE = 72,
    rho_SCANCODE_INSERT = 73, /**< insert on PC, help on some Mac keyboards (but
                                   does send code 73, not 117) */
    rho_SCANCODE_HOME = 74,
    rho_SCANCODE_PAGEUP = 75,
    rho_SCANCODE_DELETE = 76,
    rho_SCANCODE_END = 77,
    rho_SCANCODE_PAGEDOWN = 78,
    rho_SCANCODE_RIGHT = 79,
    rho_SCANCODE_LEFT = 80,
    rho_SCANCODE_DOWN = 81,
    rho_SCANCODE_UP = 82,

    rho_SCANCODE_NUMLOCKCLEAR = 83, /**< num lock on PC, clear on Mac keyboards
                                     */
    rho_SCANCODE_KP_DIVIDE = 84,
    rho_SCANCODE_KP_MULTIPLY = 85,
    rho_SCANCODE_KP_MINUS = 86,
    rho_SCANCODE_KP_PLUS = 87,
    rho_SCANCODE_KP_ENTER = 88,
    rho_SCANCODE_KP_1 = 89,
    rho_SCANCODE_KP_2 = 90,
    rho_SCANCODE_KP_3 = 91,
    rho_SCANCODE_KP_4 = 92,
    rho_SCANCODE_KP_5 = 93,
    rho_SCANCODE_KP_6 = 94,
    rho_SCANCODE_KP_7 = 95,
    rho_SCANCODE_KP_8 = 96,
    rho_SCANCODE_KP_9 = 97,
    rho_SCANCODE_KP_0 = 98,
    rho_SCANCODE_KP_PERIOD = 99,

    rho_SCANCODE_NONUSBACKSLASH = 100, /**< This is the additional key that ISO
                                        *   keyboards have over ANSI ones,
                                        *   located between left shift and Y.
                                        *   Produces GRAVE ACCENT and TILDE in a
                                        *   US or UK Mac layout, REVERSE SOLIDUS
                                        *   (backslash) and VERTICAL LINE in a
                                        *   US or UK Windows layout, and
                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
                                        *   in a Swiss German, German, or French
                                        *   layout. */
    rho_SCANCODE_APPLICATION = 101, /**< windows contextual menu, compose */
    rho_SCANCODE_POWER = 102, /**< The USB document says this is a status flag,
                               *   not a physical key - but some Mac keyboards
                               *   do have a power key. */
    rho_SCANCODE_KP_EQUALS = 103,
    rho_SCANCODE_F13 = 104,
    rho_SCANCODE_F14 = 105,
    rho_SCANCODE_F15 = 106,
    rho_SCANCODE_F16 = 107,
    rho_SCANCODE_F17 = 108,
    rho_SCANCODE_F18 = 109,
    rho_SCANCODE_F19 = 110,
    rho_SCANCODE_F20 = 111,
    rho_SCANCODE_F21 = 112,
    rho_SCANCODE_F22 = 113,
    rho_SCANCODE_F23 = 114,
    rho_SCANCODE_F24 = 115,
    rho_SCANCODE_EXECUTE = 116,
    rho_SCANCODE_HELP = 117,
    rho_SCANCODE_MENU = 118,
    rho_SCANCODE_SELECT = 119,
    rho_SCANCODE_STOP = 120,
    rho_SCANCODE_AGAIN = 121,   /**< redo */
    rho_SCANCODE_UNDO = 122,
    rho_SCANCODE_CUT = 123,
    rho_SCANCODE_COPY = 124,
    rho_SCANCODE_PASTE = 125,
    rho_SCANCODE_FIND = 126,
    rho_SCANCODE_MUTE = 127,
    rho_SCANCODE_VOLUMEUP = 128,
    rho_SCANCODE_VOLUMEDOWN = 129,
/* not sure whether there's a reason to enable these */
/*     rho_SCANCODE_LOCKINGCAPSLOCK = 130,  */
/*     rho_SCANCODE_LOCKINGNUMLOCK = 131, */
/*     rho_SCANCODE_LOCKINGSCROLLLOCK = 132, */
    rho_SCANCODE_KP_COMMA = 133,
    rho_SCANCODE_KP_EQUALSAS400 = 134,

    rho_SCANCODE_INTERNATIONAL1 = 135, /**< used on Asian keyboards, see
                                            footnotes in USB doc */
    rho_SCANCODE_INTERNATIONAL2 = 136,
    rho_SCANCODE_INTERNATIONAL3 = 137, /**< Yen */
    rho_SCANCODE_INTERNATIONAL4 = 138,
    rho_SCANCODE_INTERNATIONAL5 = 139,
    rho_SCANCODE_INTERNATIONAL6 = 140,
    rho_SCANCODE_INTERNATIONAL7 = 141,
    rho_SCANCODE_INTERNATIONAL8 = 142,
    rho_SCANCODE_INTERNATIONAL9 = 143,
    rho_SCANCODE_LANG1 = 144, /**< Hangul/English toggle */
    rho_SCANCODE_LANG2 = 145, /**< Hanja conversion */
    rho_SCANCODE_LANG3 = 146, /**< Katakana */
    rho_SCANCODE_LANG4 = 147, /**< Hiragana */
    rho_SCANCODE_LANG5 = 148, /**< Zenkaku/Hankaku */
    rho_SCANCODE_LANG6 = 149, /**< reserved */
    rho_SCANCODE_LANG7 = 150, /**< reserved */
    rho_SCANCODE_LANG8 = 151, /**< reserved */
    rho_SCANCODE_LANG9 = 152, /**< reserved */

    rho_SCANCODE_ALTERASE = 153, /**< Erase-Eaze */
    rho_SCANCODE_SYSREQ = 154,
    rho_SCANCODE_CANCEL = 155,
    rho_SCANCODE_CLEAR = 156,
    rho_SCANCODE_PRIOR = 157,
    rho_SCANCODE_RETURN2 = 158,
    rho_SCANCODE_SEPARATOR = 159,
    rho_SCANCODE_OUT = 160,
    rho_SCANCODE_OPER = 161,
    rho_SCANCODE_CLEARAGAIN = 162,
    rho_SCANCODE_CRSEL = 163,
    rho_SCANCODE_EXSEL = 164,

    rho_SCANCODE_KP_00 = 176,
    rho_SCANCODE_KP_000 = 177,
    rho_SCANCODE_THOUSANDSSEPARATOR = 178,
    rho_SCANCODE_DECIMALSEPARATOR = 179,
    rho_SCANCODE_CURRENCYUNIT = 180,
    rho_SCANCODE_CURRENCYSUBUNIT = 181,
    rho_SCANCODE_KP_LEFTPAREN = 182,
    rho_SCANCODE_KP_RIGHTPAREN = 183,
    rho_SCANCODE_KP_LEFTBRACE = 184,
    rho_SCANCODE_KP_RIGHTBRACE = 185,
    rho_SCANCODE_KP_TAB = 186,
    rho_SCANCODE_KP_BACKSPACE = 187,
    rho_SCANCODE_KP_A = 188,
    rho_SCANCODE_KP_B = 189,
    rho_SCANCODE_KP_C = 190,
    rho_SCANCODE_KP_D = 191,
    rho_SCANCODE_KP_E = 192,
    rho_SCANCODE_KP_F = 193,
    rho_SCANCODE_KP_XOR = 194,
    rho_SCANCODE_KP_POWER = 195,
    rho_SCANCODE_KP_PERCENT = 196,
    rho_SCANCODE_KP_LESS = 197,
    rho_SCANCODE_KP_GREATER = 198,
    rho_SCANCODE_KP_AMPERSAND = 199,
    rho_SCANCODE_KP_DBLAMPERSAND = 200,
    rho_SCANCODE_KP_VERTICALBAR = 201,
    rho_SCANCODE_KP_DBLVERTICALBAR = 202,
    rho_SCANCODE_KP_COLON = 203,
    rho_SCANCODE_KP_HASH = 204,
    rho_SCANCODE_KP_SPACE = 205,
    rho_SCANCODE_KP_AT = 206,
    rho_SCANCODE_KP_EXCLAM = 207,
    rho_SCANCODE_KP_MEMSTORE = 208,
    rho_SCANCODE_KP_MEMRECALL = 209,
    rho_SCANCODE_KP_MEMCLEAR = 210,
    rho_SCANCODE_KP_MEMADD = 211,
    rho_SCANCODE_KP_MEMSUBTRACT = 212,
    rho_SCANCODE_KP_MEMMULTIPLY = 213,
    rho_SCANCODE_KP_MEMDIVIDE = 214,
    rho_SCANCODE_KP_PLUSMINUS = 215,
    rho_SCANCODE_KP_CLEAR = 216,
    rho_SCANCODE_KP_CLEARENTRY = 217,
    rho_SCANCODE_KP_BINARY = 218,
    rho_SCANCODE_KP_OCTAL = 219,
    rho_SCANCODE_KP_DECIMAL = 220,
    rho_SCANCODE_KP_HEXADECIMAL = 221,

    rho_SCANCODE_LCTRL = 224,
    rho_SCANCODE_LSHIFT = 225,
    rho_SCANCODE_LALT = 226, /**< alt, option */
    rho_SCANCODE_LGUI = 227, /**< windows, command (apple), meta */
    rho_SCANCODE_RCTRL = 228,
    rho_SCANCODE_RSHIFT = 229,
    rho_SCANCODE_RALT = 230, /**< alt gr, option */
    rho_SCANCODE_RGUI = 231, /**< windows, command (apple), meta */

    rho_SCANCODE_MODE = 257,    /**< I'm not sure if this is really not covered
                                 *   by any of the above, but since there's a
                                 *   special KMOD_MODE for it I'm adding it here
                                 */

    /* @} *//* Usage page 0x07 */

    /**
     *  \name Usage page 0x0C
     *
     *  These values are mapped from usage page 0x0C (USB consumer page).
     */
    /* @{ */

    rho_SCANCODE_AUDIONEXT = 258,
    rho_SCANCODE_AUDIOPREV = 259,
    rho_SCANCODE_AUDIOSTOP = 260,
    rho_SCANCODE_AUDIOPLAY = 261,
    rho_SCANCODE_AUDIOMUTE = 262,
    rho_SCANCODE_MEDIASELECT = 263,
    rho_SCANCODE_WWW = 264,
    rho_SCANCODE_MAIL = 265,
    rho_SCANCODE_CALCULATOR = 266,
    rho_SCANCODE_COMPUTER = 267,
    rho_SCANCODE_AC_SEARCH = 268,
    rho_SCANCODE_AC_HOME = 269,
    rho_SCANCODE_AC_BACK = 270,
    rho_SCANCODE_AC_FORWARD = 271,
    rho_SCANCODE_AC_STOP = 272,
    rho_SCANCODE_AC_REFRESH = 273,
    rho_SCANCODE_AC_BOOKMARKS = 274,

    /* @} *//* Usage page 0x0C */

    /**
     *  \name Walther keys
     *
     *  These are values that Christian Walther added (for mac keyboard?).
     */
    /* @{ */

    rho_SCANCODE_BRIGHTNESSDOWN = 275,
    rho_SCANCODE_BRIGHTNESSUP = 276,
    rho_SCANCODE_DISPLAYSWITCH = 277, /**< display mirroring/dual display
                                           switch, video mode switch */
    rho_SCANCODE_KBDILLUMTOGGLE = 278,
    rho_SCANCODE_KBDILLUMDOWN = 279,
    rho_SCANCODE_KBDILLUMUP = 280,
    rho_SCANCODE_EJECT = 281,
    rho_SCANCODE_SLEEP = 282,

    rho_SCANCODE_APP1 = 283,
    rho_SCANCODE_APP2 = 284,

    /* @} *//* Walther keys */

    /* Add any other keys here. */

    rho_NUM_SCANCODES = 512 /**< not a key, just marks the number of scancodes
                                 for array bounds */
} scancode;
