#include <stdio.h>
#include <string>
#include <iostream>

int main()
{
    int count = 0;
    std::string text = "";
    std::cin >> count >> text;
    
    int sum = 0;
    for (int index=0; index < count; index++)
    {
        sum += (text[index] - '0');
    }
    
    std::cout << sum << "\n";
}