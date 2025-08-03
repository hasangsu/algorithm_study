#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    std::unordered_map<int, bool> cardMap;
    for (int index = 0; index < count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        cardMap[number] = true;
    }

    int findCount = 0;
    std::cin >> findCount;
    
    for (int index = 0; index < findCount; index++)
    {
        int findNumber = 0;
        std::cin >> findNumber;
        
        if (cardMap.find(findNumber) != cardMap.end())
        {
            // 카드가 존재할 때
            std::cout << "1" << " ";
        }
        else
        {
            // 카드가 존재하지 않을 때
            std::cout << "0" << " ";
        }
    }
}