/**
  @page SAI_AudioPlay  Description of the SAI audio play example
  
  @verbatim
  ******************** (C) COPYRIGHT 2017 STMicroelectronics *******************
  * @file    SAI/SAI_AudioRecord/readme.txt 
  * @author  MCD Application Team
  * @brief   Description of the SAI audio play example.
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

Use of the SAI HAL API to play an audio file in DMA circular mode and handle the buffer update.

      Plug a headphone to ear the sound  /!\ Take care of yours ears.
      Default volume is 20%.
      The audio file is played in loop
      @Note: Copy file 'audio.bin' (available in AudioFile) directly in the flash 
      at @0x08010000 using ST-Link utility

@note Note the DMA runs in circular buffer mode and never stops. If you break with 
      the debugger, the DMA hw will keep running and a noise will be heard.

@note This example does not use BSP_AUDIO so the MspInit is coded in the main.c.

@par Keywords

Audio, SAI, DMA, Buffer update, play, headphone, audio protocol

@par Directory contents  

  - SAI/SAI_AudioPlay/Src/main.c                  Main program
  - SAI/SAI_AudioPlay/Src/system_stm32f4xx.c      STM32F4xx system source file
  - SAI/SAI_AudioPlay/Src/stm32f4xx_it.c          Interrupt handlers
  - SAI/SAI_AudioPlay/Inc/main.h                  Main program header file
  - SAI/SAI_AudioPlay/Inc/stm32f4xx_hal_conf.h    HAL configuration file
  - SAI/SAI_AudioPlay/Inc/stm32f4xx_it.h          Interrupt handlers header file
  - SAI/SAI_AudioPlay/AudioFile/audio.bin         Audio wave extract.

@par Hardware and Software environment

  - This example runs on STM32F446xx devices.
    
  - This example has been tested with STMicroelectronics STM32446E-EVAL
    board and can be easily tailored to any other supported device
    and development board.      

  - STM32446E-EVAL Set-up :
    There are no special switches for this example 

@par How to use it ? 

In order to make the program work, you must do the following :
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the example 

 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
