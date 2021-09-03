// MOD_TAP_KEY(key, tap_action, mod_on_action, mod_off_action)

MOD_TAP_KEY(TOP, tap_code(KC_ENT), layer_on(_TOP), layer_off(_TOP))
MOD_TAP_KEY(BOTTOM, tap_code16(A(KC_BSPC)), layer_on(_BOTTOM), layer_off(_BOTTOM))

MOD_TAP_KEY(S_GUIQ, tap_code(KC_S), {layer_on(_EN); register_code(KC_LGUI);}, {layer_off(_EN); unregister_code(KC_LGUI);})
MOD_TAP_KEY(L_GUIQ, tap_code(KC_L), {layer_on(_EN); register_code(KC_RGUI);}, {layer_off(_EN); unregister_code(KC_RGUI);})

MOD_TAP_KEY(F_CTLQ, tap_code(KC_F), {layer_on(_EN); register_code(KC_LCTL);}, {layer_off(_EN); unregister_code(KC_LCTL);})
MOD_TAP_KEY(J_CTLQ, tap_code(KC_J), {layer_on(_EN); register_code(KC_RCTL);}, {layer_off(_EN); unregister_code(KC_RCTL);})

MOD_TAP_KEY(A_ALTQ, tap_code(KC_A), {layer_on(_EN); register_code(KC_LALT);}, {layer_off(_EN); unregister_code(KC_LALT);})
MOD_TAP_KEY(SCLN_Q, tap_code(KC_SCLN), {layer_on(_EN); register_code(KC_RALT);}, {layer_off(_EN); unregister_code(KC_RALT);})
