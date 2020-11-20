#include "FOC.h"
#include "math.h"


#include "stdio.h"
#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

#define PI 3.1415926

volatile uint32_t gFoc_TimeCNT;


/*************************************************************
** Function name:       ClarkeTransform
** Descriptions:        Clarke正变换
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void ClarkeTransform(PFOC_Struct pFOC)
{
    pFOC->iAlpha = pFOC->ia;
    pFOC->iBeta = (pFOC->ia + 2.0 * pFOC->ib) / sqrt(3);
}
/*************************************************************
** Function name:       ParkTransform
** Descriptions:        Park正变换
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void ParkTransform(PFOC_Struct pFOC)
{
    pFOC->id = pFOC->iAlpha * cos(pFOC->radian) + pFOC->iBeta * sin(pFOC->radian);
    pFOC->iq = -pFOC->iAlpha * sin(pFOC->radian) + pFOC->iBeta * cos(pFOC->radian);
}

/*************************************************************
** Function name:       ParkAntiTransform
** Descriptions:        Park反变换
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void ParkAntiTransform(PFOC_Struct pFOC)
{
    pFOC->iAntiAlpha = pFOC->id * cos(pFOC->radian) - pFOC->iq * sin(pFOC->radian);
    pFOC->iAntiBeta = pFOC->id * sin(pFOC->radian) + pFOC->iq * cos(pFOC->radian);
}
/*************************************************************
** Function name:       ClarkeAntiTransform
** Descriptions:        Clarke逆变换
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void ClarkeAntiTransform(PFOC_Struct pFOC)
{
    pFOC->iAntia = pFOC->iAntiAlpha;
    pFOC->iAntib = (-pFOC->iAntiAlpha + sqrt(3) * pFOC->iAntiBeta) / 2;
    pFOC->iAntic = (-pFOC->iAntiAlpha - sqrt(3) * pFOC->iAntiBeta) / 2;
}



/*************************************************************
** Function name:       CurrentPIControlID
** Descriptions:        D轴电流闭环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void CurrentPIControlID(PFOC_Struct pFOC)
{
    //获取实际值
    pFOC->idPID.pre = pFOC->id;
    //获取目标值
    pFOC->idPID.tar = pFOC->tarid;
    //计算偏差
    pFOC->idPID.bias = pFOC->idPID.tar - pFOC->idPID.pre;
    //计算PID输出值
    pFOC->idPID.out += pFOC->idPID.kp * (pFOC->idPID.bias - pFOC->idPID.lastBias) + pFOC->idPID.ki * pFOC->idPID.bias;
    //保存偏差
    pFOC->idPID.lastBias = pFOC->idPID.bias;

    if (pFOC->idPID.out > abs(pFOC->idPID.outMax)) {
        (pFOC->idPID.out = abs(pFOC->idPID.outMax)
    }

    if (pFOC->idPID.out < -abs(pFOC->idPID.outMax)) {
        (pFOC->idPID.out = -abs(pFOC->idPID.outMax)
    }
}
/*************************************************************
** Function name:       CurrentPIControlIQ
** Descriptions:        Q轴电流闭环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void CurrentPIControlIQ(PFOC_Struct pFOC)
{
    //获取实际值
    pFOC->iqPID.pre = pFOC->iq;
    //获取目标值
    pFOC->iqPID.tar = pFOC->tariq;
    //计算偏差
    pFOC->iqPID.bias = pFOC->iqPID.tar - pFOC->iqPID.pre;
    //计算PID输出值
    pFOC->iqPID.out += pFOC->iqPID.kp * (pFOC->iqPID.bias - pFOC->iqPID.lastBias) + pFOC->iqPID.ki * pFOC->iqPID.bias;
    //保存偏差
    pFOC->iqPID.lastBias = pFOC->iqPID.bias;

    if (pFOC->iqPID.out > abs(pFOC->iqPID.outMax)) {
        (pFOC->iqPID.out = abs(pFOC->iqPID.outMax)
    }

    if (pFOC->iqPID.out < -abs(pFOC->iqPID.outMax)) {
        (pFOC->iqPID.out = -abs(pFOC->iqPID.outMax)
    }
}

































/*************************************************************
** Function name:       SetCurrentPIDTar
** Descriptions:        设置D轴和Q轴的目标值
** Input parameters:    pFOC：FOC对象指针
**                      tarid：D轴目标电流
**                      tariq：Q轴目标电流
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetCurrentPIDTar(PFOC_Struct pFOC,float tarid,float tariq)
{
    pFOC->tarid = tarid;
    pFOC->tariq = tariq;
}
/*************************************************************
** Function name:       SetCurrentPIDParams
** Descriptions:        设置电流环参数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void SetCurrentPIDParams(PFOC_Struct pFOC,float kp,float ki,float kd,float outMax)
{
    pFOC->idPID.kp = kp;
    pFOC->idPID.ki = ki;
    pFOC->idPID.kd = kd;
    pFOC->idPID.outMax = outMax;

    pFOC->iqPID.kp = kp;
    pFOC->iqPID.ki = ki;
    pFOC->iqPID.kd = kd;
    pFOC->iqPID.outMax = outMax;
}





void FOC_Test(PFOC_Struct pFOC)
{
    pFOC->angle += 1.0;
    if (pFOC->angle >= 360.0) {
        pFOC->angle = 0.0;
    }
    pFOC->radian = pFOC->angle / 360.0 * 2 * PI;

    pFOC->clack.ia = sin(pFOC->radian);
    pFOC->clack.ib = sin(pFOC->radian -  PI * 2.0 / 3.0 );
    pFOC->clack.ic = sin(pFOC->radian + PI * 2.0 / 3.0);

    // printf("1:%f\r\n", pFOC->park.angle);
    // printf("2:%f\r\n", pFOC->clack.ia);
    // printf("3:%f\r\n", pFOC->clack.ib);
    // printf("4:%f\r\n", pFOC->clack.ic);
    // printf("5:%f\r\n",pFOC->iAlpha);
    // printf("6:%f\r\n",pFOC->iBeta);
    // printf("7:%f\r\n",pFOC->id);
    // printf("8:%f\r\n",pFOC->iq);


    //1.检测三相电流

    //2.Clarke变换
    ClarkeTransform(pFOC);
    //3.Park变换
    ParkTransform(pFOC);
    //4.电流闭环
    CurrentPIControlID(pFOC);
    CurrentPIControlIQ(pFOC);
    //5.Park反变换
    ParkAntiTransform(pFOC);
    //6.Clarke反变换
    ClarkeAntiTransform(pFOC);
    //7.SVPWM生成


    // printf("1:%f\r\n", pFOC->idPID.tar);
    // printf("2:%f\r\n", pFOC->idPID.pre);
    // printf("1:%f\r\n", pFOC->iqPID.tar);
    // printf("2:%f\r\n", pFOC->iqPID.pre);


}
/*************************************************************
** Function name:       FOCCycle
** Descriptions:        FOC主循环
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void FOCCycle(PFOC_Struct pFOC)
{
        if(FOC_TIMEOUT(pFOC->cycle*1000,pFOC->startTime)) {
            pFOC->startTime = FOC_GETTIME();

            FOC_Test(pFOC);

        }
}

