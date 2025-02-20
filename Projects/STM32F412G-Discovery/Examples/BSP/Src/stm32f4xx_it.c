/**
  ******************************************************************************
  * @file    BSP/Src/stm32f4xx_it.c 
  * @author  MCD Application Team
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"


/** @addtogroup STM32F4xx_HAL_Examples
  * @{
  */

/** @addtogroup BSP
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern QSPI_HandleTypeDef               QSPIHandle;
/* I2S handler declared in "stm32412g_discovery_audio.c" file */
extern I2S_HandleTypeDef                haudio_i2s;
extern DFSDM_Filter_HandleTypeDef      hAudioInDfsdmFilter[];
extern SD_HandleTypeDef uSdHandle;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M4 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief   This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

/******************************************************************************/
/*                 STM32F4xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f4xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles External line 0 interrupt request.
  * @retval None
  */
void EXTI0_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(BUTTON_WAKEUP);
}

/**
  * @brief  This function handles External line 3 interrupt request.
  * @retval None
  */
void EXTI3_IRQHandler(void)
{
   HAL_GPIO_EXTI_IRQHandler(SD_DETECT_PIN | LCD_TE_PIN);
}

/**
  * @brief  This function handles External line 9_5 interrupt request.
  * @retval None
  */
void EXTI9_5_IRQHandler(void)
{
   HAL_GPIO_EXTI_IRQHandler(TS_INT_PIN);
}

/**
  * @brief  This function handles DMA1 Stream5 interrupt request.
  * @retval None
  */
void AUDIO_OUT_I2Sx_DMAx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(haudio_i2s.hdmatx);
}

/**
  * @brief  This function handles DMA1 Stream 0 interrupt request.
  * @retval None
  */
void AUDIO_IN_I2Sx_DMAx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(haudio_i2s.hdmarx);
}

/**
  * @brief  This function handles QUADSPI interrupt request.
  * @retval None
  */
void QuadSPI_IRQHandler(void)
{
  HAL_QSPI_IRQHandler(&QSPIHandle);
}

/**
  * @brief  This function handles DFSDM MIC1 DMA interrupt request.
  * @retval None
  */
void AUDIO_DFSDM_DMAx_MIC1_IRQHandler(void)
{
  if(SdmmcTest == 1)
  {
    HAL_DMA_IRQHandler(uSdHandle.hdmatx); 
  }
  else
  {
  HAL_DMA_IRQHandler(hAudioInDfsdmFilter[POS_VAL(INPUT_DEVICE_DIGITAL_MIC1)].hdmaReg);
  }
}

/**
  * @brief  This function handles DFSDM MIC2 DMA interrupt request.
  * @retval None
  */
void AUDIO_DFSDM_DMAx_MIC2_IRQHandler(void)
{
  HAL_DMA_IRQHandler(hAudioInDfsdmFilter[POS_VAL(INPUT_DEVICE_DIGITAL_MIC2)].hdmaReg);
}

/**
  * @brief  Handles SD card interrupt request.
  * @retval None
  */
void BSP_SD_IRQHandler(void)
{
  HAL_SD_IRQHandler(&uSdHandle);
}

/**
  * @brief  Handles SD DMA Rx transfer interrupt request.
  * @retval None
  */
void BSP_SD_DMA_Rx_IRQHandler(void)
{
  HAL_DMA_IRQHandler(uSdHandle.hdmarx);
}

/**
  * @brief  This function handles PPP interrupt request.
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
