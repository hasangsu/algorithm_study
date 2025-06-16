#include <iostream>

int main()
{
    int count = 5;
    int maxLength = 15;
    std::string inputs[count];

    for (int index = 0; index < count; index++)
    {
        std::cin >> inputs[index];
    }
    
    for (int stringIndex = 0; stringIndex < maxLength; stringIndex++)
    {
        for (int inputIndex = 0; inputIndex < count; inputIndex++)
        {
            if (stringIndex < inputs[inputIndex].length())
            {
                std::cout << inputs[inputIndex][stringIndex];
            }
        }
    }
}