#include <iostream>

int main()
{
    int tastCase;
    scanf("%d", &tastCase);
    
    int result[tastCase];
    for (int index = 0; index < tastCase; index++)
    {
        int numberA;
        int numberB;
        scanf("%d %d", &numberA, &numberB);
        
        result[index] = (numberA + numberB);
    }
    
    for (int index = 0; index < tastCase; index++)
    {
        printf("%d\n", result[index]);
    }
}