#include <iostream>
#include <queue>

int main()
{
    int T = 0;
    std::cin >> T;
    
    int I = 0;
    int current_x = 0;
    int current_y = 0;
    int target_x = 0;
    int target_y = 0;
    while (T--)
    {
        std::cin >> I >> current_x >> current_y >> target_x >> target_y;
        
        int visited[I][I];
        std::fill(&visited[0][0], &visited[0][0] + I * I, -1);
        visited[current_x][current_y] = 0;
        
        std::queue<std::pair<int, int>> q;
        q.push({current_x, current_y});
        
        while (!q.empty())
        {
            std::pair<int, int> current_pos = q.front();
            q.pop();
            int current_x = current_pos.first;
            int current_y = current_pos.second;
            
            std::pair<int, int> moves[8] 
            {
                {current_x - 2, current_y - 1},
                {current_x - 1, current_y - 2},
                {current_x + 1, current_y - 2},
                {current_x + 2, current_y - 1},
                {current_x + 2, current_y + 1},
                {current_x + 1, current_y + 2},
                {current_x - 1, current_y + 2},
                {current_x - 2, current_y + 1}
            };
            
            for (int i = 0; i < 8; i++)
            {
                std::pair<int, int> next_pos = moves[i];
                int next_x = next_pos.first;
                int next_y = next_pos.second;

                if (0 <= next_x && 0 <= next_y &&
                    next_x < I && next_y < I &&
                    visited[next_x][next_y] == -1)
                {
                    visited[next_x][next_y] = visited[current_x][current_y] + 1;
                    q.push({next_x, next_y});
                }
            }
        }
        
        std::cout << visited[target_x][target_y] << "\n";
    }
}