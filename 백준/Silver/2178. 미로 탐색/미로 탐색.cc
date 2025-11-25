#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    std::vector<std::vector<int>> mazes(N, std::vector<int>(M, 0));
    
    for (int i = 0; i < N; i++)
    {
        std::string maze = "";
        std::cin >> maze;
        
        for (int j = 0; j < maze.size(); j++)
        {
            mazes[i][j] = (maze[j] - '0');
        }
    }
    
    std::vector<std::vector<int>> dist(N, std::vector<int>(M, 0));
    std::queue<std::pair<int, int>> q;
    
    // 방향
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    // 미로의 시작점
    q.push({0, 0});
    dist[0][0] = 1;
    
    // 미로 탐색
    while (!q.empty())
    {
        std::pair<int, int> d = q.front();
        q.pop();
        
        int x = d.first;
        int y = d.second;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) 
            {
                continue;
            }
            
            // 벽이면 패스
            if (mazes[nx][ny] == 0)
            {
                continue;
            }
            
            // 이미 방문했으면 패스
            if (dist[nx][ny] != 0) 
            {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    std::cout << dist[N - 1][M - 1];
}