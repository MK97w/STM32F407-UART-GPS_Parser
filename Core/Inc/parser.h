/*
 * parser.h
 *
 *  Created on: Jan 25, 2021
 *      Author: MK
 */

#ifndef INC_PARSER_H_
#define INC_PARSER_H_

#define parser_debug   0
#define buffermaxsize  256
#define parser_uart    &huart1;

typedef struct{

    // calculated values
    float dec_longitude;
    float dec_latitude;
    float altitude_ft;

    // GGA - Global Positioning System Fixed Data
    float nmea_longitude;
    float nmea_latitude;
    float utc_time;
    char ns, ew;
    int lock;
    int satelites;
    float hdop;
    float msl_altitude;
    char msl_units;

    // RMC - Recommended Minimmum Specific GNS Data
    char rmc_status;
    float speed_k;
    float course_d;
    int date;

    // GLL
    char gll_status;

    // VTG - Course over ground, ground speed
    float course_t; // ground speed true
    char course_t_unit;
    float course_m; // magnetic
    char course_m_unit;
    char speed_k_unit;
    float speed_km; // speek km/hr
    char speed_km_unit;
} GPS_t;



void parser_init();
void parser(char *strparse);
void parser_uart_callback();




















#endif /* INC_PARSER_H_ */
