#include "MotorHALSensor.h"
#include "main.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"


#include "MotorGPIO.h"
struct SMotorHALSensor_Struct
{
    uint8_t motorHALValue;
};
struct SMotorHALSensor_Struct gMotorHAL = {0};
/*************************************************************
** Function name:       MotorHALSensorHandle
** Descriptions:        电机霍尔中断执行函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void MotorHALSensorHandle(void)
{
    uint8_t halU = 0;
	uint8_t halV = 0;
	uint8_t halW = 0;
    halU = HAL_GPIO_ReadPin(HAL_U_GPIO_Port,HAL_U_Pin);
	halV = HAL_GPIO_ReadPin(HAL_V_GPIO_Port,HAL_V_Pin);
	halW = HAL_GPIO_ReadPin(HAL_W_GPIO_Port,HAL_W_Pin);

    gMotorHAL.motorHALValue = halU | (halV<<1) | (halW<<2);
	SetMotorRun(gMotorHAL.motorHALValue);
    //printf("HAL:%d\r\n",gMotorHAL.motorHALValue);
}
/*************************************************************
** Function name:       GetMotorHALSensorValue
** Descriptions:        获取电机霍尔值
** Input parameters:    None
** Output parameters:   None
** Returned value:      电机霍尔值
** Remarks:             None
*************************************************************/
uint8_t GetMotorHALSensorValue(void)
{
    return gMotorHAL.motorHALValue;
}


