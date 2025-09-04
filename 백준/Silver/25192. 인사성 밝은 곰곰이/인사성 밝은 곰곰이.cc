#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    int result = 0;
    std::unordered_map<std::string, bool> userMap;
    while (count--)
    {
        std::string user = "";
        std::cin >> user;
        
        if (user == "ENTER")
        {
            // 새로운 유저의 입장
            // 기존 유저맵 클리어
            userMap.clear();
        }
        else
        {
            // 이전 곰곰 이모티콘 사용 여부확인
            if (userMap.find(user) == userMap.end())
            {
                // 사용하지 않았으면 결과 증가
                result++;
            }
            
            userMap[user] = true;
        }
    }
    
    std::cout << result;
}