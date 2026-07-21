#include "LED_Controller_LP5817DRLR.h"
#include "stm32f4xx_hal_def.h"
#include "stm32f4xx_hal_i2c.h"

#define REGISTER_CHIP_EN (uint8_t)0x00
#define REGISTER_DEV_CONFIG0 (uint8_t)0x01
#define REGISTER_DEV_CONFIG1 (uint8_t)0x02
#define REGISTER_DEV_CONFIG2 (uint8_t)0x03
#define REGISTER_DEV_CONFIG3 (uint8_t)0x04
#define REGISTER_SHUTDOWN_CMD (uint8_t)0x0D
#define REGISTER_RESET_CMD (uint8_t)0x0E
#define REGISTER_UPDATE_CMD (uint8_t)0x0F
#define REGISTER_FLAG_CLR (uint8_t)0x13
#define REGISTER_OUT0_DC (uint8_t)0x14
#define REGISTER_OUT1_DC (uint8_t)0x15
#define REGISTER_OUT2_DC (uint8_t)0x16
#define REGISTER_OUT0_MANUAL_PWM (uint8_t)0x18
#define REGISTER_OUT1_MANUAL_PWM (uint8_t)0x19
#define REGISTER_OUT2_MANUAL_PWM (uint8_t)0x1A
#define REGISTER_FLAG (uint8_t)0x40

#define FEILD_REGISTER_CHIP_EN_ENABLE (uint8_t)1
#define FEILD_REGISTER_CHIP_EN_DISABLE (uint8_t)0

led_controller_lp5817drlr_status_t led_controller_lp5817drlr_enable(led_controller_lp5817drlr_object_t *led_controller_object, uint32_t timeout_ms)
{
    uint8_t enable_data[] = {
        REGISTER_CHIP_EN,
        FEILD_REGISTER_CHIP_EN_ENABLE};

    HAL_StatusTypeDef i2c_comms_status = HAL_I2C_Master_Transmit(led_controller_object->i2c_handler, led_controller_object->i2c_address << 1, enable_data, 2, timeout_ms);
    switch (i2c_comms_status)
    {
    case HAL_OK:
        break;

    default:
        return LED_CONTROLLER_LP5817DRLR_FAILURE;
    }

    HAL_Delay(1);

    uint8_t setup_data[] = {
        REGISTER_DEV_CONFIG0,
        0,
        0,
        0,
        0xBF,
        0xBF,
        0xBF};

    i2c_comms_status = HAL_I2C_Master_Transmit(led_controller_object->i2c_handler, led_controller_object->i2c_address << 1, setup_data, 7, timeout_ms);
    switch (i2c_comms_status)
    {
    case HAL_OK:
    {
        return LED_CONTROLLER_LP5817DRLR_SUCCESS;
    }
    break;

    default:
        return LED_CONTROLLER_LP5817DRLR_FAILURE;
    }
}

led_controller_lp5817drlr_status_t led_controller_lp5817drlr_disable(led_controller_lp5817drlr_object_t *led_controller_object, uint32_t timeout_ms)
{
    uint8_t data[] = {
        REGISTER_CHIP_EN,
        FEILD_REGISTER_CHIP_EN_DISABLE};

    HAL_StatusTypeDef i2c_comms_status = HAL_I2C_Master_Transmit(led_controller_object->i2c_handler, led_controller_object->i2c_address << 1, data, 2, timeout_ms);
    switch (i2c_comms_status)
    {
    case HAL_OK:
    {
        return LED_CONTROLLER_LP5817DRLR_SUCCESS;
    }
    break;

    default:
        return LED_CONTROLLER_LP5817DRLR_FAILURE;
    }

    return LED_CONTROLLER_LP5817DRLR_FAILURE;
}

led_controller_lp5817drlr_status_t led_controller_lp5817drlr_set_led_colour(led_controller_lp5817drlr_object_t *led_controller_object, led_controller_lp5817drlr_colour_t led_colour, uint32_t timeout_ms)
{
    uint8_t data[4];
    data[0] = REGISTER_OUT0_MANUAL_PWM;

    HAL_StatusTypeDef status = HAL_ERROR;

    switch (led_colour)
    {
    case LED_CONTROLLER_LP5817DRLR_RED:
    {
        data[1] = 0xFF;
        data[2] = 0x00;
        data[3] = 0x00;
    }
    break;

    case LED_CONTROLLER_LP5817DRLR_GREEN:
    {
        data[1] = 0;
        data[2] = 0xFF;
        data[3] = 0;
    }
    break;

    case LED_CONTROLLER_LP5817DRLR_BLUE:
    {
        data[1] = 0;
        data[2] = 0;
        data[3] = 0xFF;
    }
    break;

    case LED_CONTROLLER_LP5817DRLR_PURPLE:
    {
        data[1] = 0xFF;
        data[2] = 0;
        data[3] = 0xFF;
    }
    break;

    default:
        data[1] = 0;
        data[2] = 0;
        data[3] = 0;
    }

    status = HAL_I2C_Master_Transmit(led_controller_object->i2c_handler, led_controller_object->i2c_address << 1, data, 4, timeout_ms);

    switch (status)
    {
    case HAL_OK:
    {
        return LED_CONTROLLER_LP5817DRLR_SUCCESS;
    }
    break;

    default:
        return LED_CONTROLLER_LP5817DRLR_FAILURE;
    }

    return LED_CONTROLLER_LP5817DRLR_FAILURE;
}

led_controller_lp5817drlr_status_t led_controller_lp5817drlr_get_led_colour(led_controller_lp5817drlr_object_t *led_controller_object, led_controller_lp5817drlr_colour_t *led_colour, uint32_t timeout_ms)
{
    return LED_CONTROLLER_LP5817DRLR_NOT_IMPLEMENTED;
}
