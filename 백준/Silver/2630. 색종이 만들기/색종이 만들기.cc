#include <iostream>

void quadtree(int row, int stride, const int *paper, int &w, int &b)
{
    if (row == 1)
    {
        (paper[0] == 0) ? ++w : ++b;
        return;
    }
    
    int first = paper[0];
    bool isSame = true;
    for (int i = 0; i < row && isSame; i++) 
    {
        for (int j = 0; j < row; ++j) 
        {
            if (paper[i * stride + j] != first) 
            {
                isSame = false;
                break;
            }
        }
    }

    if (isSame) 
    {
        (first == 0) ? ++w : ++b;
        return;
    }
    
    int half = row / 2;
    const int *tl = paper;
    const int *tr = paper + half;
    const int *bl = paper + half * stride;
    const int *br = paper + half * stride + half;
    
    // tl
    quadtree(half, stride, tl, w, b);
    
    // tr
    quadtree(half, stride, tr, w, b);
    
    // bl
    quadtree(half, stride, bl, w, b);
    
    // br
    quadtree(half, stride, br, w, b);
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    // 색상별 색종이 갯수
    int w = 0;
    int b = 0;
    
    int paper[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int c = 0;
            std::cin >> c;
            
            paper[i][j] = c;
        }
    }
    quadtree(n, n, (int *) paper, w, b);
    
    std::cout << w << "\n" << b;
}