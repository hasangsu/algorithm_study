#include <iostream>
#include <vector>

void dfs(int start, int cumulativeDist, int &maxNode, int &maxDist, const std::vector<std::vector<std::pair<int, int>>> &adj, std::vector<bool> &visited)
{
    visited[start] = true;
    
    if (maxDist < cumulativeDist)
    {
        maxNode = start;
        maxDist = cumulativeDist;
    }
    
    for (const std::pair<int, int> &i : adj[start])
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
    int n = 0;
    std::cin >> n;
    
    std::vector<bool> visited(n + 1, false);
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1, std::vector<std::pair<int, int>>());
    for (int i = 0; i < n - 1; i++)
    {
        int s = 0;
        int e = 0;
        int w = 0;
        std::cin >> s >> e >> w;
        
        adj[s].push_back({e, w});
        adj[e].push_back({s, w});
    }
    
    int cumulativeDist = 0;
    int maxDist = 0;
    int maxNode = 0;
    dfs(1, cumulativeDist, maxNode, maxDist, adj, visited);
    
    cumulativeDist = 0;
    maxDist = 0;
    std::fill(visited.begin(), visited.end(), false);
    dfs(maxNode, cumulativeDist, maxNode, maxDist, adj, visited);
    
    std::cout << maxDist;
}