#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

int getNextPos(int current, const std::unordered_map<int, int>& ladderMap,
    const std::unordered_map<int, int>& snakeMap)
{
    std::unordered_map<int, int>::const_iterator it;

    it = ladderMap.find(current);
    if (it != ladderMap.end()) 
    {
        return it->second;
    }
    
    it = snakeMap.find(current);
    if (it != snakeMap.end()) 
    {
        return it->second;
    }

    return current;
}

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    // 방문 체크 (1 ~ 100)
    std::vector<bool> visited(101, false);
    std::unordered_map<int, int> ladderMap;
    std::unordered_map<int, int> snakeMap;
    
    // 사다리
    for (int i = 0; i < N; i++)
    {
        int in = 0;
        int out = 0;
        std::cin >> in >> out;
        
        ladderMap[in] = out;
    }
    
    // 뱀
    for (int i = 0; i < M; i++)
    {
        int in = 0;
        int out = 0;
        std::cin >> in >> out;
        
        snakeMap[in] = out;
    }
    
    std::queue<int> q;
    visited[1] = true;
    q.push(1);
    
    int count = 0;
    while (true)
    {
        if (q.empty())
        {
            break;
        }
        
        count++;
        int size = q.size();
        while (size--)
        {
            int current = q.front();
            q.pop();
            
            // 주사위 굴리기 (1 ~ 6)
            for (int i = 1; i <= 6; i++)
            {
                int next = current + i;
                if (100 < next)
                {
                    continue;
                }
                
                next = getNextPos(next, ladderMap, snakeMap);
                if (next == 100)
                {
                    std::cout << count;
                    return 0;
                }
                
                if (visited[next])
                {
                    continue;
                }
                
                visited[next] = true;
                q.push(next);
            }
        }
    }
}