#include <iostream>
#include <algorithm>

int main()
{
    int line1 = 0;
    int line2 = 0;
    int line3 = 0;
    std::cin >> line1 >> line2 >> line3;
    
    int result = line1 + line2 + line3;
    int maxLine = std::max({line1, line2, line3});
    if (!(maxLine < (line1  + line2 + line3 - maxLine)))
    {
        result -= maxLine;
        
        maxLine = (line1  + line2 + line3 - maxLine - 1);
        result += maxLine;
    }
    
    std::cout << result;
}