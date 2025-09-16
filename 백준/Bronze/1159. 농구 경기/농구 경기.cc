#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::unordered_map<char, int> nameMap;
    std::string name = "";
    while (count--)
    {
        std::cin >> name;
        nameMap[name[0]]++;
    }
    
    // 같은성 5명이상 리스트
    std::vector<char> result;
    for (const std::pair<char, int> &kv : nameMap)
    {
        const char key = kv.first;
        const int value = kv.second;
        if (value >= 5)
        {
            result.push_back(key);
        }
    }
    
    if (result.size() <= 0)
    {
        // 기권
        std::cout << "PREDAJA";
    }
    else
    {
        // 사전순 정렬
        std::sort(result.begin(), result.end());
    
        // 출력
        for (const char &ch : result)
        {
            std::cout << ch;
        }
    }
    
}