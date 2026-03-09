#include <iostream>

int main()
{
    while (true)
    {
        int a = 0;
        int b = 0;
        std::cin >> a >> b;
        if (a == 0 &&
            b == 0)
        {
            break;
        }
        
        if (a <= b)
        {
            std::cout << "No" << "\n";
        }
        else
        {
            std::cout << "Yes" << "\n";
        }
    }
}