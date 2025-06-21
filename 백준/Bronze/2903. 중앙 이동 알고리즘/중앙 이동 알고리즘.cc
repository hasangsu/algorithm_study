#include <iostream>
#include <cmath>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int line = std::pow(2, count);
    int point = line + 1;
    int totalPoint = point * point;
    
    std::cout << totalPoint;
}