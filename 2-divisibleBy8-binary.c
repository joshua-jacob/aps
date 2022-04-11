#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    printf("Enter a number\n");
    scanf("%d",&num);
    int result =  num;
	result = (result  >> 3) << 3;
	if (num == result)
        printf("Divisible by 8\n");
    else
        printf("Not divisible by 8\n");
    return 0;
}
