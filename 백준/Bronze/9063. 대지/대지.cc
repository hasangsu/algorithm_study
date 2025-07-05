#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int minX = 10000;
    int minY = 10000;
    int maxX = -10000;
    int maxY = -10000;
    for (int index = 0; index < count; index++)
    {
        int inputX = 0;
        int inputY = 0;
        std::cin >> inputX >> inputY;
        
        // 최소 위치
        if (inputX < minX)
        {
            minX = inputX;
        }
        if (inputY < minY)
        {
            minY = inputY;
        }
        
        // 최대 위치
        if (maxX < inputX)
        {
            maxX = inputX;
        }
        if (maxY < inputY)
        {
            maxY = inputY;
        }
    }
    
    int result = 0;
    if (2 <= count)
    {
        result = (maxX - minX) * (maxY - minY);
    }
    
    std::cout << result;
}