#include <stdio.h>

int main()
{
    unsigned long number1;
    unsigned long number2;
    unsigned long number3;
    
    scanf("%lu %lu %lu", &number1, &number2, &number3);
    printf("%lu\n", (number1 + number2 + number3));    
}