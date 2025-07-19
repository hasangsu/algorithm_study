/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

char boardWB[8][8] = {
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W'
};
	
char boardBW[8][8] = {
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
};

int main()
{
    // 전체 보드 사이즈 입력
    int boardM = 0;
    int boardN = 0;
    std::cin >> boardM >> boardN;
    
    // 보드의 각 칸의 색상 입력
    char board[boardM][boardN];
    for (int boardMIndex = 0; boardMIndex < boardM; boardMIndex++)
    {
        for (int boardNIndex = 0; boardNIndex < boardN; boardNIndex++)
        {
            char color = '\0';
            std::cin >> color;
            
            board[boardMIndex][boardNIndex] = color;
        }
    }
    
    int result = INT_MAX;
    for (int boardMIndex = 0; boardMIndex <= boardM - 8; boardMIndex++)
    {
        for (int boardNIndex = 0; boardNIndex <= boardN - 8; boardNIndex++)
        {
            // 기준점에서 가로/세로 8칸씩 생성하고
            // WB 또는 BW와 비교 필요
            int wbChange = 0;
            int bwChange = 0;
            for (int x = 0; x < 8; x++)
            {
                for (int y = 0; y < 8; y++)
                {
                    if (boardWB[x][y] != board[boardMIndex + x][boardNIndex + y])
                    {
                        wbChange++;
                    }
                    
                    if (boardBW[x][y] != board[boardMIndex + x][boardNIndex + y])
                    {
                        bwChange++;
                    }
                }
            }
            
            int changeMin = std::min(wbChange, bwChange);
            if (changeMin < result)
            {
                result = changeMin;
            }
        }
    }
    
    std::cout << result;
}