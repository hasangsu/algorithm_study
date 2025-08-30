#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int total = count * count;
    int result = total - count;
    
    std::cout << result;
}