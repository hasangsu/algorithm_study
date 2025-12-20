#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    std::vector<std::vector<int>> adj(N + 1, std::vector<int>());
    std::vector<bool> visited(N + 1, false);
    std::vector<int> p(N + 1);
    
    for (int i = 0; i < N - 1; i++)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    std::queue<int> q;
    q.push(1);
    visited[1] = true;
    
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        
        for (int c_ : adj[c])
        {
            if (!visited[c_])
            {
                q.push(c_);
                visited[c_] = true;
                p[c_] = c;
            }
        }
    }
    
    for (int i = 2; i <= N; i++)
    {
        std::cout << p[i] << "\n";
    }
}