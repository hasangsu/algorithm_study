#include <iostream>

int main()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        int n = 0;
        std::cin >> n;
        
        int square = n * n;
        sum += square;
    }
    
    int verification = sum % 10;
    std::cout << verification;
}