#ifndef ADC_ENTROPY_H
#define ADC_ENTROPY_H

#include <stdint.h>
#include "stm32f4xx_hal.h"

/*
 * Calibrate or prepare the ADC if needed.
 */
void ADC_Entropy_Init(ADC_HandleTypeDef *hadc);

/*
 * Fill a memory buffer of size 'len' bytes with random bits
 * harvested from the LSB of floating ADC conversions.
 */
void ADC_Entropy_Read(ADC_HandleTypeDef *hadc, uint8_t *memory, uint16_t len);

#endif /* ADC_ENTROPY_H */