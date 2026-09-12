/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Machine That Exists Only to Count
  *
  * 1. Collect entropy from ADC
  * 2. Generate a 10x10 random matrix
  * 3. Run Conway's Game of Life for 100 generations
  * 4. Convert the final matrix to a value
  * 5. Repeat for 10 matrices
  * 6. BogoSort the resulting values
  * 7. Increment the machine counter
  ******************************************************************************
  */
/* USER CODE END Header */

#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "adc_entropy.h"
#include "mpu6050_entropy.h"


/* -------------------------------------------------------------------------- */
/*                              Configuration                                 */
/* -------------------------------------------------------------------------- */

#define MATRIX_SIZE             10
#define MATRIX_BITS             100
#define MATRIX_ENTROPY_BYTES    13

#define NUMBER_OF_MATRICES      10
#define GAME_OF_LIFE_STEPS      100

#define RANDOM_MEMORY_SIZE      64


/* -------------------------------------------------------------------------- */
/*                              HAL Handles                                   */
/* -------------------------------------------------------------------------- */

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;


/* -------------------------------------------------------------------------- */
/*                              Global Data                                   */
/* -------------------------------------------------------------------------- */

uint8_t random_memory[RANDOM_MEMORY_SIZE];


/* 10 x 10 matrix */
uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE];


/* Values generated from the 10 matrices */
uint8_t values[NUMBER_OF_MATRICES];


/* Machine counter */
uint32_t machine_count = 0;


/* -------------------------------------------------------------------------- */
/*                          Function Prototypes                               */
/* -------------------------------------------------------------------------- */

void SystemClock_Config(void);

static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART2_UART_Init(void);

void Error_Handler(void);


/* Matrix functions */
void GenerateMatrixFromEntropy(
    uint8_t *entropy,
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE]
);

void PrintMatrix(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE]
);

uint8_t CountNeighbors(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE],
    int row,
    int col
);

void GameOfLifeStep(
    uint8_t current[MATRIX_SIZE][MATRIX_SIZE],
    uint8_t next[MATRIX_SIZE][MATRIX_SIZE]
);

void RunGameOfLife(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE],
    uint16_t generations
);

uint8_t MatrixToValue(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE]
);


/* Sorting functions */
uint8_t IsSorted(
    uint8_t *array,
    uint8_t length
);

void ShuffleArray(
    uint8_t *array,
    uint8_t length
);

void BogoSort(
    uint8_t *array,
    uint8_t length
);


/* -------------------------------------------------------------------------- */
/*                                  Main                                      */
/* -------------------------------------------------------------------------- */

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_ADC1_Init();
    MX_USART2_UART_Init();


    /* ---------------------------------------------------------------------- */
    /*                       Initialize ADC entropy                            */
    /* ---------------------------------------------------------------------- */

    /*
     * IMPORTANT:
     *
     * ADC_Entropy_Init() is implemented in:
     *
     *     Drivers/adc_entropy/adc_entropy.c
     *
     * It must NOT be implemented again in main.c.
     */

    ADC_Entropy_Init(&hadc1);


    printf("\r\n");
    printf("========================================\r\n");
    printf(" MACHINE THAT EXISTS ONLY TO COUNT\r\n");
    printf("========================================\r\n");

    printf("System initialized.\r\n");
    printf("ADC entropy initialized.\r\n");
    printf("\r\n");


    /* ---------------------------------------------------------------------- */
    /*                            Main machine loop                            */
    /* ---------------------------------------------------------------------- */

    while (1)
    {
        printf("\r\n");
        printf("----------------------------------------\r\n");
        printf("Starting machine cycle...\r\n");
        printf("----------------------------------------\r\n");


        /* ------------------------------------------------------------------ */
        /* Generate 10 matrices                                               */
        /* ------------------------------------------------------------------ */

        for (uint8_t m = 0; m < NUMBER_OF_MATRICES; m++)
        {
            printf("\r\n");
            printf("Matrix %d / %d\r\n",
                   m + 1,
                   NUMBER_OF_MATRICES);


            /* -------------------------------------------------------------- */
            /* Collect entropy                                                */
            /* -------------------------------------------------------------- */

            uint8_t matrix_entropy[MATRIX_ENTROPY_BYTES];

            memset(matrix_entropy,
                   0,
                   sizeof(matrix_entropy));


            /*
             * 100 bits are required for a 10x10 matrix.
             *
             * 13 bytes = 104 bits.
             *
             * Only the first 100 bits are used.
             */

            ADC_Entropy_Read(
                &hadc1,
                matrix_entropy,
                MATRIX_ENTROPY_BYTES
            );


            printf("Entropy collected.\r\n");


            /* -------------------------------------------------------------- */
            /* Generate matrix                                                */
            /* -------------------------------------------------------------- */

            GenerateMatrixFromEntropy(
                matrix_entropy,
                matrix
            );


            printf("Initial matrix:\r\n");

            PrintMatrix(matrix);


            /* -------------------------------------------------------------- */
            /* Run Conway's Game of Life                                      */
            /* -------------------------------------------------------------- */

            printf("Running Game of Life...\r\n");

            RunGameOfLife(
                matrix,
                GAME_OF_LIFE_STEPS
            );


            printf("Final matrix:\r\n");

            PrintMatrix(matrix);


            /* -------------------------------------------------------------- */
            /* Convert matrix into value                                      */
            /* -------------------------------------------------------------- */

            values[m] = MatrixToValue(matrix);


            printf("Matrix value = %d\r\n",
                   values[m]);
        }


        /* ------------------------------------------------------------------ */
        /* Print generated values                                             */
        /* ------------------------------------------------------------------ */

        printf("\r\n");
        printf("Generated values:\r\n");

        for (uint8_t i = 0; i < NUMBER_OF_MATRICES; i++)
        {
            printf("%d ", values[i]);
        }

        printf("\r\n");


        /* ------------------------------------------------------------------ */
        /* BogoSort                                                           */
        /* ------------------------------------------------------------------ */

        printf("\r\n");
        printf("Starting BogoSort...\r\n");

        BogoSort(
            values,
            NUMBER_OF_MATRICES
        );


        /* ------------------------------------------------------------------ */
        /* Print sorted values                                                */
        /* ------------------------------------------------------------------ */

        printf("Sorted values:\r\n");

        for (uint8_t i = 0; i < NUMBER_OF_MATRICES; i++)
        {
            printf("%d ", values[i]);
        }

        printf("\r\n");


        /* ------------------------------------------------------------------ */
        /* Increment machine counter                                          */
        /* ------------------------------------------------------------------ */

        machine_count++;

        printf("\r\n");
        printf("========================================\r\n");
        printf(" MACHINE COUNT = %lu\r\n",
               (unsigned long)machine_count);
        printf("========================================\r\n");


        /*
         * Delay before starting another cycle.
         *
         * Later this can be replaced with the physical
         * power-latch / push-button system.
         */

        HAL_Delay(1000);
    }
}


/* ========================================================================== */
/*                         MATRIX GENERATION                                  */
/* ========================================================================== */

void GenerateMatrixFromEntropy(
    uint8_t *entropy,
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE]
)
{
    uint16_t bit_index = 0;


    for (uint8_t row = 0; row < MATRIX_SIZE; row++)
    {
        for (uint8_t col = 0; col < MATRIX_SIZE; col++)
        {
            uint8_t byte_index = bit_index / 8;
            uint8_t bit_position = bit_index % 8;


            /*
             * Extract one bit from the entropy buffer.
             */

            matrix[row][col] =
                (entropy[byte_index] >> bit_position) & 0x01;


            bit_index++;
        }
    }
}


/* ========================================================================== */
/*                              PRINT MATRIX                                  */
/* ========================================================================== */

void PrintMatrix(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE]
)
{
    for (uint8_t row = 0; row < MATRIX_SIZE; row++)
    {
        for (uint8_t col = 0; col < MATRIX_SIZE; col++)
        {
            if (matrix[row][col])
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }

        printf("\r\n");
    }

    printf("\r\n");
}


/* ========================================================================== */
/*                           COUNT NEIGHBORS                                  */
/* ========================================================================== */

uint8_t CountNeighbors(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE],
    int row,
    int col
)
{
    uint8_t count = 0;


    /*
     * Check all eight surrounding cells.
     */

    for (int row_offset = -1;
         row_offset <= 1;
         row_offset++)
    {
        for (int col_offset = -1;
             col_offset <= 1;
             col_offset++)
        {
            /*
             * Do not count the cell itself.
             */

            if (row_offset == 0 &&
                col_offset == 0)
            {
                continue;
            }


            int neighbor_row =
                row + row_offset;

            int neighbor_col =
                col + col_offset;


            /*
             * Boundary check.
             *
             * This implementation does NOT wrap around.
             */

            if (neighbor_row < 0 ||
                neighbor_row >= MATRIX_SIZE ||
                neighbor_col < 0 ||
                neighbor_col >= MATRIX_SIZE)
            {
                continue;
            }


            if (matrix[neighbor_row][neighbor_col])
            {
                count++;
            }
        }
    }


    return count;
}


/* ========================================================================== */
/*                         GAME OF LIFE STEP                                  */
/* ========================================================================== */

void GameOfLifeStep(
    uint8_t current[MATRIX_SIZE][MATRIX_SIZE],
    uint8_t next[MATRIX_SIZE][MATRIX_SIZE]
)
{
    for (int row = 0;
         row < MATRIX_SIZE;
         row++)
    {
        for (int col = 0;
             col < MATRIX_SIZE;
             col++)
        {
            uint8_t neighbors =
                CountNeighbors(
                    current,
                    row,
                    col
                );


            /*
             * Conway's Game of Life rules:
             *
             * Alive:
             *   2 or 3 neighbors -> survives
             *   otherwise        -> dies
             *
             * Dead:
             *   exactly 3 neighbors -> becomes alive
             */

            if (current[row][col])
            {
                if (neighbors == 2 ||
                    neighbors == 3)
                {
                    next[row][col] = 1;
                }
                else
                {
                    next[row][col] = 0;
                }
            }
            else
            {
                if (neighbors == 3)
                {
                    next[row][col] = 1;
                }
                else
                {
                    next[row][col] = 0;
                }
            }
        }
    }
}


/* ========================================================================== */
/*                         RUN GAME OF LIFE                                   */
/* ========================================================================== */

void RunGameOfLife(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE],
    uint16_t generations
)
{
    uint8_t next[MATRIX_SIZE][MATRIX_SIZE];


    for (uint16_t generation = 0;
         generation < generations;
         generation++)
    {
        GameOfLifeStep(
            matrix,
            next
        );


        /*
         * Copy next generation back into matrix.
         */

        memcpy(
            matrix,
            next,
            sizeof(next)
        );


        /*
         * Print occasionally rather than every generation.
         *
         * This prevents the UART from becoming the main
         * bottleneck.
         */

        if ((generation + 1) % 10 == 0)
        {
            printf(
                "Generation %u / %u\r\n",
                generation + 1,
                generations
            );
        }
    }
}


/* ========================================================================== */
/*                         MATRIX TO VALUE                                    */
/* ========================================================================== */

uint8_t MatrixToValue(
    uint8_t matrix[MATRIX_SIZE][MATRIX_SIZE]
)
{
    uint8_t value = 0;


    /*
     * Current implementation:
     *
     * Count the number of living cells.
     *
     * Range = 0 to 100.
     *
     * This gives us a simple physical value to display.
     */

    for (uint8_t row = 0;
         row < MATRIX_SIZE;
         row++)
    {
        for (uint8_t col = 0;
             col < MATRIX_SIZE;
             col++)
        {
            if (matrix[row][col])
            {
                value++;
            }
        }
    }


    return value;
}


/* ========================================================================== */
/*                            CHECK SORTED                                    */
/* ========================================================================== */

uint8_t IsSorted(
    uint8_t *array,
    uint8_t length
)
{
    for (uint8_t i = 0;
         i < length - 1;
         i++)
    {
        if (array[i] > array[i + 1])
        {
            return 0;
        }
    }


    return 1;
}


/* ========================================================================== */
/*                              SHUFFLE                                       */
/* ========================================================================== */

void ShuffleArray(
    uint8_t *array,
    uint8_t length
)
{
    /*
     * Fisher-Yates shuffle.
     *
     * ADC readings are used as the random source.
     */

    for (int i = length - 1;
         i > 0;
         i--)
    {
        uint8_t random_byte;


        /*
         * Read one byte of entropy.
         */

        ADC_Entropy_Read(
            &hadc1,
            &random_byte,
            1
        );


        uint8_t j =
            random_byte % (i + 1);


        /*
         * Swap.
         */

        uint8_t temp =
            array[i];

        array[i] =
            array[j];

        array[j] =
            temp;
    }
}


/* ========================================================================== */
/*                              BOGOSORT                                      */
/* ========================================================================== */

void BogoSort(
    uint8_t *array,
    uint8_t length
)
{
    uint32_t attempts = 0;


    /*
     * BogoSort:
     *
     * while array is not sorted:
     *     randomly shuffle array
     *
     * This is intentionally absurd.
     */

    while (!IsSorted(array, length))
    {
        ShuffleArray(
            array,
            length
        );


        attempts++;


        /*
         * Print occasionally.
         */

        if (attempts % 1000 == 0)
        {
            printf(
                "BogoSort attempts: %lu\r\n",
                (unsigned long)attempts
            );
        }


        /*
         * IMPORTANT:
         *
         * There is intentionally no maximum attempt count.
         *
         * BogoSort is the ridiculous part of the project.
         *
         * Later, for the final machine, it would be safer to
         * add a maximum number of attempts or watchdog timeout.
         */
    }


    printf(
        "BogoSort finished after %lu attempts.\r\n",
        (unsigned long)attempts
    );
}


/* ========================================================================== */
/*                           SYSTEM CLOCK                                     */
/* ========================================================================== */

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};


    __HAL_RCC_PWR_CLK_ENABLE();

    __HAL_PWR_VOLTAGESCALING_CONFIG(
        PWR_REGULATOR_VOLTAGE_SCALE2
    );


    /*
     * HSI = 16 MHz
     *
     * PLL:
     *
     * PLLM = 16
     * PLLN = 336
     * PLLP = 4
     *
     * SYSCLK = 84 MHz
     */

    RCC_OscInitStruct.OscillatorType =
        RCC_OSCILLATORTYPE_HSI;

    RCC_OscInitStruct.HSIState =
        RCC_HSI_ON;

    RCC_OscInitStruct.HSICalibrationValue =
        RCC_HSICALIBRATION_DEFAULT;

    RCC_OscInitStruct.PLL.PLLState =
        RCC_PLL_ON;

    RCC_OscInitStruct.PLL.PLLSource =
        RCC_PLLSOURCE_HSI;

    RCC_OscInitStruct.PLL.PLLM =
        16;

    RCC_OscInitStruct.PLL.PLLN =
        336;

    RCC_OscInitStruct.PLL.PLLP =
        RCC_PLLP_DIV4;

    RCC_OscInitStruct.PLL.PLLQ =
        7;


    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }


    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK |
        RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 |
        RCC_CLOCKTYPE_PCLK2;


    RCC_ClkInitStruct.SYSCLKSource =
        RCC_SYSCLKSOURCE_PLLCLK;

    RCC_ClkInitStruct.AHBCLKDivider =
        RCC_SYSCLK_DIV1;

    RCC_ClkInitStruct.APB1CLKDivider =
        RCC_HCLK_DIV2;

    RCC_ClkInitStruct.APB2CLKDivider =
        RCC_HCLK_DIV1;


    if (HAL_RCC_ClockConfig(
            &RCC_ClkInitStruct,
            FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}


/* ========================================================================== */
/*                              ADC1 INIT                                     */
/* ========================================================================== */

static void MX_ADC1_Init(void)
{
    ADC_ChannelConfTypeDef sConfig = {0};


    hadc1.Instance =
        ADC1;

    hadc1.Init.ClockPrescaler =
        ADC_CLOCK_SYNC_PCLK_DIV4;

    hadc1.Init.Resolution =
        ADC_RESOLUTION_12B;

    hadc1.Init.ScanConvMode =
        DISABLE;

    hadc1.Init.ContinuousConvMode =
        DISABLE;

    hadc1.Init.DiscontinuousConvMode =
        DISABLE;

    hadc1.Init.ExternalTrigConvEdge =
        ADC_EXTERNALTRIGCONVEDGE_NONE;

    hadc1.Init.ExternalTrigConv =
        ADC_SOFTWARE_START;

    hadc1.Init.DataAlign =
        ADC_DATAALIGN_RIGHT;

    hadc1.Init.NbrOfConversion =
        1;

    hadc1.Init.DMAContinuousRequests =
        DISABLE;

    hadc1.Init.EOCSelection =
        ADC_EOC_SINGLE_CONV;


    if (HAL_ADC_Init(&hadc1) != HAL_OK)
    {
        Error_Handler();
    }


    /*
     * ADC1 Channel 0
     *
     * PA0
     *
     * This is the floating/noisy ADC input used by
     * the entropy driver.
     */

    sConfig.Channel =
        ADC_CHANNEL_0;

    sConfig.Rank =
        1;

    sConfig.SamplingTime =
        ADC_SAMPLETIME_3CYCLES;


    if (HAL_ADC_ConfigChannel(
            &hadc1,
            &sConfig) != HAL_OK)
    {
        Error_Handler();
    }
}


/* ========================================================================== */
/*                             UART2 INIT                                     */
/* ========================================================================== */

static void MX_USART2_UART_Init(void)
{
    huart2.Instance =
        USART2;

    huart2.Init.BaudRate =
        115200;

    huart2.Init.WordLength =
        UART_WORDLENGTH_8B;

    huart2.Init.StopBits =
        UART_STOPBITS_1;

    huart2.Init.Parity =
        UART_PARITY_NONE;

    huart2.Init.Mode =
        UART_MODE_TX_RX;

    huart2.Init.HwFlowCtl =
        UART_HWCONTROL_NONE;

    huart2.Init.OverSampling =
        UART_OVERSAMPLING_16;


    if (HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}


/* ========================================================================== */
/*                              GPIO INIT                                     */
/* ========================================================================== */

static void MX_GPIO_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
}


/* ========================================================================== */
/*                            PRINTF RETARGET                                 */
/* ========================================================================== */

int __io_putchar(int ch)
{
    HAL_UART_Transmit(
        &huart2,
        (uint8_t *)&ch,
        1,
        HAL_MAX_DELAY
    );

    return ch;
}


/* ========================================================================== */
/*                            ERROR HANDLER                                   */
/* ========================================================================== */

void Error_Handler(void)
{
    __disable_irq();


    while (1)
    {
        /*
         * Stay here if a fatal HAL error occurs.
         */
    }
}


#ifdef USE_FULL_ASSERT

void assert_failed(
    uint8_t *file,
    uint32_t line
)
{
    printf(
        "Wrong parameters value: file %s on line %lu\r\n",
        file,
        (unsigned long)line
    );
}

#endif
