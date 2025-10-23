#include <iostream>

int m[21][21][21] = {0, };

int w(int a, int b, int c)
{
    if ((a <= 0) ||
        (b <= 0) ||
        (c <= 0))
    {
        return 1;
    }
    else if ((20 < a) ||
            (20 < b) ||
            (20 < c))
    {
        return w(20, 20, 20);
    }
    else if (m[a][b][c] != 0)
    {
        return m[a][b][c];
    }
    else if ((a < b) &&
            (b < c))
    {
        m[a][b][c] = w(a, b, c - 1) + w (a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else
    {
        m[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }
    
    return m[a][b][c]; 
}

int main()
{
    while (true)
    {
        int a = 0;
        int b = 0;
        int c = 0;
        std::cin >> a >> b >> c;
        
        if ((a == -1) &&
            (b == -1) &&
            (c == -1))
        {
            break;
        }
        
        int result = w(a, b, c);
        std::cout << "w(" << a << ", "
                          << b << ", "
                          << c << ") = "
                          << result
                          << "\n";
    }
}