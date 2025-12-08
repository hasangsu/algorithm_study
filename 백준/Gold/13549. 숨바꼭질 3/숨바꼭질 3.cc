#include <iostream>
#include <queue>
#include <vector>
#include <climits>

int main()
{
    int N = 0;
    int K = 0;
    std::cin >> N >> K;
    
    int size = 100000;
    std::vector<int> dist(size + 1, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    
    // 시작점은 N번 칸
    // N번칸에서 N번칸까지의 거리는 0
    dist[N] = 0;
    pq.push({0, N});
    
    while (!pq.empty())
    {
        std::pair<int, int> next = pq.top();
        pq.pop();
        
        // cost : 누적 비용
        // node : 현재 노드
        int cost = next.first;
        int node = next.second;
        
        // 목적지에 도착했는지?
        if (node == K)
        {
            break;
        }
        
        // 이미 더 짧은 경로로 도착했는지?
        if (dist[node] < cost)
        {
            continue;
        }
        
        // 순간이동 : 가중치 0
        int next_node = node * 2;
        if (0 <= next_node && next_node <= size)
        {
            int next_cost = cost;
            if (next_cost < dist[next_node])
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
        
        // 뒤로 걷기 : 가중치 1
        next_node = node - 1;
        if (0 <= next_node && next_node <= size)
        {
            int next_cost = cost + 1;
            if (next_cost < dist[next_node])
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
        
        // 앞으로 걷기 : 가중치 1
        next_node = node + 1;
        if (0 <= next_node && next_node <= size)
        {
            int next_cost = cost + 1;
            if (next_cost < dist[next_node])
            {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    
    std::cout << dist[K];
}