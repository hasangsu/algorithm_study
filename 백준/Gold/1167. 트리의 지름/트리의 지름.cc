#include <iostream>
#include <vector>
#include <cstring>

void dfs(int start, int cumulativeDist, int &maxNode, int &maxDist, const std::vector<std::vector<std::pair<int, int>>> &adj, std::vector<bool> &visited)
{
    visited[start] = true;
    
    // 갱신
    if (maxDist < cumulativeDist)
    {
        maxNode = start;
        maxDist = cumulativeDist;
    }
    
    for (const std::pair<int, int> i : adj[start])
    {
        int n = i.first;
        int w = i.second;
        if (!visited[n])
        {
            dfs(n, cumulativeDist + w, maxNode, maxDist, adj, visited);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int V = 0;
    std::cin >> V;
    
    std::vector<std::vector<std::pair<int, int>>> adj(V + 1, std::vector<std::pair<int, int>>());
    std::vector<bool> visited(V + 1);
    
    for (int i = 0; i < V; i++)
    {
        int s = 0;
        std::cin >> s;
        while (true)
        {
            int e = 0;
            int w = 0;
            std::cin >> e;
            if (e == -1)
            {
                break;
            }
            std::cin >> w;
            
            adj[s].push_back({e, w});
        }
    }
    
    int cumulativeDist = 0;
    int maxDist = 0;
    int maxNode = 0;
    std::fill(visited.begin(), visited.end(), false);
    dfs(1, cumulativeDist, maxNode, maxDist, adj, visited);
    
    cumulativeDist = 0;
    maxDist = 0;
    std::fill(visited.begin(), visited.end(), false);
    dfs(maxNode, cumulativeDist, maxNode, maxDist, adj, visited);
    std::cout << maxDist;
}