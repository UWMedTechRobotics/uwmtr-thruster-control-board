#pragma once

#include "main.h"
#include "stdint.h"

/*
If `EN` pin is tied to VDD:
- Set `EN_PORT = nullptr`.
- Set `EN_PIN = 0`.
*/
typedef struct {
    GPIO_TypeDef *a0_port;
    uint16_t a0_pin;

    GPIO_TypeDef *a1_port;
    uint16_t a1_pin;

    GPIO_TypeDef *en_port;
    uint16_t en_pin;
} Multiplexer_4_To_1_TMUX1204DQAR_Object_t;

/*
Note that the multiplexer cannot be off if `en_pin` is tied to VDD.

In the event that `en_pin` is tied to VDD, setting the channel to
`Multiplexer_4_To_1_TMUX1204DQAR_Channel_Off` will just maintain the previous
state set. Also, in this case, 
`Multiplexer_4_To_1_TMUX1204DQAR_Status_Connection_Error` will be returned by 
any relevant functions.

When enabled, the default state is `Multiplexer_4_To_1_TMUX1204DQAR_Channel_S1`.
*/
typedef enum {
    Multiplexer_4_To_1_TMUX1204DQAR_Channel_Off = 0,
    Multiplexer_4_To_1_TMUX1204DQAR_Channel_S1,
    Multiplexer_4_To_1_TMUX1204DQAR_Channel_S2,
    Multiplexer_4_To_1_TMUX1204DQAR_Channel_S3,
    Multiplexer_4_To_1_TMUX1204DQAR_Channel_S4,
} Multiplexer_4_To_1_TMUX1204DQAR_Channel_t;

typedef enum {
    Multiplexer_4_To_1_TMUX1204DQAR_Status_Success = 0,
    Multiplexer_4_To_1_TMUX1204DQAR_Status_Failure,
    Multiplexer_4_To_1_TMUX1204DQAR_Status_Connection_Error,
    Multiplexer_4_To_1_TMUX1204DQAR_Status_Not_Implemented,
} Multiplexer_4_To_1_TMUX1204DQAR_Status_t;

/*
Sets the channel of the multiplexer.

Note that this function will automatically enable and disable to multiplexer 
when needed.

Returns:
- `Multiplexer_4_To_1_TMUX1204DQAR_Status_Success` if channel is set correctly.
- `Multiplexer_4_To_1_TMUX1204DQAR_Status_Connection_Error` if 
`multiplexer_channel = Multiplexer_4_To_1_TMUX1204DQAR_Channel_Off` & 
`en_port = nullptr`.
- `Multiplexer_4_To_1_TMUX1204DQAR_Status_Failure` if gpio pins or gpio ports
in `multiplexer_object` are not setup correctly. 
- `Multiplexer_4_To_1_TMUX1204DQAR_Status_Not_Implemented` if channel is 
invalid.
*/
Multiplexer_4_To_1_TMUX1204DQAR_Status_t multiplexer_4_to_1_tmux1204dqar_set_channel(Multiplexer_4_To_1_TMUX1204DQAR_Object_t *multiplexer_object, Multiplexer_4_To_1_TMUX1204DQAR_Channel_t multiplexer_channel);
