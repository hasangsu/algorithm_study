#include <iostream>
#include <vector>

void dfs(int node, const std::vector<std::vector<int>> &nodes, std::vector<bool> &visited)
{
    visited[node] = true;
    
    for (int e : nodes[node])
    {
        if (!visited[e])
        {
            dfs(e, nodes, visited);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 정점 갯수
    int N = 0;
    // 노드 갯수
    int M = 0;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> nodes(N + 1, std::vector<int>());
    for (int i = 1; i <= M; i++)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        nodes[s].push_back(e);
        nodes[e].push_back(s);
    }
    
    // 방문 체크
    std::vector<bool> visited(N + 1, false);
    // 연결 요소 갯수
    int count = 0;
    // 1번 노드부터 순서대로 연결 요소 체크
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            count++;
            dfs(i, nodes, visited);
        }
    }
    
    std::cout << count;
}