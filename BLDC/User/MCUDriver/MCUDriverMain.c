/********************** Copyright(c)***************************
** Shenzhen Yuejiang Technology Co., Ltd.
**
** http:// www.dobot.cc
**
**------File Info----------------------------------------------
** File name:               MCUDriverMain.c
** Latest modified date:    2020-09-13
** Latest version:          V1.0.0
** Description:             MCUDriver执行文件
**
**------------------------------------------------------------
** Created by:              liuxiang
** Created date:            2020-09-13
** Version:                 V1.0.0
** Descriptions:            MCUDriver执行文件
**
**------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Description:
**
*************************************************************/

#include "MCUDriverMain.h"


#include "MotorGPIO.h"
#include "MotorHALSensor.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"
/*************************************************************
** Function name:       MCUDriver_Init
** Descriptions:        MCU引脚配置代码初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void MCUDriver_Init(void)
{
    printf("CD %s\r\n",__FUNCTION__);
    TIM1_Init();

}
/*************************************************************
** Function name:       MCUDriver_Loop
** Descriptions:        MCU引脚配置代码循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void MCUDriver_Loop(void)
{

}
