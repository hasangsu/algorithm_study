#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main()
{
    int M = 0;
    int N = 0;
    int H = 0;
    std::cin >> M >> N >> H;
    
    // 높이, 세로, 가로
    std::queue<std::tuple<int, int, int>> q;
    int status[H][N][M];
    std::fill(&status[0][0][0], &status[0][0][0] + H*N*M, 0);
    for (int i = 0; i < H; i++ )
    {
        for (int j = 0; j < N; j++)
        {
            for (int l = 0; l < M; l++)
            {
                int s = 0;
                std::cin >> s;
                
                status[i][j][l] = s;
                if (status[i][j][l] == 1)
                {
                    q.push(std::make_tuple(i, j, l));
                }
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
            std::tuple<int, int, int> current_pos = q.front();
            q.pop();
            
            int current_h = std::get<0>(current_pos);
            int current_x = std::get<1>(current_pos);
            int current_y = std::get<2>(current_pos);
            std::tuple<int, int, int> moves[6] = 
            {
                {current_h - 1, current_x, current_y},
                {current_h + 1, current_x, current_y},
                {current_h, current_x - 1, current_y},
                {current_h, current_x + 1, current_y},
                {current_h, current_x, current_y - 1},
                {current_h, current_x, current_y + 1}
            };
            
            for (int i = 0; i < 6; i++)
            {
                std::tuple<int, int, int> next_pos = moves[i];
                int next_h = std::get<0>(next_pos);
                int next_x = std::get<1>(next_pos);
                int next_y = std::get<2>(next_pos);
                if (next_h < 0 || next_x < 0 || next_y < 0 || 
                    next_h >= H || next_x >= N || next_y >= M)
                {
                    continue;
                }

                if (0 <= next_h && 0 <= next_x && 0 <= next_y &&
                    next_h < H && next_x < N && next_y < M &&
                    status[next_h][next_x][next_y] == 0)
                {
                    status[next_h][next_x][next_y] = 1;
                    q.push(std::make_tuple(next_h, next_x, next_y));
                }
            }
        }
    }
    
    bool isAllRipen = true;
    for (int i = 0; i < H && isAllRipen; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            for (int l = 0; l < M; l++) 
            {
                if (status[i][j][l] == 0) 
                {
                    isAllRipen = false;
                    break;
                }
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