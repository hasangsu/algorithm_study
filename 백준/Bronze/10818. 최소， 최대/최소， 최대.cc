#include <iostream>

int main()
{
    int length = 0;
    scanf("%d", &length);
    
    int numberArray[length];
    for (int index = 0; index < length; index++)
    {
        int number = 0;
        scanf("%d", &number);
        numberArray[index] = number;
    }
    
    int min = numberArray[0];
    int max = numberArray[0];
    for (int index = 0; index < length; index++)
    {
        int number = numberArray[index];
        if (min >= number)
        {
            min = number;
        }
        else if (max <= number)
        {
            max = number;
        }
        else
        {
            continue;
        }
    }
    
    printf("%d %d", min, max);
}