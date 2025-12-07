#include <iostream>
#include <vector>
#include <queue>
#include <climits>

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
    int N = 0;
    int E = 0;
    std::cin >> N >> E;
    
    std::vector<std::vector<std::pair<int, int>>> infos(N + 1);
    for (int i = 0; i < E; i++)
    {
        int s = 0;
        int e = 0;
        int w = 0;
        std::cin >> s >> e >> w;
        
        infos[s].push_back({e, w});
        infos[e].push_back({s, w});
    }
    
    std::vector<int> optionalNodes(2, 0);
    for (int i = 0; i < 2; i++)
    {
        int n = 0;
        std::cin >> n;
        
        optionalNodes[i] = n;
    }
    
    // 거리
    std::vector<int> distNode1 = dijkstra(infos, N, 1);
    std::vector<int> distNodeOptional1 = dijkstra(infos, N, optionalNodes[0]);
    std::vector<int> distNodeOptional2 = dijkstra(infos, N, optionalNodes[1]);
    
    int path1 = INT_MAX;
    int path2 = INT_MAX;
    if (distNode1[optionalNodes[0]] < INT_MAX &&
        distNodeOptional1[optionalNodes[1]] < INT_MAX &&
        distNodeOptional2[N] < INT_MAX)
    {
        path1 = distNode1[optionalNodes[0]] + distNodeOptional1[optionalNodes[1]] + distNodeOptional2[N];    
    }
    
    if (distNode1[optionalNodes[1]] < INT_MAX &&
        distNodeOptional2[optionalNodes[0]] < INT_MAX &&
        distNodeOptional1[N] < INT_MAX)
    {
        path2 = distNode1[optionalNodes[1]] + distNodeOptional2[optionalNodes[0]] + distNodeOptional1[N];
    }
    
    int min = std::min(path1, path2);
    
    //
    if (INT_MAX <= min)
    {
        std::cout << "-1";
    }
    else
    {
        std::cout << min;    
    }
}