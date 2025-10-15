#include <iostream>
#include <vector>

void dfs(int n, int m, std::vector<int> &path, std::vector<int> &used, std::vector<std::vector<int>> &result)
{
    if (path.size() == m)
    {
        // 경로수집을 끝내면 결과에 추가
        result.push_back(path);
        return;
    }
    
    // 경로수집
    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 1)
        {
            // 이미 방문한 경로라면 사용하지 않기
            // 해당 문제는 같은 수를 여러 번 골라도 된다.
            // 그러므로 이 조건문은 절대 들어오지 않을것이다.
            continue;
        }
        
        // 방문했다고 설정하기 (해당 문제는 같은 수를 여러 번 골라도 된다.)
        // used[i] = 0;
        path.push_back(i);
        
        // 그다음 경로 방문 호출
        dfs(n, m, path, used, result);
        
        // 마지막 경로를 제외하고 새로운 마지막 경로 탐색하기
        path.pop_back();
        used[i] = 0;
    }
}

std::vector<std::vector<int>> backtracking_dfs(int n, int m)
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    std::vector<int> used(n + 1, 0);
    dfs(n, m, path, used, result);
    
    return result;
}

int main()
{
    // n개중 m개 중복 선택
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> result = backtracking_dfs(n, m);
    for (const std::vector<int> &element_i : result)
    {
        for (const int element_j : element_i)
        {
            std::cout << element_j << " ";
        }
        
        std::cout << "\n";
    }
}