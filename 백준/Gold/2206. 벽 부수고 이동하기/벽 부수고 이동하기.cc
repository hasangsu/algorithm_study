#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    int map[N][M];
    int dist[N][M][2];
    std::memset(dist, -1, sizeof(dist));
    
    for (int i = 0; i < N; i++)
    {
        std::string m = "";
        std::cin >> m;
        for (int j = 0; j < m.size(); j++)
        {
            map[i][j] = m[j] - '0';
        }
    }
    
    std::queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(0, 0, 0));
    dist[0][0][0] = 1;
    
    while (!q.empty())
    {
        // 행, 열, 부수기
        std::tuple<int, int, int> current_pos = q.front();
        q.pop();
        
        int current_y = std::get<0>(current_pos);
        int current_x = std::get<1>(current_pos);
        int current_broken = std::get<2>(current_pos);
        if (current_y == N - 1 && current_x == M - 1)
        {
            std::cout << dist[current_y][current_x][current_broken];
            return 0;
        }
        
         std::tuple<int, int, int> moves[4] =
         {
             {current_y - 1, current_x, current_broken},
             {current_y + 1, current_x, current_broken},
             {current_y, current_x - 1, current_broken},
             {current_y, current_x + 1, current_broken}
         };
         
         for (int i = 0; i < 4; i++)
         {
             std::tuple<int, int, int> next_pos = moves[i];
             int next_y = std::get<0>(next_pos);
             int next_x = std::get<1>(next_pos);
             int next_broken = std::get<2>(next_pos);
             if (next_y < 0 || next_x < 0 || next_y >= N || next_x >= M)
             {
                 continue;
             }
             
             if (map[next_y][next_x] == 0)
             {
                if (dist[next_y][next_x][next_broken] == -1) 
                {
                    dist[next_y][next_x][next_broken] = dist[current_y][current_x][current_broken] + 1;
                    q.push(std::make_tuple(next_y, next_x, next_broken));
                }
             }
             else if (map[next_y][next_x] == 1 && current_broken == 0) 
             {
                if (dist[next_y][next_x][1] == -1) 
                {
                    dist[next_y][next_x][1] = dist[current_y][current_x][current_broken] + 1;
                    q.push(std::make_tuple(next_y, next_x, 1));
                }
            }
         }
    }
    
    std::cout << -1;
}