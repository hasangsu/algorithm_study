#include <iostream>

int main()
{
    int count = 0;
    scanf("%d", &count);
    
    for (int line = 1; line <= count; line++)
    {
        for (int index = 0; index < line; index++)
        {
            printf("*");
        }
        printf("\n");
    }
}