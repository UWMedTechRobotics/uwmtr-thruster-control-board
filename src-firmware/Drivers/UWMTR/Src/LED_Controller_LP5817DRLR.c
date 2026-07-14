#include "LED_Controller_LP5817DRLR.h"

#define CHIP_EN 0x00
#define DEV_CONFIG0 0x01
#define DEV_CONFIG1 0x02
#define DEV_CONFIG2 0x03
#define DEV_CONFIG3 0x04
#define SHUTDOWN_CMD 0x0D
#define RESET_CMD 0x0E
#define UPDATE_CMD 0x0F
#define FLAG_CLR 0x13
#define OUT0_DC 0x14
#define OUT1_DC 0x15
#define OUT2_DC 0x16
#define OUT0_MANUAL_PWM 0x18
#define OUT1_MANUAL_PWM 0x19
#define OUT2_MANUAL_PWM 0x1A
#define FLAG 0x40
