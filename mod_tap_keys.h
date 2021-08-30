// MOD_TAP_KEY(key, tap_action, mod_on_action, mod_off_action)

MOD_TAP_KEY(TOP, {SEND_STRING(SS_TAP(X_ENT));}, {layer_on(_TOP);}, {layer_off(_TOP);})
MOD_TAP_KEY(BOTTOM, {SEND_STRING(SS_LALT(SS_TAP(X_BSPACE)));}, {layer_on(_BOTTOM);}, {layer_off(_BOTTOM);})

