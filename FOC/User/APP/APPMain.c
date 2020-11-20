/********************** Copyright(c)***************************
** Shenzhen Yuejiang Technology Co., Ltd.
**
** http:// www.dobot.cc
**
**------File Info----------------------------------------------
** File name:               APPMain.c
** Latest modified date:    2020-09-13
** Latest version:          V1.0.0
** Description:             APP执行文件
**
**------------------------------------------------------------
** Created by:              liuxiang
** Created date:            2020-09-13
** Version:                 V1.0.0
** Descriptions:            APP执行文件
**
**------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Description:
**
*************************************************************/

#include "APPMain.h"

#include "FarmeWorkMain.h"
#include "MCUDriverMain.h"
#include "PeripheralDriverMain.h"
#include "FunctionMain.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"
/*************************************************************
** Function name:       APP_Init
** Descriptions:        用户代码初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void APP_Init(void)
{
    printf("CD %s\r\n",__FUNCTION__);
    FarmeWork_Init();
    MCUDriver_Init();
    PeripheralDriver_Init();
    Function_Init();
}
/*************************************************************
** Function name:       APP_Loop
** Descriptions:        用户代码循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void APP_Loop(void)
{
    FarmeWork_Loop();
    MCUDriver_Loop();
    PeripheralDriver_Loop();
    Function_Loop();
}
