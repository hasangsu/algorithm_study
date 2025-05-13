#include <iostream>

int main()
{
    while (true)
    {
        int numberA = 0;
        int numberB = 0;
        scanf("%d %d", &numberA, &numberB);
        if ((numberA == 0) &&
            (numberB == 0))
        {
            break;
        }
        
        printf("%d\n", (numberA + numberB));
    }
}