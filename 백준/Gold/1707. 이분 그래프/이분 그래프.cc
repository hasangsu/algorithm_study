#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int K = 0;
    std::cin >> K;
    
    while (K--)
    {
        int V = 0;
        int E = 0;
        std::cin >> V >> E;
        
        // 간선 지정
        std::vector<std::vector<int>> l(V + 1);
        for (int i = 1; i <= E; i++)
        {
            int s = 0;
            int e = 0;
            std::cin >> s >> e;
            
            l[s].push_back(e);
            l[e].push_back(s);
        }
        
        // 색상 지정
        // 0 : 미지정
        // 1 : 빨강
        // 2 : 파랑
        std::vector<int> color(V + 1, 0); 

        bool result = true;
        for (int i = 1; i <= V && result; i++)
        {
            if (color[i] != 0)
            {
                continue;
            }
            
            // bfs queue
            std::queue<int> q;
            q.push(i);
            color[i] = 1;
            
            while (!q.empty() && result)
            {
                // 현재 정점
                int c = q.front();
                q.pop();
                
                for (int c_l : l[c])
                {
                    // 간선 색상 확인 (미지정, 미방문)
                    if (color[c_l] == 0)
                    {
                        color[c_l] = color[c] == 1 ? 2 : 1;
                        q.push(c_l);
                    }
                    else
                    {
                        // 간선의 색상이 나와 같으면?
                        if (color[c] == color[c_l])
                        {
                            result = false;
                            break;
                        }
                    }
                }
            }
        }
                
        result == true ? std::cout << "YES" << "\n"
                       : std::cout << "NO" << "\n";
    }
}