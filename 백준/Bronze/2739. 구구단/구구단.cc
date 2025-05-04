#include <iostream>

int main()
{
    int number;
    scanf("%d", &number);
    
    for (int index = 1; index <= 9; index++)
    {
        printf("%d * %d = %d\n", number, index, (number * index));
    }
}