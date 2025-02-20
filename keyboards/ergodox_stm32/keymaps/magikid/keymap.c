#include QMK_KEYBOARD_H

enum custom_keycodes {
	TMUXSWITCH = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_ergodox(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LPRN,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC,
        KC_LCTL, KC_LGUI, KC_LALT, KC_MPLY, KC_MFFD,
        KC_INS, KC_LCTL, KC_HOME, KC_SPC, KC_DEL, KC_END,

        KC_EQL, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_RPRN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS,
                 KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LCTL,
                       KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RCTL,
        MO(1), TG(2), KC_PGUP, KC_PGDN, KC_BSPC, KC_ENT
    ),

	[1] = LAYOUT_ergodox(
        KC_TILD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,
        KC_GRV, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, TMUXSWITCH, KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS,

        KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSPC,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, LCTL(LGUI(KC_Q)), KC_MPRV, KC_MNXT, KC_VOLD, KC_VOLU
    ),

	[2] = LAYOUT_ergodox(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_TRNS,
		         KC_TRNS, KC_P4, KC_P5, KC_P6, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_ENT, KC_TRNS,
                          KC_PDOT, KC_P0, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TMUXSWITCH:
        if (record->event.pressed) {
            // when keycode TMUXSWITCH is pressed
			// send CTRL+s, CTRL+j
            SEND_STRING(SS_LCTL("sj"));
        }
        break;
    }
    return true;
};
