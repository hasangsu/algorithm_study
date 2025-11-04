#include <iostream>

void quadtree(int length, int stride, const int *data, std::string &compression)
{
    if (length == 1)
    {
        (data[0] == '0') ? compression.push_back('0')
                        : compression.push_back('1');
        return;
    }
    
    int first = data[0];
    bool isSame = true;
    for (int i = 0; i < length && isSame; i++) 
    {
        for (int j = 0; j < length; ++j) 
        {
            if (data[i * stride + j] != first) 
            {
                isSame = false;
                break;
            }
        }
    }

    
    if (isSame) 
    {
        (first == '0') ? compression.push_back('0')
                        : compression.push_back('1');
    }
    else
    {
        int half = length / 2;
        const int *tl = data;
        const int *tr = data + half;
        const int *bl = data + half * stride;
        const int *br = data + half * stride + half;
        
        compression.push_back('(');
        
        // tl
        quadtree(half, stride, tl, compression);
        
        // tr
        quadtree(half, stride, tr, compression);
        
        // bl
        quadtree(half, stride, bl, compression);
        
        // br
        quadtree(half, stride, br, compression);
        
        compression.push_back(')');
    }
    
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    int data[n][n];
    for (int i = 0; i < n; i++)
    {
        std::string s = "";
        std::cin >> s;
        
        int size = s.length();
        if (n != size)
        {
            return 0;
        }
        
        for (int j = 0; j < n; j++)
        {
            data[i][j] = s[j];
        }
    }
    
    std::string compression = "";
    quadtree(n, n, (int *) data, compression);
    
    std::cout << compression;
}