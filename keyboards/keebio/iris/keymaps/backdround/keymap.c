#include QMK_KEYBOARD_H


////////////////////////////////////////
// Independent keys.

enum INDEPENDENT_KEYCODES {
    FIRST_INDEPENDENT_KEYCODE = SAFE_RANGE,

    I_COMM,
    I_DOT,
    I_COLN,

    I_SCLN,
    I_AMPR,
    I_ASTR,

    I_LBRC,
    I_RBRC,
    I_LCBR,
    I_RCBR,

    I_TILD,
    I_GRV,
    I_DQUO,
    I_QUOT,
    I_EXLM,
    I_QUES,
    I_SLSH,
    I_DLR,
    I_PERC,
    I_AT,
    I_CIRC,

    LAST_INDEPENDENT_KEYCODE
};

static const uint16_t independent_keys[] = {
    KC_COMM,
    KC_DOT ,
    KC_COLN,

    KC_SCLN,
    KC_AMPR,
    KC_ASTR,

    KC_LBRC,
    KC_RBRC,
    KC_LCBR,
    KC_RCBR,

    KC_TILD,
    KC_GRV ,
    KC_DQUO,
    KC_QUOT,
    KC_EXLM,
    KC_QUES,
    KC_SLSH,
    KC_DLR ,
    KC_PERC,
    KC_AT  ,
    KC_CIRC
};



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
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,           SPEC_,   KC_N,    KC_M,    I_COMM,  I_DOT,   I_SLSH,  KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_LGUI, SYMB_,                     SYMB_,   KC_SPC,  KC_LALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, I_PSCR,  KC_PSCR, F_PSCR,  W_PSCR,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_MINS, KC_PLUS, KC_EQL,  I_AMPR,  I_ASTR,                             KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_HASH, KC_UNDS, KC_LPRN, KC_RPRN, KC_PIPE,                            TAB,     KC_ENT,  KC_ESC,  KC_BSPC, SH_TAB,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, I_LBRC,  I_RBRC,  I_LCBR,  I_RCBR,  KC_BSLS, _______,          _______, KC_INS,  _______, _______, KC_DEL,  SH_INS,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADDITIONAL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, I_TILD,  I_GRV,   I_DQUO,  I_QUOT,  _______,                            _______, KC_LBRC, KC_SCLN, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, I_EXLM,  I_QUES,  I_SCLN,  I_COLN,  I_DLR,                              KC_RBRC, KC_DOT,  KC_COMM, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, I_PERC,  I_AT,    I_CIRC,  _______, _______,          _______, _______, KC_QUOT, _______, _______, _______, _______,
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



enum LAYOUT {
    US,
    RU,
    DV,
    LAST_LAYOUT
};
static enum LAYOUT current_layout = US;

bool sync_os_layout(uint16_t keycode) {
    if (keycode == TO_US) {
        current_layout = US;
        return true;
    } else if (keycode == TO_RU) {
        current_layout = RU;
        return true;
    } else if (keycode == TO_DV) {
        current_layout = DV;
        return true;
    }
    return false;
}



void tap_us_key(uint16_t keycode) {
    bool l_shifted = get_mods() & MOD_BIT(KC_LSFT);
    bool r_shifted = get_mods() & MOD_BIT(KC_RSFT);


    bool shifted = l_shifted || r_shifted;
    if (shifted) { clear_mods(); }

    tap_code16(TO_US);

    if (shifted) {
        tap_code16(LSFT(keycode));
    } else {
        tap_code16(keycode);
    }

    if (current_layout == RU) {
        tap_code16(TO_RU);
    } else if (current_layout == DV) {
        tap_code16(TO_DV);
    }


    if (l_shifted) { register_code16(KC_LSFT); }
    if (r_shifted) { register_code16(KC_RSFT); }
}


bool handle_custom_keys(uint16_t keycode, bool pressed) {
    if (keycode <= FIRST_INDEPENDENT_KEYCODE || keycode >= LAST_INDEPENDENT_KEYCODE) {
        return false;
    }

    int index = keycode - 1 - FIRST_INDEPENDENT_KEYCODE;

    uint16_t independent_keycode = independent_keys[index];
    if (current_layout == RU && pressed) {
        tap_us_key(independent_keycode);
        return true;
    }

    if (pressed) {
        register_code16(independent_keycode);
    } else {
        unregister_code16(independent_keycode);
    }

    return true;
}



bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (sync_os_layout(keycode)) {
        return true;
    }


    // Pass common keys.
    if (keycode < FIRST_INDEPENDENT_KEYCODE || keycode > LAST_INDEPENDENT_KEYCODE) {
        return true;
    }


    if (handle_custom_keys(keycode, record->event.pressed)) {
        return false;
    }

    // Unexpected situation.
    return true;
}
