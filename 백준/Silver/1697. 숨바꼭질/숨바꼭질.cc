#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N = 0;
    int K = 0;
    std::cin >> N >> K;
    
    // 이동가능한 맵 크기
    int max = 100000;
    
    std::vector<int> dist(max + 1, -1);
    dist[N] = 0;
    
    std::queue<int> q;
    q.push(N);
    
    while (!q.empty())
    {
        // 현재 위치 (current pos)
        int c_p = q.front();
        q.pop();
        
        if (c_p == K)
        {
            std::cout << dist[c_p];
            break;
        }
        
        // 가능한 움직임
        int moves[3] = {c_p - 1, c_p + 1, c_p * 2};
        
        for (int i = 0; i < 3; i++)
        {
            // 다음 예상 위치 (next pos)
            int n_p = moves[i];
            if (0 <= n_p && n_p <= max && dist[n_p] == -1)
            {
                dist[n_p] = dist[c_p] + 1;
                q.push(n_p);
            }
        }
    }
}