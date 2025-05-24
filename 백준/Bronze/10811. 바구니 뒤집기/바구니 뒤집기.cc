#include <stdio.h>

int main()
{
    int pocketCount = 0;
    int methodCount = 0;
    scanf("%d %d", &pocketCount, &methodCount);
    
    int pocketArray[pocketCount];
    for (int index = 0; index < pocketCount; index++)
    {
        pocketArray[index] = index + 1;
    }
    
    for (int index = 0; index < methodCount; index++)
    {
        int reverseIndex1 = 0;
        int reverseIndex2 = 0;
        scanf("%d %d", &reverseIndex1, &reverseIndex2);

        // revese
        int reverseCount = reverseIndex2 - reverseIndex1 + 1;
        int reverseArray[reverseCount] = {0};
        int temp = 0;
        for (int index = reverseIndex2; reverseIndex1 <= index; index--)
        {
            reverseArray[temp] = pocketArray[index - 1];
            temp++;
        }
        
        // apply
        temp = 0;
        for (int index = reverseIndex1; index <= reverseIndex2; index++)
        {
            pocketArray[index - 1] = reverseArray[temp];
            temp++;
        }
    }
    
    for (int index = 0; index < pocketCount; index++)
    {
        printf("%d ", pocketArray[index]);
    }
}