#include <iostream>

struct PaperInfo
{
    // -1로만 채워진 종이의 개수
    int c1 = 0;
    // 0으로만 채워진 종이의 개수
    int c2 = 0;
    // 1로만 채워진 종이의 개수
    int c3 = 0;
    
    void update(int c)
    {
        switch (c)
        {
            case -1:
            {
                c1++;
            }
            break;
            case 0:
            {
                c2++;
            }
            break;
            case 1:
            {
                c3++;
            }
            break;
            default:
            break;
        }
    }
};

void quadtree(int length, int stride, const int *paper, PaperInfo &info)
{
    if (length == 1)
    {
        int c = paper[0];
        info.update(c);
        return;
    }
    
    int first = paper[0];
    bool isSame = true;
    for (int i = 0; i < length && isSame; i++) 
    {
        for (int j = 0; j < length; ++j) 
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
        int c = paper[0];
        info.update(c);
        return;
    }
    
    int third = length / 3;
    const int *tl = paper;
    const int *tm = paper + third;
    const int *tr = paper + (third * 2);
    
    const int *ml = paper + third * stride;
    const int *mm = paper + third * stride + third;
    const int *mr = paper + third * stride + (third * 2);
    
    const int *bl = paper + (third * 2) * stride;
    const int *bm = paper + (third * 2) * stride + third;
    const int *br = paper + (third * 2) * stride + (third * 2);
    
    // tl
    // tm
    // tr
    quadtree(third, stride, tl, info);
    quadtree(third, stride, tm, info);
    quadtree(third, stride, tr, info);
    
    // ml
    // mm
    // mr
    quadtree(third, stride, ml, info);
    quadtree(third, stride, mm, info);
    quadtree(third, stride, mr, info);
    
    // bl
    // bm
    // br
    quadtree(third, stride, bl, info);
    quadtree(third, stride, bm, info);
    quadtree(third, stride, br, info);
}

int main()
{
    int n = 0;
    std::cin >> n;
    
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
    
    PaperInfo info;
    quadtree(n, n, (int *) paper, info);
    
    std::cout << info.c1 << "\n";
    std::cout << info.c2 << "\n";
    std::cout << info.c3 << "\n";
}