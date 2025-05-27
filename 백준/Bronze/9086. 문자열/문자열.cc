#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    for (int index = 0; index < count; index++)
    {
        std::string text = "";
        std::cin >> text;
        std::cout << text[0] << text[text.length() - 1] << "\n";
    }
}