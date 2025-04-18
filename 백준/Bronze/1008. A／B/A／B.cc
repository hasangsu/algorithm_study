#include <stdio.h>

int main()
{
    int number1;
    int number2;
    
    scanf("%d", &number1);
    scanf("%d", &number2);
    
    printf("%.13lf", (static_cast<double>(number1) / number2));
}