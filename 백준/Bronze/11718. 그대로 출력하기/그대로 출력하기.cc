#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
    std::string text = "";
    while (std::getline(std::cin, text))
    {
        std::cout << text << "\n";
    }
}