//
// Created by nethe on 12/29/2022.
//

#pragma once

#include_next "mcuconf.h"

#undef RP_I2C_USE_I2C0
#define RP_I2C_USE_I2C0 TRUE

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 FALSE
