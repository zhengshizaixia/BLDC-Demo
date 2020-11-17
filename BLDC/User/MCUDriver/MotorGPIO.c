/********************** Copyright(c)***************************
** Shenzhen Yuejiang Technology Co., Ltd.
**
** http:// www.dobot.cc
**
**------File Info----------------------------------------------
** File name:               MotorGPIO.c
** Latest modified date:    2020-09-13
** Latest version:          V1.0.0
** Description:             MotorGPIO.c
**
**------------------------------------------------------------
** Created by:              liuxiang
** Created date:            2020-09-13
** Version:                 V1.0.0
** Descriptions:            MotorGPIO.c
**
**------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Description:
**
*************************************************************/

#include "MotorGPIO.h"
#include "main.h"
extern TIM_HandleTypeDef htim1;

void TIM1_Init(void)
{
    //开启通道
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_3);

    //默认输出低电平
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, 0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, 0);
}
/*************************************************************
** Function name:       SetMotorLowBridge
** Descriptions:        设置电机下桥臂UVW
** Input parameters:    U:电平 V:电平 W:电平
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotorLowBridge(uint8_t u,uint8_t v,uint8_t w)
{
	HAL_GPIO_WritePin(Motor_U_GPIO_Port, Motor_U_Pin, (GPIO_PinState)u);
	HAL_GPIO_WritePin(Motor_V_GPIO_Port, Motor_V_Pin, (GPIO_PinState)v);
	HAL_GPIO_WritePin(Motor_W_GPIO_Port, Motor_W_Pin, (GPIO_PinState)w);
}
/*************************************************************
** Function name:       SetMotorLowBridge
** Descriptions:        设置电机下桥臂UVW
** Input parameters:    U:电平 V:电平 W:电平
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotorHighBridge(uint16_t u,uint16_t v,uint16_t w)
{
	if (u > 5000) {
		u = 5000;
	}
	if (v > 5000) {
		v = 5000;
	}
	if (w > 5000) {
		w = 5000;
	}
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, u);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, v);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, w);

}
/*************************************************************
** Function name:       SetMotorRun
** Descriptions:        设置电机换向
** Input parameters:    halValue：电机霍尔值
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetMotorRun(uint8_t halValue)
{
    switch (halValue)
    {
		case 5: //BA
			SetMotorHighBridge(0,500,0);
			SetMotorLowBridge(1,0,0);
			break;
		case 1:  //CA
			SetMotorHighBridge(0,0,500);
			SetMotorLowBridge(1,0,0);
			break;
		case 3: //CB
			SetMotorHighBridge(0,0,500);
			SetMotorLowBridge(0,1,0);
			break;
		case 2: //AB
			SetMotorHighBridge(500,0,0);
			SetMotorLowBridge(0,1,0);
			break;
		case 6: //AC
			SetMotorHighBridge(500,0,0);
			SetMotorLowBridge(0,0,1);
			break;
		case 4: //BC
			SetMotorHighBridge(0,500,0);
			SetMotorLowBridge(0,0,1);
			break; 
		default:
			SetMotorHighBridge(0,0,0);
			SetMotorLowBridge(0,0,0);
			break;
    }
}


