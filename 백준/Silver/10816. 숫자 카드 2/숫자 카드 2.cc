#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 가지고 있는 카드 갯수
    int countN = 0;
    std::cin >> countN;
    
    // 가지고 있는 카드 맵 (번호, 갯수)
    std::unordered_map<int, int> hasCardMap;
    for (int index = 0; index < countN; index++)
    {
        int card = 0;
        std::cin >> card;
        
        hasCardMap[card]++;
    }
    
    // 확인 필요 카드 갯수
    int countM = 0;
    std::cin >> countM;
    
    // 확인 필요 카드
    for (int index = 0; index < countM; index++)
    {
        int card = 0;
        std::cin >> card;
        
        std::cout << hasCardMap[card] << " ";
    }
}