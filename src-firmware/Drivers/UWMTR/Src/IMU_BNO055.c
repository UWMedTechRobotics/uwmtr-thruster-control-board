#include <stdint.h>

#include "IMU_BNO055.h"

#define BNO055_CHIP_ID_REGISTER 0xA0
#define BNO055_CHIP_ID 0xA0

bno055_status_t bno055_test_connection(const bno055_object_t *bno055_object, uint32_t timeout)
{
    uint8_t chip_id_register[] = {BNO055_CHIP_ID_REGISTER};

    HAL_StatusTypeDef status = HAL_I2C_Master_Transmit(bno055_object->i2c_handler, bno055_object->i2c_address, chip_id_register, 1, timeout);

    if (status != HAL_OK)
    {
        return BNO055_FAILURE;
    }

    uint8_t rx_buffer[1];
    status = HAL_I2C_Master_Receive(bno055_object->i2c_handler, bno055_object->i2c_address, rx_buffer, 1, 1000);

    if (status != HAL_OK)
    {
        return BNO055_FAILURE;
    }

    return BNO055_SUCCESS;
}