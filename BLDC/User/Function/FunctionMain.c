/********************** Copyright(c)***************************
** Shenzhen Yuejiang Technology Co., Ltd.
**
** http:// www.dobot.cc
**
**------File Info----------------------------------------------
** File name:               FunctionMain.c
** Latest modified date:    2020-09-13
** Latest version:          V1.0.0
** Description:             Function执行文件
**
**------------------------------------------------------------
** Created by:              liuxiang
** Created date:            2020-09-13
** Version:                 V1.0.0
** Descriptions:            Function执行文件
**
**------------------------------------------------------------
** Modified by:
** Modified date:
** Version:
** Description:
**
*************************************************************/

#include "FunctionMain.h"

#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"
/*************************************************************
** Function name:       Function_Init
** Descriptions:        功能代码初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Function_Init(void)
{
    printf("CD %s\r\n",__FUNCTION__);
}
/*************************************************************
** Function name:       Function_Loop
** Descriptions:        功能代码循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void Function_Loop(void)
{

}
