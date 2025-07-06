#include <iostream>
#include <algorithm>

std::string getTypeOfTriangle(int line1, int line2, int line3)
{
    std::string result = "";
    int longestSide = std::max({line1, line2, line3});
    int othersSide = (line1 + line2 + line3) - longestSide;
    if (othersSide <= longestSide)
    {
        // 세 변의 길이가 삼각형의 조건을 만족하지 못하는 경우
        result = "Invalid";
    }
    else if ((line1 == line2) &&
            (line2 == line3))
    {
        // 세 변의 길이가 모두 같은 경우
        result = "Equilateral";
    }
    else if ((line1 == line2) ||
            (line1 == line3) ||
            (line2 == line3))
    {
        // 두 변의 길이만 같은 경우
        result = "Isosceles";
    }
    else
    {
        // 세 변의 길이가 모두 다른 경우
        result = "Scalene";
    }
    
    return result;
}

int main()
{
    while (true)
    {
        int line1 = 0;
        int line2 = 0;
        int line3 = 0;
        std::cin >> line1 >> line2 >> line3;
        if ((line1 == 0) &&
            (line2 == 0) &&
            (line3 == 0))
        {
            break;
        }
        
        std::string result = getTypeOfTriangle(line1, line2, line3);
        std::cout << result << "\n";
    }
}