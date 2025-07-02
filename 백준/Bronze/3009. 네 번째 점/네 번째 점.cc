#include <iostream>
#include <map>

int main()
{
    std::map<int, int> xMap;
    std::map<int, int> yMap;
    for (int index = 0; index < 3; index++)
    {
        int x = 0;
        int y = 0;
        std::cin >> x >> y;
        
        xMap[x]++;
        yMap[y]++;
    }
    
    int resultX = 0;
    int resultY = 0;
    
    for (const std::pair<const int, int> &pair : xMap)
    {
        if (pair.second == 1)
        {
            resultX = pair.first;
        }
    }
    
    for (const std::pair<const int, int> &pair : yMap)
    {
        if (pair.second == 1)
        {
            resultY = pair.first;
        }
    }
    
    std::cout << resultX << " " << resultY;
}