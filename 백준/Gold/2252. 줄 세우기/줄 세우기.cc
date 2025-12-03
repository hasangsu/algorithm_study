#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    // 간선
    std::vector<std::vector<int>> l(N + 1);
    // 진입차수
    std::vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        l[s].push_back(e);
        indegree[e]++;
    }
    
    std::queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        
        // 정렬 출력
        std::cout << t << " ";
        
        // 간선 확인
        for (int next : l[t])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
}