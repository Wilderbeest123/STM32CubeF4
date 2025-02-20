/**
  @page FreeRTOS_SignalFromISR FreeRTOS Signal from ISR application
 
  @verbatim
  ******************************************************************************
  * @file    FreeRTOS/FreeRTOS_SignalFromISR/readme.txt
  * @author  MCD Application Team
  * @brief   Description of the FreeRTOS Signal from ISR application.
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics. All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                               www.st.com/SLA0044
  *
  ******************************************************************************
  @endverbatim

@par Application Description

How to perform thread signaling from an interrupt using CMSIS RTOS API.

This application creates a threads that calls osSignalWait to wait for a signal to set bit1 and bit2 then toggles LED2.

SysTick_Handler calls the function "Toggle_Leds" 
Toggle_Leds calls osSignalSet to send a signal = bit1 to Thread2 if a static counter is equal to 400.
and calls osSignalSet to send a signal = bit1 | bit2 to Thread2 if a static counter is equal to 1000
  
As a result, the behaviour is as follows:
LED2 toggles every 1000 ms.


@note Care must be taken when using HAL_Delay(), this function provides accurate
      delay (in milliseconds) based on variable incremented in HAL time base ISR.
      This implies that if HAL_Delay() is called from a peripheral ISR process, then
      the HAL time base interrupt must have higher priority (numerically lower) than
      the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the HAL time base interrupt priority you have to use HAL_NVIC_SetPriority()
      function.
 
@note The application needs to ensure that the HAL time base is always set to 1 millisecond
      to have correct HAL operation.

@note The FreeRTOS heap size configTOTAL_HEAP_SIZE defined in FreeRTOSConfig.h is set accordingly to the 
      OS resources memory requirements of the application with +10% margin and rounded to the upper Kbyte boundary.

For more details about FreeRTOS implementation on STM32Cube, please refer to UM1722 "Developing Applications 
on STM32Cube with RTOS".

@par keywords

RTOS, FreeRTOS, Thread, Signal, ISR, Interrupt

@par Directory contents
    - FreeRTOS/FreeRTOS_SignalFromISR/Src/main.c                Main program
    - FreeRTOS/FreeRTOS_SignalFromISR/Src/stm32f4xx_hal_timebase_tim.c HAL timebase file
    - FreeRTOS/FreeRTOS_SignalFromISR/Src/stm32f4xx_it.c        Interrupt handlers
    - FreeRTOS/FreeRTOS_SignalFromISR/Src/system_stm32f4xx.c    STM32F4xx system clock configuration file
    - FreeRTOS/FreeRTOS_SignalFromISR/Inc/main.h                Main program header file
    - FreeRTOS/FreeRTOS_SignalFromISR/Inc/stm32f4xx_hal_conf.h  HAL Library Configuration file
    - FreeRTOS/FreeRTOS_SignalFromISR/Inc/stm32f4xx_it.h        Interrupt handlers header file
    - FreeRTOS/FreeRTOS_SignalFromISR/Inc/FreeRTOSConfig.h      FreeRTOS Configuration file

@par Hardware and Software environment

  - This application runs on STM32F413xx/STM32F423xx devices.
    
  - This application has been tested with STM32F413ZH-Nucleo board and can be
    easily tailored to any other supported device and development board.
    

@par How to use it ?

In order to make the program work, you must do the following:
 - Open your preferred toolchain 
 - Rebuild all files and load your image into target memory
 - Run the application
  
 * <h3><center>&copy; COPYRIGHT STMicroelectronics</center></h3>
 */
