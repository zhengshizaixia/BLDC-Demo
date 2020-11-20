#include "FOCFunction.h"

#include "FOC.h"


FOC_EXPORT(gFOC,0.01);

/*************************************************************
** Function name:       FOC_Init
** Descriptions:        FOC初始化
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void FOC_Init(void)
{
    SetCurrentPIDParams(&gFOC,0.05,0.1,0,0.5);
    SetCurrentPIDTar(&gFOC,0,1);
}



/*************************************************************
** Function name:       FOC_Loop
** Descriptions:        FOC循环函数
** Input parameters:    None
** Output parameters:   None
** Returned value:      None
** Remarks:             None
*************************************************************/
void FOC_Loop(void)
{
    FOCCycle(&gFOC);
}





