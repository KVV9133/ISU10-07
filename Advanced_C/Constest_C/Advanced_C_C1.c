#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[2000];
	char str2[2000];
    scanf("%s", str1);
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = (len1 < len2) ? len1 : len2;

    int counter1 = 0;
    int counter2 = 0;

    for (int i = 1; i <= min_len; i++) {

        if (memcmp(str1, str2 + (len2 - i), i) == 0) 
        {
            counter1 = i;
        }
        if (memcmp(str1 + (len1 - i), str2, i) == 0) 
        {
            counter2 = i;
        }
    }

    printf("%d %d\n", counter1, counter2);
    return 0;
}
