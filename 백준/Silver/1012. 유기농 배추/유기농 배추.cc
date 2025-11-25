#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &visited, const std::vector<std::vector<int>> &maps, int row, int column, int &count)
{
   // 지도상에 없으면 진행하지 않는다.
    if (row < 0 ||
        column < 0 ||
        maps.size() <= row ||
        maps[row].size() <= column)
    {
        return;
    }
    
    // 0 배추 없는곳,
    // 1 배추 있는곳,
    // 배추가 아니면 진행하지 않는다.
    if (maps[row][column] == 0)
    {
        return;
    }
    
    // 이미 방문한 집이면 진행하지 않는다.
    if (visited[row][column] == true)
    {
        return;
    }
    
    // 방문 설정
    visited[row][column] = true;
    
     // 위
    {
        dfs(visited, maps, row - 1, column, count);
    }
    
    // 아래
    {
        dfs(visited, maps, row +1, column, count);
    }
    
    // 왼쪽
    {
        dfs(visited, maps, row, column - 1, count);
    }
    
    // 오른쪽
    {
        dfs(visited, maps, row, column + 1, count);
    } 
}

int main()
{
    int T = 0;
    std::cin >> T;
    
    while (T--)
    {
        int M = 0;
        int N = 0;
        int K = 0;
        std::cin >> M >> N >> K;
        
        std::vector<std::vector<int>> maps(N, std::vector<int>(M, 0));
        for (int i = 0; i < K; i++)
        {
            int x = 0;
            int y = 0;
            std::cin >> x >> y;
            
            maps[y][x] = 1;
        }
        
        std::vector<std::vector<int>> visited(N, std::vector<int>(M, 0));
        int count = 0;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j] && maps[i][j] == 1)
                {
                    dfs(visited, maps, i, j, count);
                    count++;
                }
            }
        }
        
        std::cout << count << "\n";
    }
}