#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int countN = 0;
    int countM = 0;
    std::cin >> countN >> countM;

    // 문자열 집합 만들기
    std::unordered_map<std::string, bool> sMap;
    for (int index = 0; index < countN; index++)
    {
        std::string s = "";
        std::cin >> s;
        
        sMap[s] = true;
    }
    
    // 비교대상 문자열
    int result = 0;
    for (int index = 0; index < countM; index++)
    {
        std::string s = "";
        std::cin >> s;
        
        if (sMap.find(s) != sMap.end())
        {
            result++;
        }
    }
    
    std::cout << result;
}