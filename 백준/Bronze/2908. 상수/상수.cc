#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

int main()
{
    std::string text = "";
    std::getline(std::cin, text);
    
    std::string reverse = text;
    std::reverse(reverse.begin(), reverse.end());
    
    std::istringstream iss(reverse);
    std::vector<std::string> tokens;
    std::string word;
    while (iss >> word)
    {
        tokens.push_back(word);
    }
    
    if (tokens.size() == 2)
    {
        int max = std::max(std::stoi(tokens[0]), std::stoi(tokens[1]));
        std::cout << max;
    }
}