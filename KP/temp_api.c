#include "temp_api.h"

char *int_to_month(int n)
{
switch(n)
{
case 1:
    return "January";
case 2:
    return "February";
case 3:
    return "March";
case 4:
    return "April";
case 5:
    return "May";
case 6:
    return "June ";
case 7:
    return "July";
case 8:
    return "August";
case 9:
    return "September";
case 10:
    return "October";
case 11:
    return "November";
case 12:
    return "December";
}
}

int AddInfo(sensor* info){
int counter=0;  
    AddRecord(info,counter++,2000,9,16,9);
    AddRecord(info,counter++,2022,9,2,-9);
    AddRecord(info,counter++,2021,1,7,8);
    AddRecord(info,counter++,2021,9,5,1);
    return counter;
}

void AddRecord(sensor* info,int number,
uint16_t year,uint8_t month,uint8_t day,int8_t t){
    info[number].year = year;
    info[number].month = month;
    info[number].day = day;
    info[number].t = t;
}



void print( sensor* info,int number){
printf("===================================\n");        
    for(int i=0;i<number;i++)
        printf("%04d-%02d-%02d-%02d-%02d t=%3d\n",    
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].min,
            info[i].sec,
            info[i].t
        );
}



void avg_month_t( sensor* info, int month)
{    
    int i=0;
    int count=0;
    int sum=0;
    while(1)
    {   
        if (info[i].month==month)
        {
            sum+=info[i].t;
            count++;
        }
    else if(info[i].month>month || info[i].year==0)   // Проверка последней строки в массиве структур(мб лучше решение есть)
            break;
        i++;
    }
    printf("===================================\n"); 
    printf("Average monthly temperature for %s = %.2f \n",int_to_month(month),(float)sum/count);    
    //return (float)sum/count;
}

void min_month_t( sensor* info, int month)
{    
int i=0;
int8_t min=127;
while(1)
{   
    if (info[i].month==month)
    {
        if(info[i].t<min)
        min=info[i].t;
    }
    else if(info[i].month>month || info[i].year==0)   // Проверка последней строки в массиве структур(мб лучше решение есть)
        break;

    i++;
    }
    printf("===================================\n"); 
    printf("Minimum monthly temperature for %s = %hhd \n",int_to_month(month),min);  
    //return min;
}

void max_month_t( sensor* info,int month)
{    
    int i=0;
    int8_t max=-128;
    while(1)
    {   
    if (info[i].month==month)
    {
        if(info[i].t>max)
        max=info[i].t;
    }
    else if(info[i].month>month || info[i].year==0)   // Проверка последней строки в массиве структур(мб лучше решение есть)
        break;

    i++;
    }
    printf("===================================\n"); 
    printf("Maximum monthly temperature for %s = %hhd \n",int_to_month(month),max);  
    //return max;
}


void avg_year_t( sensor* info)
{    
    int sum=0;
    int count=0;
    for(int i =0;info[i].year!=0;i++)
    {
        sum+=info[i].t;
        count++;
    }
    printf("===================================\n"); 
    printf("Average annual temperature = %.2f \n",(float)sum/count);    
    //return (float)sum/count;
}


void min_year_t( sensor* info)
{    

    int8_t min=127;
    for(int i =0;info[i].year!=0;i++)
    {   
        if (info[i].t<min)
            min=info[i].t;
    }
    printf("===================================\n"); 
    printf("Minimum temperature for the year = %hhd \n",min);    
    //return min;
}


void max_year_t( sensor* info)
{    
    int8_t max=-128;
    for(int i =0;info[i].year!=0;i++)
    {
        if (info[i].t>max)
            max=info[i].t;
    }
    printf("===================================\n"); 
    printf("Maximum temperature for the year = %hhd \n",max);    
    //return max;
}


void read_file( char *filename, sensor *info) // Добавить обработку входных данных
    {
    FILE *fr = fopen(filename, "r");
    if (fr == NULL) 
    {
        printf("Error, file could not be opened: %s\n", filename);
        return ;
    }
    char s[100];
    sensor *pt=info;
    int i=0;
    while(fscanf(fr," %[^\n]",s)!= EOF && i <1000000)
    {
        //printf("%s\n",s);
        sscanf(s,"%" SCNd16 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ,
        &(pt[i].year), &(pt[i].month),
        &(pt[i].day), &(pt[i].min),
        &(pt[i].sec), &(pt[i].t));
        i++;
    };
    fclose(fr);
    }

    void print_help(void)
{
    printf( "The -h key is intended for\n"
            "The -f key is intended for\n"
            "The -m key is intended for\n");
}





