#include <iostream>

int main()
{
    int numberN = 0;
    int numberK = 0;
    std::cin >> numberN >> numberK;
    
    int result = 0;
    int count = 0;
    for (int index = 1; index <= numberN; index++)
    {
        if ((numberN % index == 0))
        {
            count++;
            if (count == numberK)
            {
                result = index;
            }
        }
    }
    
    std::cout << result;
}