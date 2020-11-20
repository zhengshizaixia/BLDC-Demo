#ifndef FOC_h
#define FOC_h

#include "stdint.h"


extern volatile uint32_t gFoc_TimeCNT;

/*
增量式PI调节
*/
struct PI_Struct
{
    /* data */
    float kp;
    float ki;
    float kd;

    float pre;
    float tar;
    float bias;
    float lastBias;
    float out;
    float outMax;
};


/*
FOC结构体
*/
struct SFOC_Struct
{
    /* data */
    uint32_t startTime;
    float cycle;

    float tariq;    //目标电流
    float tarid;


    float angle;    //角度
    float radian;   //弧度
    float ia;       //a 相实际电流
    float ib;       //b 相实际电流
    float ic;       //c 相实际电流
    float iAlpha;   //clarke变换后 * 2/3后 Iα
    float iBeta;    //clarke变换后 * 2/3后 Iβ
    float iq;       //park变换后 Iq
    float id;       //park变换后 Id

    float iAntiAlpha;   //park反变换后 后 Iα
    float iAntiBeta;    //park反变换后 后 Iβ
    float iAntia;   //park反变换后 * 3/2 后 Ia
    float iAntib;   //park反变换后 * 3/2 后 Ib
    float iAntic;   //park反变换后 * 3/2 后 Ic


    struct PI_Struct idPID;
    struct PI_Struct iqPID;
};
typedef struct SFOC_Struct FOC_Struct;
typedef FOC_Struct *PFOC_Struct;


#define FOC_EXPORT(x,xCycle)    \
FOC_Struct x = {                \
    .startTime = 0,             \
    .cycle = xCycle,            \
    .tarid = 0.0,               \
    .tariq = 0.0,               \
    .angle = 0.0,               \
    .radian = 0.0,              \
    .ia = 0.0,                  \
    .ib = 0.0,                  \
    .ic = 0.0,                  \
    .iAlpha = 0.0,              \
    .iBeta = 0.0,               \
    .iq = 0.0,                  \
    .id = 0.0,                  \
    .idPID = {0},               \
    .iqPID = {0},               \
};




/*************************************************************
** Function name:       WS2812_TIMEBASE
** Descriptions:        时基,放在周期为1ms的函数里面执行
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
*************************************************************/
#define FOC_TIMEBASE(ms)                \
        gFoc_TimeCNT+= ms

/*************************************************************
** Function name:       WS2812_GETTIME
** Descriptions:        获取起始时间
** Input parameters:    None
** Output parameters:   None
** Returned value:      (uint32_t)起始时间
*************************************************************/
#define FOC_GETTIME(void)                        \
    gFoc_TimeCNT

/*************************************************************
** Function name:       WS2812_TIMEOUT
** Descriptions:        检查超时
** Input parameters:    timeOut：(uint32_t)超时时间
**                      startTime:(uint32_t)开始的时间
** Output parameters:   None
** Returned value:      false,未超时，true，超时
*************************************************************/
#define FOC_TIMEOUT(timeOut,startTime)                \
    ((gFoc_TimeCNT - startTime) >= timeOut ? 1 : 0)






void SetCurrentPIDTar(PFOC_Struct pFOC,float tarid,float tariq);
void SetCurrentPIDParams(PFOC_Struct pFOC,float kp,float ki,float kd,float outMax);
void FOCCycle(PFOC_Struct pFOC);




#endif /* FOC_h */
