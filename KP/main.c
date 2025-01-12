
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "temp_api.h"
#include <inttypes.h>



//sensor  *info;
int m=1;
int interact_regime = 0;
int check_key=0;
int y_regime=0;
int month_regime=0;

int main( int argc, char *argv[])
{   

    char str_in[100]="temperature_small.csv";
    for(int i=0;i<argc;i++)
    {   
        //printf("i = %d,argv = %s \n",i,argv[i]);
        char *str=argv[i];
        if (str[0]=='-')
        {   
            check_key=1;
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
                {
                    m=temp;
                    month_regime=1;
                }
                else
                    printf("Неверный ввод");
                break;
             case 'i':
                interact_regime = 1;
                break;
            case 'y':
                y_regime = 1;
                break;
            }
        }

    }
    int size=0; //Кол-во строк
    sensor *info = NULL;
    read_file(str_in,&info, &size);

    if (!check_key)
        print_pr();
    if (interact_regime) 
    {
    int input_month;
    while (1) 
    {
        printf("Enter the month number (1-12) for statistics or 0 to exit: ");
        if (scanf("%d", &input_month) != 1 || input_month == 0) 
        {
            printf("Exit.\n");
            break;
        }

        if (input_month < 1 || input_month > 12) 
        {
            printf("Please enter a number between 1 and 12.\n");
            continue;
        }
        printf("Statistics for %s:\n", int_to_month(input_month));
        avg_month_t(info, input_month);
        min_month_t(info, input_month);
        max_month_t(info, input_month);
    }
    }

    if (y_regime)
    {
        print_statistics(info,size);
        avg_year_t(info,size);
        max_year_t(info,size);
        min_year_t(info,size);
    }

    if (month_regime)
    {
        avg_month_t(info,m);
        min_month_t(info,m);
        max_month_t(info,m);
    }


    // avg_month_t(info,m);
    // min_month_t(info,m);
    // max_month_t(info,m);
    // avg_year_t(info,size);
    // min_year_t(info,size);
    // max_year_t(info,size);
    // printf("%d",size);
    // print(info,size);
    return 0;
}