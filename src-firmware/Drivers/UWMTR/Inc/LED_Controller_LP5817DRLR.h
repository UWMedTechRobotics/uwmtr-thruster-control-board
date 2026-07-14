#pragma once

/*
Note only independent mode will be implemented.
*/

#include "main.h"

#define LED_CONTROLLER_LP5817DRLR_I2C_ADDRESS 0x2D // Read = (0x2D << 1 + 1), Write = (0x2D << 1)

typedef struct {
    I2C_HandleTypeDef *i2c_handler;
    uint16_t i2c_address;  
} led_controller_lp5817drlr_object_t;

typedef enum {
    LED_CONTROLLER_LP5817DRLR_RED = 0,  // Red for indicating failure.
    LED_CONTROLLER_LP5817DRLR_GREEN,    // Green for indicating motor spinning.
    LED_CONTROLLER_LP5817DRLR_PURPLE,   // Purple for indicating serial communication.
    LED_CONTROLLER_LP5817DRLR_BLUE,     // Blue for indicating idle state.
} led_controller_lp5817drlr_colour_t;

typedef enum {
    LED_CONTROLLER_LP5817DRLR_SUCCESS = 0,
    LED_CONTROLLER_LP5817DRLR_FAILURE,
    LED_CONTROLLER_LP5817DRLR_NOT_IMPLEMENTED,
} led_controller_lp5817drlr_state_t;

led_controller_lp5817drlr_state_t led_controller_lp5817drlr_set_led_colour(led_controller_lp5817drlr_colour_t led_colour);

led_controller_lp5817drlr_state_t led_controller_lp5817drlr_get_led_colour(led_controller_lp5817drlr_colour_t *led_colour);
