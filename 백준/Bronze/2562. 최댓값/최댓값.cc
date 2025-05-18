#include <iostream>

int main()
{
    int length = 9;
    int numberArray[length];
    for (int index = 0; index < length; index++)
    {
        int number = 0;
        scanf("%d", &number);
        numberArray[index] = number;
    }
    
    int max = 0;
    int maxIndex = 0;
    for (int index = 0; index < length; index++)
    {
        int number = numberArray[index];
        if (max <= number)
        {
            max = number;
            maxIndex = index + 1;
        }
    }
    
    printf("%d\n", max);
    printf("%d\n", maxIndex);
}