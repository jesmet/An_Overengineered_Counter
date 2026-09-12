#include "adc_entropy.h"

void ADC_Entropy_Init(ADC_HandleTypeDef *hadc)
{
    /* 
     * If using an MCU family with hardware ADC calibration (e.g. STM32L4, G4, F3),
     * you can run HAL_ADCEx_Calibration_Start(hadc, ADC_SINGLE_ENDED) here.
     * STM32F4 factory calibration is handled automatically by hardware.
     */
    (void)hadc;
}

void ADC_Entropy_Read(ADC_HandleTypeDef *hadc, uint8_t *memory, uint16_t len)
{
    uint32_t total_bits = (uint32_t)len * 8;
    uint32_t bit_count = 0;

    /* Clear the destination buffer */
    for (uint16_t i = 0; i < len; i++)
    {
        memory[i] = 0;
    }

    while (bit_count < total_bits)
    {
        HAL_ADC_Start(hadc);

        if (HAL_ADC_PollForConversion(hadc, 5) == HAL_OK)
        {
            uint32_t raw_adc = HAL_ADC_GetValue(hadc);
            
            /* Extract the noise-dominated LSB */
            uint8_t noise_bit = (uint8_t)(raw_adc & 0x01);

            /* Pack bit into buffer */
            uint16_t byte_index = bit_count / 8;
            uint8_t bit_index = 7 - (bit_count % 8);

            memory[byte_index] |= (noise_bit << bit_index);
            bit_count++;
        }

        HAL_ADC_Stop(hadc);
    }
}