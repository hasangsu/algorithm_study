#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    int K = 0;
    std::cin >> N >> K;
    
    std::vector<std::pair<long long, long long>> gems(N);
    std::vector<long long> bags(K);
    
    // 보석 정보
    for (int i = 0; i < N; i++)
    {
        std::cin >> gems[i].first >> gems[i].second;
    }
    
    // 가방 정보
    for (int i = 0; i < K; i++)
    {
        std::cin >> bags[i];
    }
    
    // 정렬
    std::sort(gems.begin(), gems.end());
    std::sort(bags.begin(), bags.end());
    
    // 가격 구하기
    long long result = 0;
    std::priority_queue<long long> pq;
    int j = 0;
    
    for (int i = 0; i < K; i++)
    {
        long long w = bags[i];
        
        while ((j < N) && gems[j].first <= w)
        {
            pq.push(gems[j].second);
            j++;
        }
        
        if (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }
    
    std::cout << result;
}