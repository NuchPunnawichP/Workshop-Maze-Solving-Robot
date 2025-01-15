/*
 * CPPmain.cpp
 *
 *  Created on: Jan 15, 2025
 *      Author: Pannawit
 */

#include "CPPmain.h"
#include "stdio.h"

extern ADC_HandleTypeDef hadc1;
uint32_t adc_value[3];
uint32_t front_adc, left_adc, right_adc;

uint8_t ml, mr;

void setup()
{

}

void loop()
{
	HAL_ADC_Start(&hadc1);
	if (HAL_ADC_PollForConversion(&hadc1, 1000) == HAL_OK)
	{
		front_adc = HAL_ADC_GetValue(&hadc1);
	}

	if (HAL_ADC_PollForConversion(&hadc1, 1000) == HAL_OK)
	{
		left_adc = HAL_ADC_GetValue(&hadc1);
	}

	if (HAL_ADC_PollForConversion(&hadc1, 1000) == HAL_OK)
	{
		right_adc = HAL_ADC_GetValue(&hadc1);
	}
	HAL_ADC_Stop(&hadc1);

	if(front_adc >= 2000)
	{
		ml = 1;
		mr = 1;
	}
	else if(left_adc <= 2000 && front_adc <= 2000)
	{
		ml = 1;
		mr = 0;
	}
	else if(right_adc <= 2000 && front_adc <= 2000)
	{
		ml = 0;
		mr = 1;
	}
	else
	{
		ml = 0;
		mr = 0;
	}

	// Drive Motor
	Drive_motor(ml, mr);
}

void Drive_motor(uint8_t ml, uint8_t mr)
{
	if(ml)
	{
		// Left Motor
		HAL_GPIO_WritePin(m2a_GPIO_Port, m2a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(m2b_GPIO_Port, m2b_Pin, GPIO_PIN_RESET);
	}

	if(mr)
	{
		// Right Motor
		HAL_GPIO_WritePin(m1a_GPIO_Port, m1a_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(m2a_GPIO_Port, m2a_Pin, GPIO_PIN_RESET);
	}
}
