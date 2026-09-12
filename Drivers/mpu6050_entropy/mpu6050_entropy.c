
#include "mpu6050_entropy.h"

/* MPU-6050 I2C address */
#define MPU6050_I2C_ADDR        (0x68 << 1)

/* MPU-6050 registers */
#define MPU6050_REG_CONFIG      0x1A
#define MPU6050_REG_ACCEL_CONFIG 0x1C
#define MPU6050_REG_ACCEL_XOUT_H 0x3B
#define MPU6050_REG_PWR_MGMT_1  0x6B


void MPU6050_Entropy_Init(I2C_HandleTypeDef *hi2c)
{
    uint8_t data;

    /* Wake up MPU-6050 */
    data = 0x00;

    HAL_I2C_Mem_Write(hi2c,
                      MPU6050_I2C_ADDR,
                      MPU6050_REG_PWR_MGMT_1,
                      I2C_MEMADD_SIZE_8BIT,
                      &data,
                      1,
                      HAL_MAX_DELAY);

    /*
     * Disable DLPF.
     * This gives the accelerometer the widest bandwidth
     * available for this configuration.
     */
    data = 0x00;

    HAL_I2C_Mem_Write(hi2c,
                      MPU6050_I2C_ADDR,
                      MPU6050_REG_CONFIG,
                      I2C_MEMADD_SIZE_8BIT,
                      &data,
                      1,
                      HAL_MAX_DELAY);

    /*
     * Accelerometer ±2g range.
     */
    data = 0x00;

    HAL_I2C_Mem_Write(hi2c,
                      MPU6050_I2C_ADDR,
                      MPU6050_REG_ACCEL_CONFIG,
                      I2C_MEMADD_SIZE_8BIT,
                      &data,
                      1,
                      HAL_MAX_DELAY);
}


void MPU6050_Entropy_Read(I2C_HandleTypeDef *hi2c,
                          uint8_t *memory)
{
    uint8_t accel[6];

    uint16_t bit_count = 0;


    /* Clear the destination buffer */
    for (uint8_t i = 0; i < 64; i++)
    {
        memory[i] = 0;
    }


    /*
     * Each MPU-6050 accelerometer reading provides:
     *
     * X LSB
     * Y LSB
     * Z LSB
     *
     * = 3 bits per sample.
     *
     * 512 / 3 = 170.67
     *
     * Therefore 171 samples are required,
     * with the final sample contributing only
     * the bits required to reach 512.
     */
    while (bit_count < 512)
    {
        /*
         * Read:
         *
         * 0x3B X high
         * 0x3C X low
         * 0x3D Y high
         * 0x3E Y low
         * 0x3F Z high
         * 0x40 Z low
         */
        HAL_I2C_Mem_Read(hi2c,
                         MPU6050_I2C_ADDR,
                         MPU6050_REG_ACCEL_XOUT_H,
                         I2C_MEMADD_SIZE_8BIT,
                         accel,
                         6,
                         HAL_MAX_DELAY);


        /*
         * Extract the least significant bit
         * of each accelerometer axis.
         */
        uint8_t x_bit = accel[1] & 0x01;
        uint8_t y_bit = accel[3] & 0x01;
        uint8_t z_bit = accel[5] & 0x01;


        uint8_t bits[3] =
        {
            x_bit,
            y_bit,
            z_bit
        };


        /*
         * Put the three bits into the destination
         * buffer sequentially.
         */
        for (uint8_t i = 0; i < 3; i++)
        {
            if (bit_count >= 512)
                break;

            uint16_t byte_index = bit_count / 8;
            uint8_t bit_index = 7 - (bit_count % 8);

            memory[byte_index] |=
                (bits[i] << bit_index);

            bit_count++;
        }


        /*
         * Wait approximately 1 ms before taking
         * another physical sensor sample.
         */
        HAL_Delay(1);
    }
}

