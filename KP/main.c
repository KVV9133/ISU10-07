
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"
#include <inttypes.h>

#define SIZE 520000


sensor info[SIZE];
int m=1;

int main( int argc, char *argv[])
{   

    char str_in[100];
    for(int i=0;i<argc;i++)
    {   
        //printf("i = %d,argv = %s \n",i,argv[i]);
        char *str=argv[i];
        if (str[0]=='-')
        {
            switch(str[1])
            {
            case 'h':
                print_help();
                break;
            case 'f':
                sscanf(argv[i+1],"%s",str_in);
                break;
            case 'm':
                int temp;
                sscanf(argv[i+1],"%d",&temp);
                if(temp<=12 && temp>=1)
                    m=temp;
                else
                    printf("Неверный ввод");
            break;
            }
        }

    }

    read_file(str_in,info);
    avg_month_t(info,m);
    min_month_t(info,m);
    max_month_t(info,m);
    avg_year_t(info);
    min_year_t(info);
    max_year_t(info);

    return 0;
}