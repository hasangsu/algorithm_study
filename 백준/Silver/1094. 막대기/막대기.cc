#include <iostream>

int main()
{
    int length = 0;
    std::cin >> length;
    
    int count = 0;
    int temp = length;
    
    while (temp > 0)
    {
        if (temp & 1)
        {
            count++;
        }
        
        temp >>= 1;
    }
    
    std::cout << count;
}