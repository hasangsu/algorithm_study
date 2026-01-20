/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int table[20][200001];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int m = 0;
    std::cin >> m;
    
    for (int i = 1; i <= m; i++) 
    {
        std::cin >> table[0][i];
    }
    
    // 희소배열 ...
    for (int k = 1; k < 20; k++) 
    {
        for (int i = 1; i <= m; i++) 
        {
            int mid = table[k - 1][i];
            table[k][i] = table[k - 1][mid];
        }
    }
    
    int Q = 0;
    std::cin >> Q;
    
    for (int i = 0; i < Q; i++)
    {
        int n = 0;
        int x = 0;
        std::cin >> n >> x;
        
        for (int k = 0; k < 20; k++) 
        {
            if (n & (1 << k)) 
            {
                x = table[k][x];
            }
        }
        
        std::cout << x << "\n";
    }
}