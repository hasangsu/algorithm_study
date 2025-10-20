#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<int>> &sudoku, int row, int column, int element)
{
    // 가로, 세로에 같은 숫자가 있으면 실패
    for (int i = 0; i < 9; i++)
    {
        if ((sudoku[row][i] == element) ||
            (sudoku[i][column] == element))
        {
            return false;
        }
    }
    
    // 3 x 3에 같은 숫자가 있으면 실패
    int square_row = (row / 3) * 3;
    int square_column = (column / 3) * 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[square_row + i][square_column + j] == element)
            {
                return false;
            }
        }
    }
    
    return true;
}

bool dfs(int n, std::vector<std::vector<int>> &sudoku)
{
    if (n == 81)
    {
        return true;
    }
    
    int row = n / 9;
    int column = n % 9;
    
    // 0 이 아니면 탐색할 필요 없음
    if (sudoku[row][column] != 0)
    {
        return dfs(n+1, sudoku);
    }
    
    for (int i = 1; i <= 9; i++)
    {
        // 숫자를 넣을 수 없음 (가로, 세로, 3x3에 이미 동일 숫자 있음)
        if (!isValid(sudoku, row, column, i))
        {
            continue;
        }
        
        // 숫자를 넣을 수 있음 (가로, 세로, 3x3에 조건 충족)
        sudoku[row][column] = i;
        
        // 다음
        if (dfs(n+1, sudoku))
        {
            return true;
        }
        
        sudoku[row][column] = 0;
    }
    
    return false;
}

std::vector<std::vector<int>> backtracking_dfs(std::vector<std::vector<int>> sudoku)
{
    dfs(0, sudoku);
    return sudoku;
}

int main()
{
    // 9 x 9 스도쿠
    std::vector<std::vector<int>> sudoku;
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> line;
        for (int j = 0; j < 9; j++)
        {
            int element = 0;
            std::cin >> element;
            
            line.push_back(element);
        }
        
        sudoku.push_back(line);
    }
    
    std::vector<std::vector<int>> result = backtracking_dfs(sudoku);
    for (const std::vector<int> &line : result)
    {
        for (const int &element : line)
        {
            std::cout << element << " ";
        }
        
        std::cout << "\n";
    }
}