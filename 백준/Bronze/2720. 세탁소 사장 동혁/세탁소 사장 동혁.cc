#include <iostream>

int main()
{
    int quater = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    int testcase = 0;
    std::cin >> testcase;
    
    for (int index = 0; index < testcase; index++)
    {
        int change = 0;
        std::cin >> change;
        
        int quaterCount = change / quater;
        change = change - (quater * quaterCount);
        
        int dimeCount = change / dime;
        change = change - (dime * dimeCount);
        
        int nickelCount = change / nickel;
        change = change - (nickel * nickelCount);
        
        int pennyCount = change / penny;
        change = change - (penny * pennyCount);
        
        std::cout << quaterCount << " " << dimeCount << " " << nickelCount << " " << pennyCount << "\n";
    }
}