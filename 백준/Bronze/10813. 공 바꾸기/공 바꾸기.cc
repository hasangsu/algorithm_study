#include <iostream>

int main()
{
    int basketCount = 0;
    int inputMethod = 0;
    scanf("%d %d", &basketCount, &inputMethod);
    
    int basket[basketCount] = {0};
    for (int bastketIndex = 0; bastketIndex < basketCount; bastketIndex++)
    {
        basket[bastketIndex] = bastketIndex + 1;
    }
    
    for (int inputIndex = 0; inputIndex < inputMethod; inputIndex++)
    {
        int bastketIndex1 = 0;
        int bastketIndex2 = 0;
        scanf("%d %d", &bastketIndex1, &bastketIndex2);
        
        int temp = basket[bastketIndex1 - 1];
        basket[bastketIndex1 - 1] = basket[bastketIndex2 - 1];
        basket[bastketIndex2 - 1] = temp;
    }
    
    for (int bastketIndex = 0; bastketIndex < basketCount; bastketIndex++)
    {
        printf("%d\n", basket[bastketIndex]);
    }
}