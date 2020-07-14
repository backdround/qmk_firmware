#include QMK_KEYBOARD_H

////////////////////////////////////////
// Key aliases.

// OS tab
#define TAB RALT(KC_H)
#define SH_INS LSFT(KC_INS)
#define SH_TAB RSFT(KC_TAB)

// OS language switch
#define TO_US KC_CAPS
#define TO_RU LSFT(KC_CAPS)
#define TO_DV LCTL(KC_CAPS)

// OS printscreens
#define I_PSCR LGUI(KC_PSCR) // Interactive
#define F_PSCR LCTL(KC_PSCR) // Full virtual space
#define W_PSCR LSFT(KC_PSCR) // Window

// Additional ru keys
#define O_TSE KC_KP_1 // ц
#define O_SHS KC_KP_2 // щ
#define O_SHE KC_KP_3 // ш
#define O_FEE KC_KP_4 // ф
#define O_YUU KC_KP_5 // ю
#define O_YEE KC_KP_6 // э


////////////////////////////////////////
// Layouts.

enum LAYOUTS {
    _QWERTY,
    _SYMBOLS,
    _ADDITIONAL,
    _SPECIAL,
    _CUSTOMIZATION
};

// Momentary layout
#define SYMB_ MO(_SYMBOLS)
#define ADD_  MO(_ADDITIONAL)
#define SPEC_ MO(_SPECIAL)
#define CUST_ MO(_CUSTOMIZATION)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_1,    TO_DV,   TO_US,   TO_RU,   CUST_,                              CUST_,   KC_VOLU, KC_MUTE, KC_VOLD, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     SPEC_,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SPEC_,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    ADD_,    KC_LCTL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           SPEC_,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, SYMB_,                     SYMB_,   KC_SPC,  KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, I_PSCR,  KC_PSCR, F_PSCR,  W_PSCR,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_PLUS, KC_EQL,  KC_AMPR, KC_ASTR,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_UNDS, KC_LPRN, KC_RPRN, KC_PIPE,                            TAB,     KC_ENT,  KC_ESC,  KC_BSPC, SH_TAB,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS, _______,          _______, KC_INS,  _______, _______, KC_DEL,  SH_INS,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADDITIONAL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_TILD, KC_GRV,  KC_DQUO, KC_QUOT,  _______,                           _______, O_SHS,   O_FEE,   _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_QUES, KC_SCLN, KC_COLN, KC_DLR,                             O_TSE,   O_YUU,   O_SHE,   _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_PERC, KC_AT,   KC_CIRC,  _______, _______,         _______, _______, O_YEE,   _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SPECIAL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                               _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,          _______, _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_CUSTOMIZATION] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_SAI, RGB_M_P, BL_BRTG, _______, RESET,   _______,                            _______, RESET,   _______, RGB_SAI, RGB_M_P, BL_BRTG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_SAD, RGB_TOG, BL_TOGG, _______, _______, _______,                            _______, _______, _______, RGB_SAD, RGB_TOG, BL_TOGG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUI, RGB_VAI, BL_INC,  _______, _______, _______,                            _______, _______, _______, RGB_HUI, RGB_VAI, BL_INC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_HUD, RGB_VAD, BL_DEC,  _______, _______, _______, _______,          _______, _______, _______, _______, RGB_HUD, RGB_VAD, BL_DEC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    return true;
}
