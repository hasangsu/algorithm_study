#include <iostream>
#include <algorithm>

int main()
{
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    std::cin >> x >> y >> w >> h;
    
    int xMin = std::min(std::abs(x - w), std::abs(x - 0));
    int yMin = std::min(std::abs(y - h), std::abs(y - 0));
    int result = std::min(xMin, yMin);
    std::cout << result;
}