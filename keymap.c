#include QMK_KEYBOARD_H
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

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,

  CTRL,
  ALT,
  GUI,

  RU,
  DVP,

  EN_LANG,
  RU_LANG,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ESC LCA_T(KC_ESC)  // ESC when tapped and CTRL + ALT   when held
#define TAB C_S_T(KC_TAB)  // TAB when tapped and CTPL + SHIFT when held

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RULANG| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_planck_grid(
    TAB,     KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
    ESC,     KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS,
    KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_SFTENT,
    RU_LANG, CTRL,    ALT,     GUI,     LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |ENLANG| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    _______,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    _______,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  _______ ,
    EN_LANG,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______
),

/* EN
 * ,-----------------------------------------------------------------------------------.
 * |      |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EN] = LAYOUT_planck_grid(
    _______, KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    _______,
    _______, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    _______,
    _______, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |   ~  |   %  |      |      |   ^  |   `  |   \  |   |  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  [   |  {   |  }   |  (   |  =   |  *   |   )  |   +  |   !  |   ]  |  -   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | RU   |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | PSCR | PGDN | PGUP |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, KC_TILD, KC_PERC, _______, _______, KC_CIRC, KC_GRV,  KC_BSLS, KC_PIPE, _______,
    KC_DEL,  KC_LBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_EQL,  KC_ASTR, KC_RPRN, KC_PLUS, KC_EXLM, KC_RBRC, KC_MINS,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   RU,      _______, _______, _______, _______,
    _______, KC_RCTL, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_PGDN, KC_PGUP, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  $   |  &   |      |      |   ?  |   @  |   #  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  7   |  5   |  3   |  1   |  9   |  0   |   2  |   4  |   6  |   8  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | DVP  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Vol- | End  | Home | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______, KC_DLR,  KC_AMPR, _______, _______, KC_QUES, KC_AT,   KC_HASH, KC_SLSH, _______,
    KC_DEL,  KC_7,    KC_5,    KC_3,    KC_1,    KC_9,    KC_0,    KC_2,    KC_4,    KC_6,    KC_8,    _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DVP,     _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_END,  KC_HOME, KC_VOLU
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|      |Dvorak|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, _______, QWERTY,  _______,  DVORAK,  _______, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;

    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;

    case RU:  // turns on russian(qwerty) layer
        if (record->event.pressed) {
            layer_on(_QWERTY);
        }
        return false;
        break;

    case DVP:  // turns off russian(qwerty) layer
        if (record->event.pressed) {
            layer_off(_QWERTY);
        }
        return false;
        break;

    case CTRL:
        if (record->event.pressed) {
            layer_on(_EN);
            SEND_STRING(SS_DOWN(X_LCTRL));
        } else {
            layer_off(_EN);
            SEND_STRING(SS_UP(X_LCTRL));
        }
        return false;
        break;

    case ALT:
        if (record->event.pressed) {
           layer_on(_EN);
           SEND_STRING(SS_DOWN(X_LALT));
        } else {
           layer_off(_EN);
           SEND_STRING(SS_UP(X_LALT));
        }
        return false;
        break;

    case GUI:
        if (record->event.pressed) {
            layer_on(_EN);
            SEND_STRING(SS_DOWN(X_LGUI));
        } else {
            layer_off(_EN);
            SEND_STRING(SS_UP(X_LGUI));
        }
        return false;
        break;

    case EN_LANG:  // sends win + space and turns off russan(qwerty) layer
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI));
            SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_LALT) SS_UP(X_LSHIFT));
            layer_off(_QWERTY);
        }
        return false;
        break;

    case RU_LANG:  // sends win + space and turns on russian(qwerty) layer
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_SPACE) SS_UP(X_LGUI));
            SEND_STRING(SS_DOWN(X_LSHIFT) SS_TAP(X_LALT) SS_UP(X_LSHIFT));
            layer_on(_QWERTY);
        }
        return false;
        break;


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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
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
