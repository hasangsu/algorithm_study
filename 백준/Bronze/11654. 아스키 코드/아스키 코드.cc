#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
    char text;
    std::cin >> text;
    std::cout << static_cast<int>(text) << "\n";
}