#include <iostream>

long long combination(int east, int west) 
{
    if (west > east - west)
    {
        west = east - west;
    }
    
    long long result = 1;
    for (int i = 1; i <= west; i++) {
        result = result * (east - west + i) / i;
    }
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    // east C west
    int west = 0;
    int east = 0;
    while (count--)
    {
        std::cin >> west >> east;
        long long result = combination(east, west);
        std::cout << result << "\n";
    }
}