#include <iostream>
#include <algorithm>

int main()
{
    int row = 0;
    int column = 0;
    std::cin >> row >> column;
    
    // 성 만들기
    char castle[row][column] = {'.'};
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            char status = '.';
            std::cin >> status;
            
            castle[i][j] = status;
        }
    }
    
    // 성 row 상태 확인
    int need_row = 0;
    for (int i = 0; i < row; i++)
    {
        bool isNeed = true;
        for (int j = 0; j < column; j++)
        {
            if (castle[i][j] == 'X')
            {
                isNeed = false;
                break;
            }
        }
        
        if (isNeed)
        {
            need_row++;
        }
    }
    
    // 성 column 상태 확인
    int need_column = 0;
    for (int i = 0; i < column; i++)
    {
        bool isNeed = true;
        for (int j = 0; j < row; j++)
        {
            if (castle[j][i] == 'X')
            {
                isNeed = false;
                break;
            }
        }
        
        if (isNeed)
        {
            need_column++;
        }
    }
    
    std::cout << std::max(need_row, need_column);
}