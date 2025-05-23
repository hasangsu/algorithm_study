#include <stdio.h>

int main()
{
    int count = 10;
    int divide = 42;
    int rest[divide] = {0};
    for (int index=0; index < count; index++)
    {
        int number = 0;
        scanf("%d", &number);
        
        rest[number % divide] = 1;
    }
    
    int result = 0;
    for (int index=0; index < divide; index++)
    {
        if (rest[index] == 1)
        {
            result++;
        }
    }
    
    printf("%d\n", result);
}