#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void dfs(std::vector<bool> &visited, const std::vector<std::vector<int>> &Ms, int p, std::vector<int> &orders)
{
    if (visited[p])
    {
        return;
    }
    
    visited[p] = true;
    orders.push_back(p);
    
    for (int m : Ms[p])
    {
        if (visited[m])
        {
            continue;
        }
        
        dfs(visited, Ms, m, orders);
    }
}

void bfs(std::vector<bool> &visited, const std::vector<std::vector<int>> &Ms, int p, std::vector<int> &orders)
{
    if (visited[p])
    {
        return;
    }
    
    visited[p] = true;
    orders.push_back(p);
    
    std::queue<int> q;
    q.push(p);
    
    while (!q.empty())
    {
        int t_p = q.front();
        q.pop();
        
        for (int m : Ms[t_p])
        {
            if (visited[m])
            {
                continue;
            }
            
            visited[m] = true;
            q.push(m);
            orders.push_back(m);
        }
    }
}

int main()
{
    int N = 0;
    int M = 0;
    int V = 0;
    std::cin >> N >> M >> V;
    
    std::vector<int> Ns(N + 1);
    std::vector<std::vector<int>> Ms(N + 1);
    for (int i = 0; i < M; i++)
    {
        int l1 = 0;
        int l2 = 0;
        std::cin >> l1 >> l2;
        
        Ms[l1].push_back(l2);
        Ms[l2].push_back(l1);
    }
    
    for (int i = 1; i <= N; i++)
    {
        std::sort(Ms[i].begin(), Ms[i].end());
    }
    
    // dfs
    {
        std::vector<bool> visited(N + 1);
        std::vector<int> orders;
        dfs(visited, Ms, V, orders);
        
        for (int o : orders)
        {
            std::cout << o << " ";
        }
    }
    
    std::cout << "\n";
    
    // bfs
    {
        std::vector<bool> visited(N + 1);
        std::vector<int> orders;
        bfs(visited, Ms, V, orders);
        
        for (int o : orders)
        {
            std::cout << o << " ";
        }
    }
}