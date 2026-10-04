/*
 * @Author: Lee nlee15428@gmail.com
 * @Date: 2026-10-03 21:10:06
 * @LastEditors: Lee nlee15428@gmail.com
 * @LastEditTime: 2026-10-04 13:28:12
 * @FilePath: \work1\Tasks\src\problem.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "problem.h"
#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "iwdg.h"

#define PROBLEM 3 // 按题号修改数字

volatile uint32_t tick = 0;

void Problem_Init(void)
{
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

#if PROBLEM >= 2
    HAL_TIM_Base_Start_IT(&htim3);
#endif
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM3)
    {
        tick++;
#if PROBLEM == 2
        HAL_IWDG_Refresh(&hiwdg);
#endif
    }
}