#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

std::vector<int> dijkstra(const std::vector<std::vector<std::pair<int, int>>> &infos, int count, int start)
{
    std::vector<int> dist(count + 1, INT_MAX);
    
    // pq first : 현재까지 거리(비용)
    // pq second : 현재 노드
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int> > > pq;
    
    // 시작노드 설정
    dist[start] = 0;
    pq.push({0, start});
    
    // 탐색
    while (!pq.empty())
    {
        std::pair<int, int> status = pq.top();
        pq.pop();
        
        int cost = status.first;
        int now = status.second;
        if (cost > dist[now])
        {
            continue;
        }
        
        for (std::pair<int, int> info : infos[now])
        {
            // info first : 연결된 노드
            // info second : 연결된 노드의 가중치
            int next = info.first;
            int weight = info.second;
            if (dist[next] > cost + weight)
            {
                dist[next] = cost + weight;
                pq.push({dist[next], next});
            }
        }
    }
    
    return dist;
}

int main()
{
    int T = 0;
    std::cin >> T;
    while (T--)
    {
        // n, m, t는 다음과 같다.
        // n : 노드
        // m : 간선
        // t : 목표 노드
        int n = 0;
        int m = 0;
        int t = 0;
        std::cin >> n >> m >> t;
        
        // s, g, h는 다음과 같다.
        // s : 시작 노드
        // g : 필수 방문 노드
        // h : 필수 방문 노드
        int s = 0;
        int g = 0;
        int h = 0;
        std::cin >> s >> g >> h;
        
        // pair<int, int>는 다음과 같다.
        // first : 연결된 노드
        // second : 가중치
        int ghLen = 0;
        std::vector<std::vector<std::pair<int, int>>> infos(n + 1);
        for (int i = 0; i < m; i++)
        {
            int s = 0;
            int e = 0;
            int w = 0;
            std::cin >> s >> e >> w;
            
            infos[s].push_back({e, w});
            infos[e].push_back({s, w});
            
            if ((s == g && e == h) || (s == h && e == g)) 
            {
                ghLen = w;
            }
        }
        
        std::vector<int> goalNodes(t);
        for (int i = 0; i < t; i++)
        {
            int n = 0;
            std::cin >> n;
            
            goalNodes[i] = n;
        }
        
        std::sort(goalNodes.begin(), goalNodes.end());
        
        std::vector<int> distS = dijkstra(infos, n, s);
        std::vector<int> distG = dijkstra(infos, n, g);
        std::vector<int> distH = dijkstra(infos, n, h);
        
        for (int x : goalNodes) 
        {
            int normal = distS[x];

            // (s부터 g까지) + (g부터 h까지) + (h부터 x까지)
            // (s부터 h까지) + (h부터 g까지) + (g부터 x까지)
            long long gh = std::min((long long)distS[g] + ghLen + distH[x], (long long)distS[h] + ghLen + distG[x]);

            if (normal != INT_MAX && (long long)normal == gh) 
            {
                std::cout << x << ' ';
            }
        }
    }
}