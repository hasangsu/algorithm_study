#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, int> valueMap;
    std::unordered_map<std::string, int> multiplicationMap;
    
    // 값 맵 생성
    valueMap["black"] = 0;
    valueMap["brown"] = 1;
    valueMap["red"] = 2;
    valueMap["orange"] = 3;
    valueMap["yellow"] = 4;
    valueMap["green"] = 5;
    valueMap["blue"] = 6;
    valueMap["violet"] = 7;
    valueMap["grey"] = 8;
    valueMap["white"] = 9;
    
    // 저항 맵 생성
    multiplicationMap["black"] = 1;
    multiplicationMap["brown"] = 10;
    multiplicationMap["red"] = 100;
    multiplicationMap["orange"] = 1000;
    multiplicationMap["yellow"] = 10000;
    multiplicationMap["green"] = 100000;
    multiplicationMap["blue"] = 1000000;
    multiplicationMap["violet"] = 10000000;
    multiplicationMap["grey"] = 100000000;
    multiplicationMap["white"] = 1000000000;

    long long value = 0;
    for (int i=0; i < 2; i++)
    {
        std::string color = "";
        std::cin >> color;
        
        if (i==0)
        {
            // 처음
            value += valueMap[color] * 10;
        }
        else
        {
            // 마지막
            value += valueMap[color];
        }
    }
    
    // 곱해야하는 색상
    std::string lastColor = "";
    std::cin >> lastColor;
    long long result = value * multiplicationMap[lastColor];
    
    std::cout << result;
}