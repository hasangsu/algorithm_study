#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
    std::string text;
    int index = 0;
    std::cin >> text >> index;
    
    std::cout << text[index - 1];
}