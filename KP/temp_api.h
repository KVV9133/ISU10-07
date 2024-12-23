#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

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
int AddInfo(sensor* info);
void print(sensor *,int);
void avg_month_t( sensor* ,int );
void min_month_t( sensor*,int  );
void max_month_t( sensor*,int  );
void avg_year_t( sensor*  );
void min_year_t( sensor*  );
void max_year_t( sensor*  );

void read_file( char *, sensor *); 
void print_help(void);
