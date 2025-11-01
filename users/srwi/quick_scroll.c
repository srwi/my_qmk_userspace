#include "quick_scroll.h"

static bool quick_scroll_up_active = false;    // Track if QS_UP is active
static bool quick_scroll_down_active = false;  // Track if QS_DOWN is active
static bool quick_scroll_left_active = false;  // Track if QS_LEFT is active
static bool quick_scroll_right_active = false; // Track if QS_RGHT is active
static uint16_t last_scroll_time = 0;          // Timer for repeats

void perform_quick_scroll_action(uint16_t keycode) {
    switch (keycode) {
        case QS_UP:
            SEND_STRING(SS_DOWN(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_UP));
            SEND_STRING(SS_UP(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_UP));
            break;

        case QS_DOWN:
            SEND_STRING(SS_DOWN(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_DOWN));
            SEND_STRING(SS_UP(X_LEFT_CTRL));
            SEND_STRING(SS_TAP(X_DOWN));
            break;
        case QS_LEFT:
            SEND_STRING(SS_TAP(X_LEFT));
            break;
        case QS_RGHT:
            SEND_STRING(SS_TAP(X_RIGHT));
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QS_UP:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_UP);
                quick_scroll_up_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_up_active = false;
            }
            return false;

        case QS_DOWN:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_DOWN);
                quick_scroll_down_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_down_active = false;
            }
            return false;
        case QS_LEFT:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_LEFT);
                quick_scroll_left_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_left_active = false;
            }
            return false;
        case QS_RGHT:
            if (record->event.pressed) {
                perform_quick_scroll_action(QS_RGHT);
                quick_scroll_right_active = true;
                last_scroll_time = timer_read();
            } else {
                quick_scroll_right_active = false;
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

void matrix_scan_user(void) {
    static const uint16_t repeat_interval = 12; // Time between repeats in milliseconds

    if (timer_elapsed(last_scroll_time) > repeat_interval) {
        if (quick_scroll_up_active) {
            perform_quick_scroll_action(QS_UP);
        }

        if (quick_scroll_down_active) {
            perform_quick_scroll_action(QS_DOWN);
        }

        if (quick_scroll_left_active) {
            perform_quick_scroll_action(QS_LEFT);
        }

        if (quick_scroll_right_active) {
            perform_quick_scroll_action(QS_RGHT);
        }

        last_scroll_time = timer_read();
    }
}
