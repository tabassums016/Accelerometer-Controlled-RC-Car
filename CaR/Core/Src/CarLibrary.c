/*
 * mylibrary.c
 *
 *  Created on: Feb 7, 2020
 *      Author: ''''
 */
#include "CarHeader.h"

char buffer[50];
uint8_t timer_count = 0, buffer_index = 0;

uint8_t string_compare(char array1[], char array2[], uint16_t length)
{
	 uint8_t comVAR=0, i;
	 for(i=0;i<length;i++)
	   	{
	   		  if(array1[i]==array2[i])
	   	  		  comVAR++;
	   	  	  else comVAR=0;
	   	}
	 if (comVAR==length)
		 	return 1;
	 else 	return 0;
}

void Message_handler()
{
	if(string_compare(buffer, "1", strlen("1")))
	{
		HAL_GPIO_WritePin(MA1_GPIO_Port, MA1_Pin, RESET);
		HAL_GPIO_WritePin(MA2_GPIO_Port, MA2_Pin, SET);            // FOR LEFT TURN
		HAL_GPIO_WritePin(MB1_GPIO_Port, MB1_Pin, SET);
		HAL_GPIO_WritePin(MB2_GPIO_Port, MB2_Pin, RESET);

		//HAL_UART_Transmit(&huart2, (uint8_t*)"LED is ON.\n", strlen("LED is ON.\n"), 500);
	}else
	if(string_compare(buffer, "2", strlen("2")))
	{
		HAL_GPIO_WritePin(MA1_GPIO_Port, MA1_Pin, SET);
		HAL_GPIO_WritePin(MA2_GPIO_Port, MA2_Pin, RESET);            // FOR RIGHT TURN
		HAL_GPIO_WritePin(MB1_GPIO_Port, MB1_Pin, RESET);
		HAL_GPIO_WritePin(MB2_GPIO_Port, MB2_Pin, SET);
		//HAL_UART_Transmit(&huart2, (uint8_t*)"LED is OFF.\n", strlen("LED is OFF.\n"), 500);
	}else
		if(string_compare(buffer, "3", strlen("3")))
			{
				HAL_GPIO_WritePin(MA1_GPIO_Port, MA1_Pin, RESET);
				HAL_GPIO_WritePin(MA2_GPIO_Port, MA2_Pin, SET);            // FORWARD
				HAL_GPIO_WritePin(MB1_GPIO_Port, MB1_Pin, RESET);
				HAL_GPIO_WritePin(MB2_GPIO_Port, MB2_Pin, SET);
				//HAL_UART_Transmit(&huart2, (uint8_t*)"LED is OFF.\n", strlen("LED is OFF.\n"), 500);
			}else
			if(string_compare(buffer, "4", strlen("4")))
			{
				HAL_GPIO_WritePin(MA1_GPIO_Port, MA1_Pin, SET);
				HAL_GPIO_WritePin(MA2_GPIO_Port, MA2_Pin, RESET);            // REVERSE
				HAL_GPIO_WritePin(MB1_GPIO_Port, MB1_Pin, SET);
				HAL_GPIO_WritePin(MB2_GPIO_Port, MB2_Pin, RESET);
				//HAL_UART_Transmit(&huart2, (uint8_t*)"LED is OFF.\n", strlen("LED is OFF.\n"), 500);
			}else
				if(string_compare(buffer, "5", strlen("5")))
			{
				HAL_GPIO_WritePin(MA1_GPIO_Port, MA1_Pin, RESET);
				HAL_GPIO_WritePin(MA2_GPIO_Port, MA2_Pin, RESET);            // STOP
				HAL_GPIO_WritePin(MB1_GPIO_Port, MB1_Pin, RESET);
				HAL_GPIO_WritePin(MB2_GPIO_Port, MB2_Pin, RESET);
				//HAL_UART_Transmit(&huart2, (uint8_t*)"LED is OFF.\n", strlen("LED is OFF.\n"), 500);
			}else
	{
		strcat(buffer, "\n");
		HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 500);
	}

	memset(buffer, 0, sizeof(buffer));
	buffer_index = 0;
	timer_count = 0;
}
