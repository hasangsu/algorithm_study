#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    std::string text = "";
    std::cin >> text;
    
    int pos[26] = {0};
    std::fill(std::begin(pos), std::end(pos), -1);
    
    for (int index = 0; index < text.length(); index++)
    {
        int posIndex = static_cast<int>(text[index]) - 97;
        if (pos[posIndex] == -1)
        {
            pos[posIndex] = index;
        }
    }
    
    for (int index = 0; index < 26; index++)
    {
        std::cout << pos[index] << "\n";
    }
}