#include <iostream>

int main()
{
    int sum = 0.0;
    int diff = 0.0;
    std::cin >> sum >> diff;
    if ((sum < diff) || (sum + diff) % 2 != 0 || (sum - diff) % 2 != 0) 
    {
        std::cout << -1;
        return 0;
    }
    
    int a = (sum + diff) / 2;
    int b = (sum - diff) / 2;
    if ((a < 0) || (b < 0))
    {
        std::cout << -1;
        return 0;
    }
    
    if (a > b)
    {
        std::cout << a << " " << b;
    }
    else
    {
        std::cout << b << " " << a;
    }
}