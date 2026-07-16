#pragma once

#include <stdint.h>

#include "main.h"

#define BNO055_I2C_ADDRESS_ADDR_GND 0x28 << 1
#define BNO055_I2C_ADDRESS_ADDR_PWR 0x29 << 1

typedef struct {
    I2C_HandleTypeDef *i2c_handler;
    uint16_t i2c_address;  
} bno055_object_t;

typedef enum {
    BNO055_SUCCESS = 0,
    BNO055_FAILURE
} bno055_status_t;

/*
Attempts to read the IMU's chip ID from it's chip ID register.
- If successful, returns `BNO055_SUCCESS`.
- If failure, returns `BNO055_FAILURE`.
*/
bno055_status_t bno055_test_connection(const bno055_object_t *bno055_object, uint32_t timeout);