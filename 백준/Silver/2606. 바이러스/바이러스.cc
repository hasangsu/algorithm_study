#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void bfs(std::vector<bool> &visited,
        const std::vector<std::vector<int>> &links, 
        int worm,
        int &count)
{
    // worm 방문
    visited[worm] = true;
    
    std::queue<int> q;
    q.push(worm);
    
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        
        for (const int n : links[c])
        {
            if (!visited[n])
            {
                // 오름차순 간선 방문
                visited[n] = true;
                count++;
                
                q.push(n);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int computer_count = 0;
    int link_count = 0;
    std::cin >> computer_count >> link_count;
    
    std::vector<std::vector<int>> links(computer_count + 1);
    std::vector<bool> visited(computer_count + 1);
    for (int i = 0; i < link_count; i++)
    {
        int s = 0;
        int n = 0;
        std::cin >> s >> n;
        
        links[s].push_back(n);
        links[n].push_back(s);
    }
    
    // 연결된 컴퓨터 오름차순 정렬
    for (int i = 1; i <= computer_count; i++)
    {
        std::sort(links[i].begin(), links[i].end());
    }
    
    // 1번 컴퓨터가 웜바이러스 걸렸을 때
    int result = 0;
    bfs(visited, links, 1, result);
    
    // 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수
    std::cout << result;
}