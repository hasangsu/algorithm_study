#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    std::unordered_map<std::string, bool> statusMap;
    for (int index = 0; index < count; index++)
    {
        std::string name = "";
        std::string status = "";
        std::cin >> name >> status;
        
        bool isEnter = (status == "enter") ? true : false;
        if (isEnter)
        {
            // 추가
            statusMap[name] = true;
        }
        else
        {
            // 제거
            statusMap.erase(name);
        }
    }

    std::vector<std::string> nameList;
    for (const std::pair<const std::string, bool> &status : statusMap) 
    {
        nameList.push_back(status.first);
    }
    
    std::sort(nameList.begin(), nameList.end(), std::greater<std::string>());
    for (const std::string &name : nameList)
    {
        std::cout << name << "\n";
    }
}