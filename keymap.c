#include QMK_KEYBOARD_H
#include <sendstring_dvorak.h>
#include "muse.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _QWERTY,
  _EN,
  _LOWER,
  _RAISE,
  _ADJUST
};

bool is_qwerty_active = false;

float USSR_SONG[][2] = SONG(B__NOTE(_G6), 
  B__NOTE(_C7), W__NOTE(_G6), H__NOTE(_A6), 
  B__NOTE(_B6), W__NOTE(_E6), W__NOTE(_E6), 
  B__NOTE(_A6), W__NOTE(_G6), H__NOTE(_F6),
  B__NOTE(_G6), W__NOTE(_C6), W__NOTE(_C6),
  B__NOTE(_D6), W__NOTE(_D6), W__NOTE(_E6),
  B__NOTE(_D6), W__NOTE(_D6), W__NOTE(_G6),
  B__NOTE(_F6), W__NOTE(_G6), W__NOTE(_A6),
  B__NOTE(_B6), 
  );

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,

  CTRL,
  ALT,
  GUI,

  BRUDERSCHAFT,

#define MOD_TAP_KEY(keycode, mod_key1, mod_key2, action)   \
  keycode,
#include "mod_tap_keys.h"
#undef MOD_TAP_KEY
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LANG  TG(_QWERTY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LANG | Ctrl | Alt  | GUI  | SPC  |Lower |Raise | SPC  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    KC_TAB,    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_MINS,
    ESC,       KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_BSPC,
    KC_LSFT,   KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SFTENT,
    CH_LANG,   CTRL,    ALT,     GUI,     KC_SPC,  LOWER,   RAISE,   KC_SPC,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT,
    _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* EN
 * ,-----------------------------------------------------------------------------------.
 * |      |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EN] = LAYOUT_planck_grid(
    _______, KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______,
    _______, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | F11  |      |      |   ~  |   %  |      |      |   ^  |   `  |   \  |   |  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  [   |  {   |  +   |  (   |  =   |  *   |   )  |   !  |   }  |   ]  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | LANG |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | RCTL |      |      |      | [{}] |      |      | PSCR | PGDN | PGUP |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_F11,  _______, _______, KC_TILD, KC_PERC, _______, _______, KC_CIRC, KC_GRV,  KC_BSLS, KC_PIPE, KC_MINS,
    KC_DEL,  KC_LBRC, KC_LCBR, KC_PLUS, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN, KC_EXLM, KC_RCBR, KC_RBRC, _______,
    _______, _______, _______, _______, LANG,    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_RCTL, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_PGDN, KC_PGUP, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | F11  |      |      |  $   |  &   |      |      |   ?  |   @  |   #  |   /  | F12  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  7   |  5   |  3   |  1   |  9   |  0   |  2   |  4   |  6   |  8   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F5  |  F3  |  F1  |  F9  |  F10 |  F2  |  F4  |  F6  |  F8  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | [{}] |      | Vol- | End  | Home | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_F11,  _______, _______, KC_DLR,  KC_AMPR, _______, _______, KC_QUES, KC_AT,   KC_HASH, KC_SLSH, KC_F12,
    _______, KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    KC_DEL,
    _______, KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,   KC_F10,  KC_F2,   KC_F4,   KC_F6,   KC_F8,   _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_END,  KC_HOME, KC_VOLU
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Aud on|Audoff|      |      |      |      |      |      |Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Mus on|Musoff|      |      |      |      |      |      |      |      | USSR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | [{}] | [{}] |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, DVORAK,  _______, _______,
    _______, MU_ON,   MU_OFF,  _______, _______, _______, _______, _______, _______, _______, _______, BRUDERSCHAFT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#define CHANGE_LANGUAGE {                           \
  if (is_qwerty_active) {                           \
    layer_off(_QWERTY);                             \
    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_1))));     \
  } else {                                          \
    layer_on(_QWERTY);                              \
    SEND_STRING(SS_LSFT(SS_LCTL(SS_TAP(X_2))));     \
  }                                                 \
  is_qwerty_active = !is_qwerty_active;             \
};

#define CASE(keycode, key_pressed_action, key_released_action)  \
  case (keycode):                                               \
    if (record->event.pressed) {                                \
      key_pressed_action;                                       \
    } else {                                                    \
      key_released_action;                                      \
    }                                                           \
    return false;                                               \
    break;

#define CASE_PRESSED(keycode, key_pressed_action) CASE(keycode, key_pressed_action, {});

#define CASE_WITH_ON_EN(keycode, key_pressed_action, key_released_action)   \
  CASE(keycode,                                                             \
    {layer_on(_EN); key_pressed_action;},                                   \
    {key_released_action; layer_off(_EN);}                                  \
  );

#define CASE_WITH_ON_EN_PRESS(keycode)      \
  CASE_WITH_ON_EN(                          \
    keycode,                                \
    SEND_STRING(SS_DOWN(X_L ## keycode)),   \
    SEND_STRING(SS_UP(X_L ## keycode))      \
  );

#define CASE_MOD_TAP_KEY(keycode, mod_key1, mod_key2, action)\
  CASE_WITH_ON_EN(keycode, {                                 \
    keycode ## _TIMER = timer_read();                        \
    IS_ ## keycode ## _ACTIVE = true;                        \
  }, {                                                       \
    if(IS_ ## mod_key1 ## _ ## mod_key2 ## _ACTIVE) {        \
      unregister_code(KC_L ## mod_key1);                     \
      unregister_code(KC_L ## mod_key2);                     \
      IS_ ## mod_key1 ## _ ## mod_key2 ## _ACTIVE = false;   \
    } else {                                                 \
      action                                                 \
    }                                                        \
    IS_ ## keycode ## _ACTIVE = false;                       \
  });

#define MOD_TAP_KEY(keycode, mod_key1, mod_key2, action)    \
uint16_t keycode ## _TIMER = 0;                             \
bool IS_ ## keycode ## _ACTIVE = false;                     \
bool IS_ ## mod_key1 ## _ ## mod_key2 ## _ACTIVE = false;
#include "mod_tap_keys.h"
#undef MOD_TAP_KEY

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    CASE_WITH_ON_EN_PRESS(CTRL);
    CASE_WITH_ON_EN_PRESS(ALT);
    CASE_WITH_ON_EN_PRESS(GUI);

    CASE_PRESSED(BRUDERSCHAFT, PLAY_SONG(USSR_SONG));
    CASE_PRESSED(DVORAK, set_single_persistent_default_layer(_DVORAK));

    #define MOD_TAP_KEY(keycode, mod_key1, mod_key2, action)    \
    CASE_MOD_TAP_KEY(keycode, mod_key1, mod_key2, action);
    #include "mod_tap_keys.h"
    #undef MOD_TAP_KEY

  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #define MOD_TAP_KEY(keycode, mod_key1, mod_key2, action)  \
  if (IS_ ## keycode ## _ACTIVE) {                          \
    if (timer_elapsed(keycode ## _TIMER) > TAPPING_TERM) {  \
      register_code(KC_L ## mod_key1);                      \
      register_code(KC_L ## mod_key2);                      \
      IS_ ## mod_key1 ## _ ## mod_key2 ## _ACTIVE = true;   \
    }                                                       \
  }
  #include "mod_tap_keys.h"
  #undef MOD_TAP_KEY

  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
