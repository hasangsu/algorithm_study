#include <iostream>

int main()
{
    int size = 0;
    int scale = 0;
    std::cin >> size >> scale;
    
    int bitmap[size][size] = {0, };
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int bit = 0;
            std::cin >> bit;
            
            bitmap[i][j] = bit;
        }
    }
    
    // int upscale[size * scale][size * scale] = {0, };
    for (int i = 0; i < size; i++)
    {
        // 가로 스케일
        for (int s1 = 0; s1 < scale; s1++)
        {
            for (int j = 0; j < size; j++)
            {
                int bit = bitmap[i][j];
                
                // 세로 스케일
                for (int s2 = 0; s2 < scale; s2++)
                {
                    // upscale[i * scale + s1][j * scale + s2] = bit;
                    std::cout << bit << " ";
                }
            }
            std::cout << "\n";
        }
    }
}