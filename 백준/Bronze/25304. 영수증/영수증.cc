#include <iostream>

int main()
{
    int totalPrice = 0;
    int itemCount = 0;
    scanf("%d", &totalPrice);
    scanf("%d", &itemCount);
    
    int tempPrice = 0;
    for (int index = 0; index < itemCount; index++)
    {
        int price = 0;
        int count = 0;
        scanf("%d %d", &price, &count);
        
        tempPrice += (price * count);
    }
    
    if (totalPrice == tempPrice)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}