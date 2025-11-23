#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void dfs(std::vector<std::vector<bool>> &visited, const std::vector<std::vector<int>> &maps, int row, int column, int &count)
{
    // 지도상에 없으면 진행하지 않는다.
    if (row < 0 ||
        column < 0 ||
        maps.size() <= row ||
        maps.size() <= column)
    {
        return;
    }
    
    // 0 집이 없는곳,
    // 1 집이 있는곳,
    // 집이 아니면 진행하지 않는다.
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
    count++;
    
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
    int N = 0;
    std::cin >> N;
    
    std::vector<std::vector<int>> maps(N);
    for (int i = 0; i < N; i++)
    {
        std::string house = "";
        std::cin >> house;
        
        for (char c : house)
        {
            maps[i].push_back(c - '0');    
        }
    }
    
    // graph (dfs or bfs)
    {
        std::vector<std::vector<bool>> visited(N, std::vector<bool>(N, false));
        std::vector<int> complexs;
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (!visited[i][j] && maps[i][j] == 1)
                {
                    int count = 0;
                    dfs(visited, maps, i, j, count);
                    complexs.push_back(count);
                }
                
            }
        }

        std::sort(complexs.begin(), complexs.end());
        
        std::cout << complexs.size() << "\n";
        for (const int c : complexs)
        {
            std::cout << c << "\n";
        }
    }
}