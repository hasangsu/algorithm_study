#include <iostream>

int main()
{
    int numberA = 0;
    int numberB = 0;
    while (scanf("%d %d", &numberA, &numberB) != -1)
    {
        printf("%d\n", (numberA + numberB));
    }
}