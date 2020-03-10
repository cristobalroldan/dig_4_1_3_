#include "main.h"
#include "adc.h"
#include "gpio.h"
//#include "my_it_callbacks.h"

//extern ADC_HandleTypeDef hadc1;

volatile unsigned int data = 0;
volatile unsigned int  data_promedio = 0;
volatile unsigned int data_aux = 0;
volatile unsigned int *ptr = &data_promedio;
int c = 0;



void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc){

	if(hadc->Instance == ADC1){
	  HAL_ADC_Start(hadc);
	  HAL_ADC_PollForConversion(hadc,15);
	  data = HAL_ADC_GetValue(hadc);
	  data_aux = data + data_aux;
	  c++;

	}

	if (c==5){
		  *ptr = (data_aux/5) ;
	  	  data_aux = 0;
	  	  c=0;

		}
}

