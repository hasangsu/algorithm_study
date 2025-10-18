#include <iostream>
#include <vector>

void dfs(int n, std::vector<int> &path, std::vector<std::vector<int>> &result)
{
    if (path.size() == n)
    {
        // 경로수집을 끝내면 결과에 추가
        result.push_back(path);
        return;
    }
    
    int row = path.size();
    
    // 경로수집
    for (int column = 1; column <= n; column++)
    {
        bool safe = true;
        
        for (int row_prev = 0; row_prev < row; row_prev++)
        {
            int column_prev = path[row_prev];
            if (column_prev == column || std::abs(column_prev - column) == std::abs(row_prev - row))
            {
                safe = false;
                break;
            }
        }
        
        if (!safe)
        {
            continue;
        }
        
        path.push_back(column);
        dfs(n, path, result);
        path.pop_back();
    }
}

std::vector<std::vector<int>> backtracking_dfs(int n)
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    dfs(n, path, result);
    
    return result;
}

int main()
{
    // n x n 체스판에서 n개의 퀸 정렬
    int n = 0;
    std::cin >> n;
    
    std::vector<std::vector<int>> result = backtracking_dfs(n);
    
    int count = result.size();
    std::cout << count;
}