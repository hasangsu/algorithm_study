#include <iostream>

int main()
{
    int basketCount = 0;
    int inputMethod = 0;
    scanf("%d %d", &basketCount, &inputMethod);
    
    int basket[basketCount] = {0};
    for (int inputIndex = 0; inputIndex < inputMethod; inputIndex++)
    {
        int basketIndex1 = 0;
        int basketIndex2 = 0;
        int number = 0;
        scanf("%d %d %d", &basketIndex1, &basketIndex2, &number);
        
        for (int basketIndex = basketIndex1; basketIndex <= basketIndex2; basketIndex++)
        {
            basket[basketIndex - 1] = number;
        }
    }
    
    for (int arrayIndex = 0; arrayIndex < basketCount; arrayIndex++)
    {
        printf("%d\n", basket[arrayIndex]);
    }
}