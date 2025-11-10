#include "layer_handling.h"

// Switch layer using the command (replace L with the desired layer):
// ./hidapitester.exe --vidpid 594D/604D --usagePage 0xff60 --usage 0x61 --open --send-output 0,9,0,1,L --close
void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    uint8_t *value_id = &(data[2]);
    uint8_t *value_data = &(data[3]);

    switch(*value_id) {
        case 1:
            layer_move(*value_data);
            break;
        default:
            *command_id = id_unhandled;
            break;
    }
}

// Save the last layer to EEPROM
layer_state_t default_layer_state_set_user(layer_state_t state) {
	eeconfig_update_default_layer(state);
	return state;
}

// Notify VIA about layer changes
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t data[RAW_EPSIZE] = {0};
    data[0] = 0xff;
    data[1] = sizeof(layer_state_t);
    memcpy(&data[2], &default_layer_state, sizeof(layer_state_t));
    memcpy(&data[2 + sizeof(layer_state_t)], &state, sizeof(layer_state_t));
    raw_hid_send(data, RAW_EPSIZE);
    return state;
}
