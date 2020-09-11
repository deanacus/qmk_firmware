#include QMK_KEYBOARD_H

enum layer_names {
		_MBL,
		_MFL,
		_WBL,
		_WFL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_MBL] = LAYOUT_60_ansi(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		MO(_MFL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT, KC_RCTL, KC_GRV
	),
	[_MFL] = LAYOUT_60_ansi(
		KC_GRV, KC_NO, KC_F2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_UP, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
		KC_TRNS, KC_NO, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_ENT,
		KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
		KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT, KC_RCTL, DF(_WBL)
	),
	[_WBL] = LAYOUT_60_ansi(
		KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
		MO(_WFL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
		KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, KC_RCTL, KC_RGUI, KC_RALT, KC_GRV
	),
	[_WFL] = LAYOUT_60_ansi(
		KC_GRV, KC_NO, KC_F2, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
		KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_UP, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
		KC_TRNS, KC_NO, KC_NO, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_ENT,
		KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT,
		KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, KC_RCTL, KC_RGUI, KC_RALT, DF(_MBL)
	),
};

enum combo_events {
  CTL_Q_ALT_F4,
  CTL_TAB_ALT_TAB
};

const uint16_t PROGMEM ctl_q_alt_f4[] = {KC_LCTL, KC_Q, COMBO_END};
const uint16_t PROGMEM ctl_tab_alt_tab[] = {KC_LCTL, KC_TAB, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CTL_Q_ALT_F4] = COMBO_ACTION(ctl_q_alt_f4),
  [CTL_TAB_ALT_TAB] = COMBO_ACTION(ctl_tab_alt_tab)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CTL_Q_ALT_F4:
      if (pressed) {
        tap_code16(LALT(KC_F4));
      }
      break;
    case CTL_TAB_ALT_TAB:
      if (pressed && layer_state_is(_WBL)) {
        tap_code16(LALT(KC_TAB));
      }
      break;
  }
}