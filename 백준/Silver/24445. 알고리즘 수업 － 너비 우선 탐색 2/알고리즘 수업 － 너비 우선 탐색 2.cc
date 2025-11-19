#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int order = 0;

void bfs(std::vector<bool> &visited,
        std::vector<int> &orders,
        const std::vector<std::vector<int>> &E, 
        int R)
{
    // 방문
    visited[R] = true;
    
    std::queue<int> q;
    q.push(R);
    
    // 순번
    order++;
    orders[R] = order;
    
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        
        for (const int n : E[t])
        {
            if (!visited[n])
            {
                // 내림차순 간선 방문
                visited[n] = true;
                
                order++;
                orders[n] = order;
                
                q.push(n);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    int M = 0;
    int R = 0;
    std::cin >> N >> M >> R;
    
    std::vector<std::vector<int>> E(N + 1);
    std::vector<bool> visited(N + 1);
    std::vector<int> orders(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u = 0;
        int v = 0;
        std::cin >> u >> v;
        
        E[u].push_back(v);
        E[v].push_back(u);
    }
    
    for (int i = 1; i <= N; i++)
    {
        //  내림차순 정렬
        std::sort(E[i].begin(), E[i].end(), std::greater<int>());
    }
    
    bfs(visited, orders, E, R);
    for (int i = 1; i <= N; i++)
    {
        std::cout << orders[i] << "\n";
    }
}