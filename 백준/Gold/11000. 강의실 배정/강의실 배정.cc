#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> lectures(N);
    for (int i = 0; i < N; i++) 
    {
        std::cin >> lectures[i].first >> lectures[i].second;
    }

    std::sort(lectures.begin(), lectures.end());
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    
    // 강의 끝나는 시간
    pq.push(lectures[0].second);
    for (int i = 1; i < N; i++) 
    {
        // 이전 강의 끝나는 시간3시 <= 다음 강의 시작시간 3시또는 그 이후
        if (pq.top() <= lectures[i].first)
        {
            pq.pop();
        }
        
        // 강의실 갱신 혹은 새 강의실 추가
        pq.push(lectures[i].second);
    }

    std::cout << pq.size();
}