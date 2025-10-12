#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<std::string> ids;
    for (int i = 0; i < count; i++)
    {
        std::string id = "";
        std::cin >> id;
        
        ids.push_back(id);
    }
    
    int min = 1;
    while (true)
    {
        std::unordered_map<std::string, bool> idsMap;
        bool isContain = false;
        
        for (int i = 0; i < count; i++)
        {
            std::string id = ids[i];
            int idLength = id.size();
            
            std::string targetId = ids[i].substr(id.size() - min);
            if (idsMap.find(targetId) != idsMap.end())
            {
                // 이미 있음
                isContain = true;
            }
            else
            {
                idsMap[targetId] = true;
            }
        }
        
        if (isContain)
        {
            min++;
        }
        else
        {
            break;
        }
    }
    
    std::cout << min;
}