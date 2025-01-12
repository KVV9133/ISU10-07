#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

 typedef struct  {
    uint8_t sec;
    uint8_t min;
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t t;
} sensor ;

void AddRecord(sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day,int8_t t);
void print_pr();
void print_statistics(sensor* , int );
int AddInfo(sensor* info);
void print(sensor *,int);
char* int_to_month(int n);
void avg_month_t( sensor* ,int );
void min_month_t( sensor*,int  );
void max_month_t( sensor*,int  );
void avg_year_t( sensor*  ,int);
void min_year_t( sensor*  ,int);
void max_year_t( sensor*  ,int);

void read_file( char *, sensor **,int*); 
void print_help(void);
