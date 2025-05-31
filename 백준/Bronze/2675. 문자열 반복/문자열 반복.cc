#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    int testCaseCount = 0;
    std::cin >> testCaseCount;
    
    for (int index=0; index < testCaseCount; index++)
    {
        int count = 0;
        std::string text = "";
        std::cin >> count >> text;
        
        for (int textIndex=0; textIndex < text.length(); textIndex++)
        {
            for (int countIndex=0; countIndex < count; countIndex++)
            {
                std::cout << text[textIndex];
            }
        }
        
        std::cout << "\n";
    }
}