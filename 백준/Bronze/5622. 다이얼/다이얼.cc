#include <stdio.h>
#include <string>
#include <iostream>
#include <map>

int main()
{
    // 다이얼 맵
    std::map<char, int> dialMap;
    dialMap['A'] = 2;
    dialMap['B'] = 2;
    dialMap['C'] = 2;
    dialMap['D'] = 3;
    dialMap['E'] = 3;
    dialMap['F'] = 3;
    dialMap['G'] = 4;
    dialMap['H'] = 4;
    dialMap['I'] = 4;
    dialMap['J'] = 5;
    dialMap['K'] = 5;
    dialMap['L'] = 5;
    dialMap['M'] = 6;
    dialMap['N'] = 6;
    dialMap['O'] = 6;
    dialMap['P'] = 7;
    dialMap['Q'] = 7;
    dialMap['R'] = 7;
    dialMap['S'] = 7;
    dialMap['T'] = 8;
    dialMap['U'] = 8;
    dialMap['V'] = 8;
    dialMap['W'] = 9;
    dialMap['X'] = 9;
    dialMap['Y'] = 9;
    dialMap['Z'] = 9;
    
    std::string text = "";
    std::cin >> text;
    
    int sum = text.length();
    for (int index=0; index < text.length(); index++)
    {
        sum += dialMap[text[index]];
    }
    
    std::cout << sum;
}