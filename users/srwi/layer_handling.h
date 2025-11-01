#pragma once

#include "raw_hid.h"
#include "usb_descriptor.h"

void via_custom_value_command_kb(uint8_t *data, uint8_t length);

layer_state_t layer_state_set_user(layer_state_t state);

layer_state_t default_layer_state_set_user(layer_state_t state);
