#include <iostream>

int main()
{
    int powerStrip = 0;
    std::cin >> powerStrip;
    
    int total = 1;
    while (powerStrip--)
    {
        int hole = 0;
        std::cin >> hole;
        
        total += hole;
        total --;
    }
    
    std::cout << total;
}