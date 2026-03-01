#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> mans(9);
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        std::cin >> mans[i];
        total += mans[i];
    }
    
    int fake1 = 0;
    int fake2 = 0;
    bool isFind = false;
    int target = total - 100;
    
    std::sort(mans.begin(), mans.end());
    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (mans[i] + mans[j] == target)
            {
                fake1 = mans[i];
                fake2 = mans[j];
                isFind = true;
                break;
            }
        }
        
        if (isFind)
        {
            break;
        }
    }
    
    for (const int man : mans)
    {
        if (man == fake1 ||
            man == fake2)
        {
            continue;
        }
        
        std::cout << man << "\n";
    }
}