#include <iostream>

int main()
{
    int count = 0;
    scanf("%d", &count);
    
    for (int index = 0; index < count; index++)
    {
        int numberA = 0;
        int numberB = 0;
        scanf("%d %d", &numberA, &numberB);
        printf("Case #%d: %d + %d = %d\n", index + 1, numberA, numberB, (numberA + numberB));
    }
}