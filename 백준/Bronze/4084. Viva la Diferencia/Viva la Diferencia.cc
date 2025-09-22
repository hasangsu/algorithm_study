#include <iostream>
#include <vector>

int main()
{
    while (true)
    {
        int a;
        int b;
        int c;
        int d;
        std::cin >> a >> b >> c >> d;
        if ((a == 0) &&
            (b == 0) &&
            (c == 0) &&
            (d == 0))
        {
            break;
        }
        
        int count = 0;
        while (true)
        {
            bool isSame = (a == b) && (b == c) && (c == d);
            if (isSame)
            {
                break;
            }
            
            count++;
            
            int a_ = std::abs(a-b);
            int b_ = std::abs(b-c);
            int c_ = std::abs(c-d);
            int d_ = std::abs(d-a);
            
            a = a_;
            b = b_;
            c = c_;
            d = d_;
        }
        
        std::cout << count << "\n";
    }
}