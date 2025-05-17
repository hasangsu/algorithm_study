#include <iostream>

int main()
{
    int length = 0;
    int targetNumber = 0;
    scanf("%d %d", &length, &targetNumber);
    
    int numberArray[length];
    for (int index = 0; index < length; index++)
    {
        int number = 0;
        scanf("%d", &number);
        numberArray[index] = number;
    }
    
    for (int index = 0; index < length; index++)
    {
        int compareNumber = numberArray[index];
        if (compareNumber < targetNumber)
        {
            printf("%d\n", compareNumber);
        }
    }
}