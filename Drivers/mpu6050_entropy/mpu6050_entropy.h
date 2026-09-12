
#ifndef MPU6050_ENTROPY_H
#define MPU6050_ENTROPY_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

/*
 * Initialize MPU-6050 for entropy sampling.
 */
void MPU6050_Entropy_Init(I2C_HandleTypeDef *hi2c);

/*
 * Fill a 64-byte buffer (512 bits) with samples
 * obtained from the LSBs of the X, Y and Z
 * accelerometer outputs.
 *
 * memory must point to at least 64 bytes of memory.
 */
void MPU6050_Entropy_Read(I2C_HandleTypeDef *hi2c,
                          uint8_t *memory);

#endif
