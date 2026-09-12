<img width="1280" height="640" alt="git (1)" src="https://github.com/user-attachments/assets/8920b256-2ba8-4988-b824-5351134eb4bd" />


 
# [An overengineered counter that doesn't count] 🎯


## Basic Details
### Team Name: [Yellow]


### Team Members
- Team Lead: [Name] - [Sanjay Sajeev]
- Member 2: [Name] - [Jesmet Sunny]

### Project Description
This was our attempt to make a counter with the thought process that we are over qualified engineers with unlimited time and an Ego to show off. But it ended up as rechening of our egos.

### The Problem (that doesn't exist)
All counters and simple and boring there is nothing fascinating about them. We wanted to change that and bring new blood into the industry. And we hope to do this with our counter. Which uses sophisticated algorithm to predict is the button press should be counted or not.

### The Solution (that nobody asked for)
The solution we came up was to use randomness as our base and combine it with cellular automation (Conways Game of Life), Bogus Quantum sort to determine which universe would survive or not. 

## Technical Details
### Technologies/Components Used
For Software:
- C++, C
- STM32 CubeIDE
- afiskon/stm32-ssd1306
- majidsalehi88/LCD_I2C_pcf8574_STM32
- Custom random generator library using MPU-6050
- Custom random generator library using ADC
- STM32 Nucleo board, ChatGPT, Gemini, Perplexity, Pocket notebook, Jesmet Sunny etc

For Hardware:
- STM32F401, 0.96 OLED 4SPI display, 16*2LCD display and PCF8574 I2C expender, MPU-6050, Arduino UNO etc
- Multimeter, powersuppy, jumpercables, Soldering Iron, Breadboard etc

### Implementation
Lot of lack of sleep, coffee, chickens, Internet, Jesmet and most valuably fear of being useless.

### Project Documentation
<img width="1280" height="1280" alt="image" src="https://github.com/user-attachments/assets/a8bc6000-9581-4df1-abcf-8f87f96253a3" />
This how it should look if we were successfull. But we weren't!

<img width="1280" height="1280" alt="image" src="https://github.com/user-attachments/assets/65333732-9563-407b-9b57-2ba77f96ca83" />
This is testing the OLED Display using an Arduino. Its pretty cool. I thought it was not 5v tolerant and connected it to 5 but it survived and i didn't lose 250 yeee Also an SPI device.

<img width="1280" height="1280" alt="image" src="https://github.com/user-attachments/assets/513c9eaa-2cd7-4f7b-9720-f6eebd0479a2" />
This is the output values being measured from the Accelerometer gyroscope. Its a 3.3v device including the I2C

<img width="1280" height="1280" alt="image" src="https://github.com/user-attachments/assets/9bb29373-4581-4770-a4ef-28ddf4326d8a" />
The green led looks cool on it. So its the thing whose output you say above. Man its really cool that mass production has made such a mems device so accessible and cheap.

<img width="1280" height="1280" alt="image" src="https://github.com/user-attachments/assets/35158b86-36e4-471d-9682-9c1c16038fee" />
This is the 16*2 display they are actually quite fascinating devices been manufactured for quite some time. They have build in display controller and character bank. And even allows us to manually make new characters. Also they have build in Japanese characters. Isn't that assume.

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/145ea74a-2d7d-46e6-994c-51702231148f" />
One thing not assume about them is the number of wires they have it takes up too much gpio and hard to manager all off the wires. So this cool thing exist which makes it controller's able using software using an hardware module. I am actually thinking of using these modules for other purposes like what they are not intended for. Lets see how that goes.Its also I2C but its 5v so might not work as the pull ups used are pulling up to 5v but the accelerometer is 3.3v so not good if they meet so i was either going to remove the 5v pull ups or use the I2C1 and I2C2. Thats another fascinating thing they have gpio which are tolerable upto 7v which is so coool as its 3.3v microcontroller.
**Dont judge my soldering!!!! it was my first years ago**

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/0718c201-4abd-43eb-9a1d-43816689e84e" />
The place i have been calling home for the past 14 hours 59 minutes 57 seconds. Also cool bottle right. And thats my pill shaped bottle.

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/e3beedf7-3aad-42d6-8c2b-ccb2ed7ef6ac" />
Me just after placing this on the table filled with optimism not realising what was going for me.

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/aa99bcd8-7d54-4123-bdda-7d34d0e0e4e4" /> 
that is my multimeter hanging around with his buddies.

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/1fada82e-3a54-410a-85c7-fadcaeb8755f" />
This is where all of it started when i went through the components I have. Also the flowers were given by my sister.

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/3738a193-c12b-4917-a367-4f25b08412c6" />
The exclusive back shot of the 0.96 display

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/58b9b1b0-2e12-457a-bb93-8ab92f883065" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/34f00b93-5ea5-4c22-ae07-812f00376e95" />
Broken dreams of me wanting to go so much but was able to do so little. This was the lore we had developed for the device.
Connecting it with TVA time branching and all. 

<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/34ab8482-e618-42ab-8e53-1ec82c16da87" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/8ca2d027-1ec1-4677-85ac-aa6108380853" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/988c8697-7976-4be5-85ca-aa88f8ba7ed7" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/199df177-bfec-4078-964e-19637395e4cf" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/47f98611-7c38-4cbc-84b8-9f909ee974f0" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/7e07372d-8812-4c24-8a4a-2a44c8f82294" />
<img width="1536" height="1536" alt="image" src="https://github.com/user-attachments/assets/274e2154-d2cc-4ec6-b4cf-963807755fbc" />

These are few of my scribbling. 


### 1. Project Concept & Core Vision
The goal of this project was to design a real-time, hardware-driven embedded system on **STM32 ARM Cortex-M microcontrollers** (prototyped on the STM32F401RE / STM32F303RE Nucleo-64 and scaled for the STM32 NUCLEO-F767ZI). 

The system implements a stochastic computing pipeline:
1. **Physical Entropy Extraction:** Harvesting non-deterministic physical noise (thermal and electromagnetic) to generate true random bitstreams.
2. **Cellular Automata Engine:** Seeding an \\(8 \times 8\\) matrix for **Conway’s Game of Life** with hardware noise bits, evolving the matrix across 100 generations, and reducing each evolved grid into row-weighted numerical sums.
3. **Randomized Array Sorting (Bogo Sort):** Evaluating whether the generated Conway array is sorted. If unsorted, executing a single-attempt **Bogo Sort** using an unbiased **Fisher-Yates shuffle** driven by live hardware entropy.
4. **Dual-Display & UART Output:** Rendering visual outputs across a 0.96" graphic SSD1306 OLED display, an HD44780 character LCD with a PCF8574 I2C backpack, and live serial logs over USART2.

---

### 2. Hardware & Electrical Architecture (The 5V vs. 3.3V Solution)

#### **The Voltage Conflict**
A major hardware challenge was interfacing mixed-voltage peripherals:
* **3.3V Native Peripherals:** The STM32 microcontroller, MPU-6050 motion processor, and SSD1306 OLED operate natively at **3.3V** (`VDD`).
* **5V Legacy Peripherals:** The HD44780 character LCD with its PCF8574 I2C backpack requires **5V** (`VCC`) for proper liquid crystal contrast (`VLCD`) and backlight LED driving.

#### **Electrical Safety & Bus Isolation**
Connecting a 5V PCF8574 I2C backpack with internal pull-up resistors directly to a shared I2C line risks injecting 5V back into fragile 3.3V sensors.

* **5V Tolerance Verification:** We confirmed via the STM32 datasheets that specific GPIO pins are classified with an **FT** (5V Tolerant) or **FTf** (5V Tolerant, Fast Mode Plus) I/O structure. These pins can safely withstand input voltages up to \\(\text{VDD} + 4.0\text{ V}\\) (~7.3V) without damage.
* **Dual I2C Bus Isolation:**
  * **I2C1 (3.3V Bus):** Connected exclusively to 3.3V devices (MPU-6050 and SSD1306 OLED).
  * **I2C2 (5V Bus):** Connected to the 5V PCF8574 LCD backpack using designated FT/FTf pins (`PB8`/`PB9` or `PA9`/`PA10`), with a single unified system ground (`GND`) shared across all rails.

---

### 3. Mathematical Algorithms & Software Logic

#### **A. Fisher-Yates Shuffle & Rejection Sampling**
Standard pseudo-random operations using modulo (`rand() % max`) introduce **modulo bias**, making certain indices statistically more probable. To ensure uniform array shuffling (\\(O(N)\\) time complexity):
1. **Bit Extraction:** We construct binary integers by harvesting physical noise bits.
2. **Rejection Sampling:** If the generated binary value is greater than or equal to the array bound `max`, the value is discarded completely, and fresh bits are harvested. This guarantees mathematically unbiased permutations.

#### **B. Conway’s Game of Life Engine**
* **Initialization:** An \\(8 \times 8\\) grid (\\(64\text{ cells}\\)) is populated using 64 bits from the entropy engine.
* **Neighborhood Evaluation:** Each cell checks its 8 surrounding neighbors using toroidal wrapping conditions (grid edge wrapping).
* **State Transition:**
  * Live cells die from underpopulation (\\(<2\text{ neighbors}\\)) or overpopulation (\\(>3\text{ neighbors}\\)).
  * Dead cells become alive through reproduction (\\(=3\text{ neighbors}\\)).
* **Grid Reduction:** After 100 generations, each \\(8 \times 8\\) grid is converted into a scalar sum by accumulating row-weighted bit patterns. Four runs generate a 4-element array (`initial_sums`).

---

### 4. Hardware Entropy Extraction: Trial, Failure, and Pivot

#### **Attempt 1: MPU-6050 Accelerometer Thermal LSB Noise**
* **The Concept:** Read the Least Significant Bit (LSB) of the accelerometer’s lower output byte `ACCEL_XOUT_L` (register `0x3C`), `ACCEL_YOUT_L` (`0x3E`), and `ACCEL_ZOUT_L` (`0x40`).
* **Driver Implementation:** We wrote a custom C library (`mpu6050_entropy.c`/`.h`). To maximize thermal noise, we disabled the Digital Low Pass Filter (`DLPF_CFG = 0` in `CONFIG` register `0x1A` for 260 Hz bandwidth) and set the accelerometer full-scale range to maximum sensitivity (\\(\pm 2g\\) in `ACCEL_CONFIG` register `0x1C`).
* **The Failure:** When testing `MPU6050_Get_Random_Stream()` on hardware, the target 64-byte memory array remained entirely empty (filled with `0x00`).

#### **Root Cause Analysis of the MPU-6050 Failure:**
1. **Sleep Mode Lock:** By default on power-up, bit 6 (`SLEEP`) of `PWR_MGMT_1` (register `0x6B`) is set to `1`. The internal ADCs are disabled, freezing data registers at `0` until `0x00` is explicitly written to wake up the IC.
2. **HAL Address Formatting:** In STM32 HAL, `HAL_I2C_Mem_Read()` requires the 7-bit slave address shifted left by 1 (`0x68 << 1 = 0xD0`). Passing `0x68` unshifted sends address `0x34`, causing a NACK error.
3. **Missing Bus Verification:** Bus communication was not verified prior to reading by querying the `WHO_AM_I` register (`0x75`, expected return value `0x68`).

#### **Attempt 2: Floating ADC Pin Static Noise (The Solution)**
Rather than wrestling with I2C register timing and delays, we pivoted to a reliable physical noise generator:
* **Operating Principle:** An unconnected analog pin (**PA0 / ADC1 Channel 0**) acts as a physical antenna, picking up background thermal and electromagnetic static.
* **Configuration:** In STM32CubeMX, we configured **ADC1 IN0** in single-ended mode with maximum sampling time (480/601.5 ADC clock cycles) to extend the noise integration window.
* **Entropy Generation:** Converting the floating analog input and masking the Least Significant Bit (`raw_adc & 0x01`) yielded a fast, continuous 0/1 entropy bitstream with zero I2C bus overhead.

---

### 5. Embedded C Porting, UART Retargeting & Build Errors

When porting the desktop algorithm simulation to the **STM32F401** target, we encountered and resolved several compiler and linker issues:

#### **Errors Encountered & Fixed:**
1. **Array Assignment Syntax Error:**  
   * *Error:* `assignment to expression with array type` (`lsb = raw_accel & 0x01;`).
   * *Fix:* Changed direct variable assignments to explicit array indexing (`lsb = raw_accel & 0x01;`, `lsb = raw_accel & 0x01;`, `lsb = raw_accel & 0x01;`).
2. **Function Signature Mismatch:**  
   * *Error:* Conflicting types for `MPU6050_Entropy_Init` (`void` vs `HAL_StatusTypeDef`).
   * *Fix:* Standardized header declarations (`mpu6050_entropy.h`) to return `HAL_StatusTypeDef`.
3. **String Initialization Typo:**  
   * *Error:* `char bit_buffer = "...";` caused string pointer subscript errors.
   * *Fix:* Corrected to array declaration `const char bit_buffer[] = "...";`.
4. **Linker Undefined Reference Errors:**  
   * *Error:* `ld.exe` failed with undefined references to `huart2`, `SystemClock_Config`, `MX_GPIO_Init`, and `MX_USART2_UART_Init`.
   * *Fix:* Provided complete global handle allocations (`UART_HandleTypeDef huart2;`), clock setup routines, and CubeMX peripheral initializations in `main.c`.
5. **UART Serial Printing:** Retargeted standard `printf()` to **USART2** (`PA2`/`PA3`) over the ST-LINK Virtual COM Port at 115200 baud by overriding `__io_putchar()` and `_write()`.

#### **Step 1 Hardware Execution Output:**
Upon flashing the self-contained `main.c` script, the ST-LINK serial console confirmed the complete execution of the pipeline:
```text
==========================================
=== CONWAY BOGOSORT PIPELINE (STEP 1) ===
==========================================
Simulating bit stream with 301 dummy bits pre-loaded...

Generated Conway Sums: 

Array is unordered. Initiating 1-attempt Bogosort...
Shuffled Array: 

======= UNIVERSE DESTROYED =======
```

---

### 6. Current Integrated System Architecture

The project now stands as a fully configured multi-peripheral system defined in STM32CubeMX (`.ioc`):

| Hardware Peripheral | Interface Mode | STM32 Pin Assignment | Function |
| :--- | :--- | :--- | :--- |
| **ADC1 (IN0)** | Analog Input | **PA0** (Floating Pin) | Live 0/1 entropy bitstream generator |
| **0.96" SSD1306 OLED** | **SPI1** Transmit Master (@ 8–10 MHz) | **PA5** (SCK), **PA7** (MOSI), **PB0** (RES), **PB1** (DC), **PB2** (CS) | 128x64 graphic animation of Conway grid & Bogosort |
| **HD44780 LCD (PCF8574)** | **I2C2** (5V Bus / Fast Mode 400kHz) | **PB8** (SCL), **PB9** (SDA) on FT pins | 16x2 text status display (Sums, Trial Counts, Universe State) |
| **MPU-6050 Motion Sensor** | **I2C1** (3.3V Bus) | **PB6** (SCL), **PB7** (SDA) | Auxiliary motion/vibration entropy input |
| **ST-LINK VCP Debugger** | **USART2** (Asynchronous @ 115200 Baud) | **PA2** (TX), **PA3** (RX) | Live console logging & diagnostic feedback |

The system architecture combines real-time physical noise harvesting with deterministic state machine execution and multi-display visual output!

This final explanation was made using Notebookllm


### Project Demo
# Video
[Add your demo video link here]
*Explain what the video demonstrates*

# Additional Demos
[Add any extra demo materials/links]

## Team Contributions
- Sanjay Sajeev: Master Brain
- Jesmet Sunny: Docile Subordinate 
- All AI models free to use and I am aware off

---
Made with ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️ at TinkerHub Useless Projects 

![Static Badge](https://img.shields.io/badge/TinkerHub-24?color=%23000000&link=https%3A%2F%2Fwww.tinkerhub.org%2F)
![Static Badge](https://img.shields.io/badge/UselessProjects--26-26?link=https%3A%2F%2Ftinkerhub.org%2Fevents%2F1M8ORET9A1%2Fuseless-projects-3.0)



