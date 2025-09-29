#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int nowLanks = 0;
    int score = 0;
    int lankCount = 0;
    std::cin >> nowLanks >> score >> lankCount;

    std::vector<int> lanks;
    lanks.reserve(lankCount);
    while (nowLanks--)
    {
        int n = 0;
        std::cin >> n;
        
        lanks.push_back(n);
    }
    
    // 비어있으면 무조건 1등
    if (lanks.empty())
    {
        std::cout << 1;
        return 0;
    }
    
    // 랭킹 리스트에 올라갈 수 없을 정도로 낮다면
    std::sort(lanks.rbegin(), lanks.rend());
    if ((lanks.size() == lankCount) &&
        (score <= lanks.back()))
    {
        std::cout << -1;
        return 0;
    }
    
    std::vector<int>::iterator it = std::lower_bound(lanks.begin(), lanks.end(), score, std::greater<int>());
    
    int rank = (it - lanks.begin()) + 1;
    std::cout << rank;
}