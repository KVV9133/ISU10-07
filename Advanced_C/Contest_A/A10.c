#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>


union floatbit {
    float value;
    struct {
        uint32_t mant : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
    } bit;
} f;


int main()
{	
	float a;
	scanf("%f",&a);
	f.value=a;
	printf("%u",f.bit.exp);

    return 0;
}