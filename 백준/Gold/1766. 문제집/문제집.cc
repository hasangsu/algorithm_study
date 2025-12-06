#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> l(N + 1);
    std::vector<int> indegree(N + 1);
    for (int i = 0; i < M; i++)
    {
        // s : 먼저 풀어야하는 문제
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        // 간선 리스트
        l[s].push_back(e);
        
        // 진입차수
        indegree[e]++;
    }
    
    // 진입차수가 0인 문제를 찾아서 시작큐만들기
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    
    while (!q.empty())
    {
        int problems = q.top();
        q.pop();
        
        std::cout << problems << " ";
    
        for (int next : l[problems]) 
        {
            indegree[next]--;
            if (indegree[next] == 0) 
            {
                q.push(next);
            }
        }
    }
}