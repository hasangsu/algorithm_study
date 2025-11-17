#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<bool> &visited, 
        std::vector<int> &orders,
        int &order,
        const std::vector<std::vector<int>> &E, 
        int R)
{
    visited[R] = true;
    orders[R] = order++;
    
    for (const int n : E[R])
    {
        if (!visited[n])
        {
            dfs(visited, orders, order, E, n);
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
    int order = 1;
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
        std::sort(E[i].begin(), E[i].end(), std::greater<int>());
    }
    
    dfs(visited, orders, order, E, R);
    for (int i = 1; i <= N; i++)
    {
        std::cout << orders[i] << "\n";
    }
}