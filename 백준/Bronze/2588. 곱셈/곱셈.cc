#include <stdio.h>

int main()
{
    int number1;
    int number2;
    
    scanf("%d", &number1);
    scanf("%d", &number2);
    
    printf("%d\n", (number1 * (number2 % 10)));
    printf("%d\n", (number1 * ((number2 / 10) % 10)));
    printf("%d\n", (number1 * (number2 / 100)));
    printf("%d\n", (number1 * number2));    
}