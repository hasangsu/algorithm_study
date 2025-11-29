#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int M = 0;
    int N = 0;
    std::cin >> M >> N;
    
    std::queue<std::pair<int, int>> q;
    int status[N][M];
    std::fill(&status[0][0], &status[0][0] + N*M, 0);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int s = 0;
            std::cin >> s;
            
            status[i][j] = s;
            if (status[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
    
    int day = -1;
    while (true)
    {
        if (q.empty())
        {
            break;
        }
        
        day++;
        int size = q.size();
        while (size--)
        {
            std::pair<int, int> current_pos = q.front();
            q.pop();
            
            int current_x = current_pos.first;
            int current_y = current_pos.second;
            std::pair<int, int> moves[4] = 
            {
                {current_x - 1, current_y},
                {current_x + 1, current_y},
                {current_x, current_y - 1},
                {current_x, current_y + 1}
            };
            
            for (int i = 0; i < 4; i++)
            {
                std::pair<int, int> next_pos = moves[i];
                int next_x = next_pos.first;
                int next_y = next_pos.second;
                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M)
                {
                    continue;
                }

                if (0 <= next_x && 0 <= next_y &&
                    next_x < N && next_y < M &&
                    status[next_x][next_y] == 0)
                {
                    status[next_x][next_y] = 1;
                    q.push({next_x, next_y});
                }
            }
        }
    }
    
    bool isAllRipen = true;
    for (int i = 0; i < N && isAllRipen; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            if (status[i][j] == 0) 
            {
                isAllRipen = false;
                break;
            }
        }
    }
    
    if (!isAllRipen)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << day;
    }
}