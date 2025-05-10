#include <iostream>

int main()
{
    int count = 0;
    scanf("%d", &count);
    
    int result[count];
    for (int index = 0; index < count; index++)
    {
        int numberA = 0;
        int numberB = 0;
        scanf("%d %d", &numberA, &numberB);
        result[index] = (numberA + numberB);
    }
    
    for (int index = 0; index < count; index++)
    {
        printf("Case #%d: %d\n", index + 1, result[index]);
    }
}