#pragma once

#include "quantum.h"

enum my_keycodes {
  QS_UP = SAFE_RANGE,
  QS_DOWN,
  QS_LEFT,
  QS_RGHT
};

void perform_quick_scroll_action(uint16_t keycode);

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void matrix_scan_user(void);
