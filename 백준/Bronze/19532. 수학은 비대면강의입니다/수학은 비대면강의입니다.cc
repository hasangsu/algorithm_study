#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    std::cin >> a >> b >> c >> d >> e >> f;
    
    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            // 방정식1과 방정식2 모두 일치
            bool isEquation1 = ((a * x) + (b * y) == c) ? true : false;
            bool isEquation2 = ((d * x) + (e * y) == f) ? true : false;
            if (isEquation1 && isEquation2)
            {
                std::cout << x << " " << y;
            }
        }
    }
}