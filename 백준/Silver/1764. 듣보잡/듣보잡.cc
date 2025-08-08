#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int hearCount = 0;
    int seeCount = 0;
    std::cin >> hearCount >> seeCount;
    
    // 듣도 못한 사람 맵
    std::unordered_map<std::string, bool> hearMap;
    for (int index = 0; index < hearCount; index++)
    {
        std::string name = "";
        std::cin >> name;
        
        hearMap[name] = true;
    }
    
    // 보도 못한 사람 맵
    std::unordered_map<std::string, bool> seeMap;
    for (int index = 0; index < seeCount; index++)
    {
        std::string name = "";
        std::cin >> name;
        
        seeMap[name] = true;
    }
    
    // 찾기
    int result = 0;
    std::vector<std::string> results;
    for (std::pair<const std::string, bool> hear : hearMap) 
    {
        // 듣도 못한 사람 이름
        std::string name = hear.first;
        
        // 듣도 못한 사람 이름으로 보도 못한 사람 찾기
        if (seeMap.find(name) != seeMap.end()) 
        {
            result++;
            results.push_back(name);
        }
    }
    
    std::sort(results.begin(), results.end());
    std::cout << result << "\n";
    for (const std::string &name : results)
    {
        std::cout << name << "\n";
    }
}