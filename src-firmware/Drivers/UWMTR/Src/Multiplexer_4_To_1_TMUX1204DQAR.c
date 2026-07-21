#include "Multiplexer_4_To_1_TMUX1204DQAR.h"
#include "main.h"

#include <stddef.h>

Multiplexer_4_To_1_TMUX1204DQAR_Status_t multiplexer_4_to_1_tmux1204dqar_set_channel(Multiplexer_4_To_1_TMUX1204DQAR_Object_t *multiplexer_object, Multiplexer_4_To_1_TMUX1204DQAR_Channel_t multiplexer_channel)
{
    if (multiplexer_channel == Multiplexer_4_To_1_TMUX1204DQAR_Channel_Off && multiplexer_object->en_port == NULL)
    {
        return Multiplexer_4_To_1_TMUX1204DQAR_Status_Connection_Error;
    }

    HAL_StatusTypeDef hal_status = HAL_OK;

    switch (multiplexer_channel)
    {
    case Multiplexer_4_To_1_TMUX1204DQAR_Channel_Off:
    {
        HAL_GPIO_WritePin(multiplexer_object->en_port, multiplexer_object->en_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(multiplexer_object->a0_port, multiplexer_object->a0_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(multiplexer_object->a1_port, multiplexer_object->a1_pin, GPIO_PIN_RESET);
    }
    break;

    case Multiplexer_4_To_1_TMUX1204DQAR_Channel_S1:
    {
        HAL_GPIO_WritePin(multiplexer_object->en_port, multiplexer_object->en_pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(multiplexer_object->a0_port, multiplexer_object->a0_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(multiplexer_object->a1_port, multiplexer_object->a1_pin, GPIO_PIN_RESET);
    }
    break;

    case Multiplexer_4_To_1_TMUX1204DQAR_Channel_S2:
    {
        HAL_GPIO_WritePin(multiplexer_object->en_port, multiplexer_object->en_pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(multiplexer_object->a0_port, multiplexer_object->a0_pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(multiplexer_object->a1_port, multiplexer_object->a1_pin, GPIO_PIN_RESET);
    }
    break;

    case Multiplexer_4_To_1_TMUX1204DQAR_Channel_S3:
    {
        HAL_GPIO_WritePin(multiplexer_object->en_port, multiplexer_object->en_pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(multiplexer_object->a0_port, multiplexer_object->a0_pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(multiplexer_object->a1_port, multiplexer_object->a1_pin, GPIO_PIN_SET);
    }
    break;

    case Multiplexer_4_To_1_TMUX1204DQAR_Channel_S4:
    {
        HAL_GPIO_WritePin(multiplexer_object->en_port, multiplexer_object->en_pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(multiplexer_object->a0_port, multiplexer_object->a0_pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(multiplexer_object->a1_port, multiplexer_object->a1_pin, GPIO_PIN_SET);
    }
    break;

    default:
        return Multiplexer_4_To_1_TMUX1204DQAR_Status_Not_Implemented;
    }

    if (hal_status == HAL_OK)
    {
        return Multiplexer_4_To_1_TMUX1204DQAR_Status_Success;
    }

    return Multiplexer_4_To_1_TMUX1204DQAR_Status_Failure;
}