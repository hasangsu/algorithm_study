#include <iostream>

int main()
{
    int number;
    scanf("%d", &number);
    
    int sum = 0;
    for (int index = 1; index <= number; index++)
    {
        sum += index;
    }
    
    printf("%d\n", sum);
}