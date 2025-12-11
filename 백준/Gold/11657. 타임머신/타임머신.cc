#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

bool bellmanFord(int N, int start, const std::vector<std::tuple<int, int, int>> &edges, std::vector<long long> &dist)
{
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] = INT_MAX;
    }
    dist[start] = 0;
    
    for (int i = 0; i < N - 1; i++)
    {
        bool update = false;
        
        for (const std::tuple<int, int, int> edge : edges)
        {
            int s = std::get<0>(edge);
            int e = std::get<1>(edge);
            int w = std::get<2>(edge);
            
            if (dist[s] != INT_MAX)
            {
                // 최단거리라면 갱신
                if (dist[s] + w < dist[e])
                {
                    dist[e] = dist[s] + (w * 1LL);
                    update = true;
                }
            }
        }
        
        if (!update)
        {
            break;
        }
    }
    
    bool result = true;
    for (const std::tuple<int, int, int> edge : edges)
    {
        int s = std::get<0>(edge);
        int e = std::get<1>(edge);
        int w = std::get<2>(edge);
        
        if (dist[s] != INT_MAX)
        {
            // 마이너스 갱신
            if (dist[s] + w < dist[e])
            {
                result = false;
            }
        }
    }
    
    return result;
}

int main()
{
    // N : 도시(노드)의 갯수
    // M : 버스노선(간선)의 갯수
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    // (0) : 시작도시
    // (1) : 끝도시
    // (2) : 가중치
    std::vector<std::tuple<int, int, int>> edges(M);
    for (int i = 0; i < M; i++)
    {
        int s = 0;
        int e = 0;
        int w = 0;
        std::cin >> s >> e >> w;
        
        edges[i] = {s, e, w};
    }
    
    int start = 1;
    std::vector<long long> dist(N + 1);
    
    bool canGo = bellmanFord(N, start, edges, dist);
    if (canGo)
    {
        for (int i = start + 1; i <= N; i++)
        {
            long long d = dist[i];
            if (d == INT_MAX)
            {
                std::cout << -1 << "\n";
            }
            else
            {
                std::cout << d << "\n";
            }
        }
    }
    else
    {
        std::cout << -1;
    }
}