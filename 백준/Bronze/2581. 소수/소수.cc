#include <iostream>

int main()
{
    int numberM = 0;
    std::cin >> numberM;
    
    int numberN = 0;
    std::cin >> numberN;
    
    int sum = 0;
    int min = numberN;
    for (int index = numberM; index <= numberN; index++)
    {
        if (index < 2)
        {
            continue;
        }
        
        bool isPrime = true;
        for (int primeIndex = 2; primeIndex < index; primeIndex++)
        {
            if (index % primeIndex == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime)
        {
            sum += index;
            
            if (index <= min)
            {
                min = index;
            }
        }
    }
    
    if (sum != 0)
    {
        std::cout << sum << "\n";
        std::cout << min;
    }
    else
    {
        std::cout << "-1";
    }
}