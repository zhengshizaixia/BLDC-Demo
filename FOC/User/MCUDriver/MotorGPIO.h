/********************** Copyright(c)***************************
** Shenzhen Yuejiang Technology Co., Ltd.
**
** http:// www.dobot.cc
**
**------File Info----------------------------------------------
** File name:               MotorGPIO.h
** Latest modified date:    2020-09-13
** Latest version:          V1.0.0
** Description:             MotorGPIO.h
**
**------------------------------------------------------------
** Created by:              liuxiang
** Created date:            2020-09-13
** Version:                 V1.0.0
** Descriptions:            MotorGPIO.h
**
**------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Description:
**
*************************************************************/

#ifndef MotorGPIO_h
#define MotorGPIO_h

#include "stdint.h"

void TIM1_Init(void);
void SetMotorRun(uint8_t halValue);
#endif /* MotorGPIO_h */
