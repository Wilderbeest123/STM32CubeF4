/**
  @page LCD_DSI_CmdMode_TearingEffect_ExtPin : LCD DSI examples in DSI command mode

  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the LCD DSI in command mode example.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
   @endverbatim

@par Example Description

This example provides a description of how to use the embedded LCD DSI controller 
(using IPs LTDC and DSI Host) to drive the KoD LCD mounted on board.

The goal of this example is to display a QVGA landscape (320x240) images on LCD glass
in Command mode using Tearing Effect through GPIO (DSI EXTERNAL LINK) and partial 
refresh method. One buffer is used for display and for draw.

Layer0 is initialized to display a brief description of the example. It will be
used for images display also.

In this example, the display area is splitted in tow part right and left. When the
end of refresh event occured, left part of display area is refreshed/displayed while
the other right part is prepared to be displayed when Line Event occurs.
Pin JP2 is configured to command TE DSI. When the programmed edge is detected,
an interrupt is generated.

Partial Refresh with splitting method is based on the following steps:
- Set area of refresh by fixing Page and Column values.
- Select active area (LEFT_AREA)
- Set Scan Line at line 533, this to allow to write data to LEFT_AREA before a new
  refresh comes.
- Copy image to LCD frame buffer address
- Refresh LEFT_AREA
- refresh RIGHT_AREA

Each image is displayed for two secondes.

@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in SysTick ISR. This
      implies that if HAL_Delay() is called from a peripheral ISR process, then
      the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

@note The application need to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

@par Keywords

Graphic, Display, LCD, DSI, MIPI Alliance, Command mode, Tearing effect, Partial refresh, Single buffer,
LTDC, QVGA, ARGB8888, GPIO, External pin

@par Directory contents

  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Inc/stm32f4xx_hal_conf.h          HAL configuration file
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Inc/stm32f4xx_it.h                Interrupt handlers header file
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Inc/main.h                        Header for main.c module
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Inc/life_augmented_argb8888.h     Image 320x240 in ARGB8888 to display on LCD
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Inc/image_320x240_argb8888.h      Image 320x240 in ARGB8888 to display on LCD  
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Src/stm32f4xx_it.c                Interrupt handlers
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Src/main.c                        Main program
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Src/stm32f4xx_hal_msp.c           HAL MSP file
  - LCD_DSI/LCD_DSI_CmdMode_TearingEffect_ExtPin/Src/system_stm32f4xx.c            STM32F4xx system source file

@par Hardware and Software environment

  - This example runs on STM32F469xx devices.

  - This example has been tested with STMicroelectronics STM32469I-DISCOVERY
    board and can be easily tailored to any other supported device
    and development board.

  - This example is configured to run by default on STM32469I-DISCO RevC board.
  - In order to run this example on RevA or RevB boards, replace the flag 
    USE_STM32469I_DISCO_REVC, which is defined in the pre-processor options, by 
    either USE_STM32469I_DISCO_REVA or USE_STM32469I_DISCO_REVB respectively.

@par How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the example


 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
