#include <iostream>
#include <algorithm>
#include <vector>

int checkSkill(std::vector<int> &skills, int coolTime)
{
    // 스킬을 사용하지 않았다면
    if (skills.empty())
    {
        return 0;
    }
    
    // 스킬 사용 시간순으로 정렬
    std::sort(skills.begin(), skills.end());
    
    int count = 1;
    int last = skills[0];
    
    for (int i = 1; i < skills.size(); i++) 
    {
        if (skills[i] - last >= coolTime) 
        {
            count++;
            last = skills[i];
        }
    }
    
    return count;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // N : 에르다 노바 사용횟수
    // M : 오리진 스킬 사용횟수
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    std::vector<int> novas(N);
    std::vector<int> origins(M);
    for (int i = 0; i < N; i++)
    {
        std::cin >> novas[i];
    }
    for (int i = 0; i < M; i++)
    {
        std::cin >> origins[i];
    }
    
    int nova_count = checkSkill(novas, 100);
    int origin_count = checkSkill(origins, 360);
    std::cout << nova_count << " " << origin_count;
}