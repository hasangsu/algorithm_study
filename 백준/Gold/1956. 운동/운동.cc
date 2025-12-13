#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    // v : 도시의 갯수
    // e : 도로의 갯수
    int v = 0;
    int e = 0;
    std::cin >> v >> e;
    
    std::vector<std::vector<int>> dist(v + 1, std::vector<int>(v + 1, INT_MAX));
    
    // 같은 도시로의 거리는 0
    for (int i = 1; i <= v; i++) 
    {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < e; i++)
    {
        int s = 0;
        int e = 0;
        int w = 0;
        std::cin >> s >> e >> w;
        
        dist[s][e] = std::min(dist[s][e], w);
    }
    
    // 플로이드 워셜 (목적지로 바로 가는것과 어딘가를 경유에서 가는것을 비교)
    // * k는 경유도시
    // * i는 출발도시
    // * j는 도착도시
    for (int k = 1; k <= v; k++)
    {
        for (int i = 1; i <= v; i++)
        {
            for (int j = 1; j <= v; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int cycle = INT_MAX;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (i != j && dist[i][j] != INT_MAX && dist[j][i] != INT_MAX)
            {
                cycle = std::min(cycle, dist[i][j] + dist[j][i]);
            }
        }
    }
    
    cycle == INT_MAX ? std::cout << -1 :
                       std::cout << cycle;
}