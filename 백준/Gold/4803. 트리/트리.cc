#include <iostream>
#include <vector>

void dfs(int current, int prev, const std::vector<std::vector<int>> &adj, std::vector<bool> &visited, bool &isTree)
{
    visited[current] = true;
    
    for (const int next : adj[current])
    {
        if (next == prev)
        {
            continue;
        }
        
        if (visited[next])
        {
            isTree = false;
        }
        else
        {
            dfs(next, current, adj, visited, isTree);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<std::vector<int>> adj;
    std::vector<bool> visited;
    bool isTree;
    
    int testcase = 1;
    while (true)
    {
        int n = 0;
        int m = 0;
        std::cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        
        adj.assign(n + 1, std::vector<int>());
        visited.assign(n + 1, false);
        for (int i = 0; i < m; i++) 
        {
            int s;
            int e;
            std::cin >> s >> e;
            adj[s].push_back(e);
            adj[e].push_back(s);
        }

        int count = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (!visited[i])
            {
                isTree = true;
                dfs(i, 0, adj, visited, isTree);
                
                if (isTree) 
                {
                    count++;
                }
            }
        }
        
        std::cout << "Case " << testcase << ": ";
        if (count == 0) 
        {
            std::cout << "No trees." << "\n";
        } 
        else if (count == 1) 
        {
            std::cout << "There is one tree." << "\n";
        } 
        else 
        {
            std::cout << "A forest of " << count << " trees." << "\n";
        }

        testcase++;
    }
}