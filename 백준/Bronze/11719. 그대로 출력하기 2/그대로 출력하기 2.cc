#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string n = "";
    while (std::getline(std::cin, n))
    {
        std::cout << n << "\n";
    }
}