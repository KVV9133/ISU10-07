#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int *mass, struct pack_array *str_pack)
{	
	unsigned int res = 0;
	str_pack->count0 = 0;
    str_pack->count1 = 0;
	for(int i=0;i<32;i++)
	{
		res = (res << 1) | (mass[i] & 1);
		if (mass[i])
			str_pack->count1++;
		else
			str_pack->count0++;
	}
	str_pack->array = res;
	printf("%u %u %u",str_pack->array,str_pack->count0, str_pack->count1);
}

int main()
{	
	struct pack_array str_pack;
	int bit_mass[32];
	int *p_m=bit_mass;
	for(int i=0;i<32;p_m++,i++)
	scanf("%d",p_m);
	array2struct(bit_mass, &str_pack);

    return 0;
}
