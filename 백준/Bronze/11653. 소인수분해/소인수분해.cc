#include <iostream>

int main()
{
    int numberN = 0;
    std::cin >> numberN;
    
    if (numberN < 2)
    {
    }
    else
    {
        for (int index = 2; index <= numberN; index++)
        {
            while (numberN % index == 0)
            {
                std::cout << index << "\n";
                numberN = numberN / index;
            }
        }    
    }
}