#pragma once

#include "main.h"

/*
If `EN` pin is tied to VDD:
- Set `EN_PORT = null`.
- Set `EN_PIN = 0`.
*/
typedef struct {
    GPIO_TypeDef *A0_PORT,
    uint16_t A0_PIN,

    GPIO_TypeDef *A1_PORT,
    uint16_t A1_PIN,

    GPIO_TypeDef *EN_PORT,
    uint16_t EN_PIN,
} Multiplexer_4_To_1_TMUX1204DQAR_Object_t;
