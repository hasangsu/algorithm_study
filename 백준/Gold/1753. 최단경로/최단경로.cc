#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main()
{
    int V = 0;
    int E = 0;
    std::cin >> V >> E;
    
    int K = 0;
    std::cin >> K;
    
    std::vector<bool> visited(V + 1, false);
    std::vector<std::vector<std::pair<int, int>>> info(V + 1);
    for (int i = 0; i < E; i++)
    {
        int s = 0;
        int e = 0;
        int w = 0;
        std::cin >> s >> e >> w;
        
        info[s].push_back({e, w});
    }
    
    std::vector<int> dist(V + 1, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int> > > pq;
    
    // 시작점
    dist[K] = 0;
    pq.push({0, K});
    
    while (!pq.empty())
    {
        std::pair<int, int> now_info = pq.top();
        pq.pop();
        
        int toDist = now_info.first;
        int current = now_info.second;
        
        // 방문
        if (visited[current]) 
        {
            continue;
        }
        visited[current] = true;
        
        for (const std::pair<int, int> next : info[current])
        {
            int next_node = next.first;
            int weight = next.second;
            
            if (dist[next_node] > toDist + weight) 
            {
                dist[next_node] = toDist + weight;
                pq.push({ dist[next_node], next_node });
            }
        }
    }
    
    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INT_MAX)
        {
            std::cout << "INF" << "\n";
        }
        else
        {
            std::cout << dist[i] << "\n";
        }
    }
}