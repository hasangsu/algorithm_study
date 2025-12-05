#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int testcase = 0;
    std::cin >> testcase;
    
    while (testcase--)
    {
        // 팀의 수
        int n = 0;
        std::cin >> n;
        
        // 작년에 n등한 팀
        std::vector<int> previousRank(n, 0);
        for (int i = 0; i < n; i++)
        {
            int rank = 0;
            std::cin >> rank;
            
            previousRank[i] = rank;
        }
        
        // 작년 n등 기준으로 간선 생성
        std::vector<std::vector<bool>> adj(n + 1, std::vector<bool>(n + 1, false));
        std::vector<int> indegree(n + 1, 0);
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                int higher = previousRank[i];
                int lower  = previousRank[j];
                if (!adj[higher][lower]) 
                {
                    adj[higher][lower] = true;
                    indegree[lower]++;
                }
            }
        }
        
        // 상대적 등수 변경
        int m = 0;
        std::cin >> m;
        while (m--) 
        {
            int a = 0;
            int b = 0;
            std::cin >> a >> b;

            if (adj[a][b]) 
            {
                adj[a][b] = false;
                indegree[b]--;
                adj[b][a] = true;
                indegree[a]++;
            } 
            else 
            {
                adj[b][a] = false;
                indegree[a]--;
                adj[a][b] = true;
                indegree[b]++;
            }
        }
        
        std::queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        int count = 0;
        bool isMultiRank = false;
        std::vector<int> result;
        while (!q.empty())
        {
            if (2 <= q.size())
            {
                // 순위가 여러개 나올 수 있으므로 확실한 순위를 정하기 어렵다.
                isMultiRank = true;
                break;
            }
            
            int t = q.front();
            q.pop();
            
            count++;
            result.push_back(t);
            
            // 간선 확인
            for (int next = 1; next <= n; next++)
            {
                if (adj[t][next])
                {
                    indegree[next]--;
                    if (indegree[next] == 0)
                    {
                        q.push(next);
                    }
                }
            }
        }
        
        if (isMultiRank)
        {
            std::cout << "?" << "\n";
        }
        else if (count != n)
        {
            std::cout << "IMPOSSIBLE" << "\n";
        }
        else
        {
            // 최종 순위
            for (int i : result)
            {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
    }
}