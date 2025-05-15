#include <iostream>

int main()
{
    int length;
    scanf("%d", &length);
    
    int numberArray[length];
    for (int index = 0; index < length; index++)
    {
        int number = 0;
        scanf("%d", &number);
        numberArray[index] = number;
    }
    
    int findNumber = 0;
    scanf("%d", &findNumber);
    
    int result = 0;
    for (int index = 0; index < length; index++)
    {
        if (numberArray[index] == findNumber)
        {
            result++;
        }
    }
    
    printf("%d\n", result);
}