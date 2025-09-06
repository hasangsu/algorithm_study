#include <iostream>
#include <unordered_map>

bool isDancing(const std::unordered_map<std::string, bool> &danceMap, const std::string &user)
{
    std::unordered_map<std::string, bool>::const_iterator it = danceMap.find(user);
    if (it == danceMap.end())
    {
        return false;
    }
    
    return it->second;
}
    
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    // 기본적으로 총총이는 춤을 추고 있다.
    std::unordered_map<std::string, bool> danceMap;
    danceMap["ChongChong"] = true;
    
    while (count--)
    {
        std::string user1 = "";
        std::string user2 = "";
        std::cin >> user1 >> user2;
        
        if (isDancing(danceMap, user1) || isDancing(danceMap, user2))
        {
            danceMap[user1] = true;
            danceMap[user2] = true;
        }
    }
    
    std::cout << danceMap.size();
}