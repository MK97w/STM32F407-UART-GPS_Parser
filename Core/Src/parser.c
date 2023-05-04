/*
 * parser.c
 *
 *  Created on: Jan 25, 2021
 *      Author: MK
 */



#include "parser.h"
#include "string.h"
#include "stdio.h"
#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef huart1;

uint8_t rx_data = 0;
uint8_t rx_buffer[buffermaxsize];
uint8_t rx_index =0;

GPS_t GPS;

void parser_init()
{
	HAL_UART_Receive_IT(&huart1, &rx_data, 1);

}

void parser_uart_callback()
{
	if(rx_data != 'n' && rx_index < sizeof(rx_buffer))
	{
		rx_buffer[rx_index++] = rx_data;

	}
	else
	{
		parser((char*) rx_buffer);
		rx_index = 0;
		memset(rx_buffer,0, sizeof(rx_buffer));

	}

	HAL_UART_Receive_IT(&huart1, &rx_data, 1);

}

void parser(char *strparse)
{
if(!strncmp(strparse, "$GPGGA",6))
{
	if(sscanf(strparse,"$GPGGA,%f,%f,%c,%f,%c,%d,%d,%f,%f,%c", &GPS.utc_time, &GPS.nmea_latitude, &GPS.ns, &GPS.nmea_longitude, &GPS.ew, &GPS.lock, &GPS.satelites, &GPS.hdop, &GPS.msl_altitude, &GPS.msl_units)>=1) // @suppress("Float formatting support")
	{
			return;
	}
}
}







