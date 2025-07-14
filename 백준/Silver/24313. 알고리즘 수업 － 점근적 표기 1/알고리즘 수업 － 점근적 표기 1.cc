#include <iostream>

int main()
{
    int a1 = 0;
    int a0 = 0;
    int c = 0;
    int n0 = 0;
    std::cin >> a1 >> a0 >> c >> n0;
    
    bool result = (a1 <= c) && ((a1 - c) * n0 + a0 <= 0);
    std::cout << (result ? 1 : 0);
}