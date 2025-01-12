#include "temp_api.h"

char *int_to_month(int n)
{   
    char *month[] = 
    {
        "Invalid month",
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    return month[n];
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
    printf("====================================================\n"); 
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
    else if(info[i].month>month || info[i].year==0)   // Проверка последней строки в массиве структур(мб лучше решение есть)-
        break;

    i++;
    }
    printf("====================================================\n"); 
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
    printf("====================================================\n"); 
    printf("Maximum monthly temperature for %s = %hhd \n",int_to_month(month),max);  
    //return max;
}


void avg_year_t( sensor* info,int size)
{    
    int sum=0;
    int count=0;
    for(int i =0;i<size;i++)
    {
        sum+=info[i].t;
        count++;
    }
    printf("====================================================\n"); 
    printf("Average annual temperature = %.2f \n",(float)sum/count);    
    //return (float)sum/count;
}


void min_year_t( sensor* info,int size)
{    

    int8_t min=127;
    for(int i =0;i<size;i++)
    {   
        if (info[i].t<min)
            min=info[i].t;
    }
    printf("====================================================\n"); 
    printf("Minimum temperature for the year = %hhd \n",min);    
    printf("====================================================\n"); 
    //return min;
}


void max_year_t( sensor* info,int size)
{    
    int8_t max=-128;
    for(int i =0;i<size;i++)
    {
        if (info[i].t>max)
            max=info[i].t;
    }
    printf("====================================================\n"); 
    printf("Maximum temperature for the year = %hhd \n",max);    
    //return max;
}


void read_file( char *filename, sensor **info,int *size) // Добавить обработку входных данных - done
{
    FILE *fr = fopen(filename, "r");
    if (fr == NULL) 
    {
        printf("Error, file could not be opened: %s\n", filename);
        return ;
    }
    char s[100];
    int t_size=10;
    *info = (sensor*)malloc(t_size * sizeof(sensor));
    while(fscanf(fr," %[^\n]",s)!= EOF)
    {   
        if (*size==t_size)
        {
            t_size+=10;
            sensor* new_sensor=realloc(*info,sizeof(sensor)*t_size);
            *info=new_sensor;

            //printf("t_size-%d\n",t_size);
        }
        //printf("%s\n",s);
        int16_t temp_year;
        int8_t temp_month, temp_day, temp_min, temp_sec, temp_t;
        int  check_str=sscanf(s, "%" SCNd16 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8,
        &temp_year,&temp_month,&temp_day,&temp_min,&temp_sec,&temp_t);
        if (check_str != 6) 
        {
            printf("Error: The string \"%s\" contains invalid data. String Number %d\n", s,*size);
            continue;
        }
    
    
            if (temp_year < 0 || temp_year > 3000 ||  
            temp_month < 1 || temp_month > 12 ||    
            temp_day < 1 || temp_day > 31 ||        
            temp_min < 0 || temp_min > 59 ||        
            temp_sec < 0 || temp_sec > 59)          
        {
            printf("Error: The string \"%s\" contains invalid data.\n", s);
            continue; 
        }
        (*info)[*size].year = temp_year;
        (*info)[*size].month = temp_month;
        (*info)[*size].day = temp_day;
        (*info)[*size].min = temp_min;
        (*info)[*size].sec = temp_sec;
        (*info)[*size].t = temp_t;
        (*size)++;
    }
    //     if(sscanf(s, "%" SCNd16 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8 ";" "%" SCNd8,
    //            &((*info)[*size].year), &((*info)[*size].month),
    //            &((*info)[*size].day), &((*info)[*size].min),
    //            &((*info)[*size].sec), &((*info)[*size].t))!=6);
    //     (*size)++;
    // };
    
    fclose(fr);
}
    



void print_help(void) {
    printf("==============================================================================\n");
    printf("| %-10s | %-61s |\n", "Key", "Description");
    printf("==============================================================================\n");
    printf("| %-10s | %-61s |\n", "-h", "Displays this help message");
    printf("| %-10s | %-61s |\n", "-f", "Specifies the name of the CSV file");
    printf("| %-10s | %-61s |\n", "-m", "Calculates statistics for the specified month (1-12)");
    printf("| %-10s | %-61s |\n", "-i", "Interactive mode to analyze months");
    printf("| %-10s | %-61s |\n", "-y", "Display statistics for the entire year");
    printf("==============================================================================\n");
}


void print_statistics(sensor* info, int size) {
    printf("====================================================\n");
    printf("| Year | Month | MonthAvg  | MonthMax   | MonthMin |\n");
    printf("====================================================\n");

    for (int month = 1; month <= 12; month++) {
        int count = 0;
        int sum = 0;
        int min = 127;
        int max = -128;

        for (int i = 0; i < size; i++) {
            if (info[i].month == month) {
                count++;
                sum += info[i].t;
                if (info[i].t > max) 
                    max = info[i].t;
                if (info[i].t < min) 
                    min = info[i].t;
            }
        }

        if (count > 0) {
            printf("| %4d | %5d | %9.2f | %9d | %9d |\n",
                   info[0].year, month, (float)sum / count, max, min);
        }
    }

    printf("====================================================\n"); 
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


void print_pr()
{
    printf("====================================================\n"); 
    printf("         Welcome to Temp Statistic Application      \n");
    printf("====================================================\n");
    printf("You can use the following commands:\n");
    printf("- -h: Show help message.\n");
    printf("- -f <filename>: Specify the input CSV file.\n");
    printf("- -m <month>: Analyze a specific month (1-12).\n");
    printf("- -i: Interactive mode to analyze months.\n");
    printf("- -y: Display statistics for the entire year.\n");
    printf("====================================================\n");
}
