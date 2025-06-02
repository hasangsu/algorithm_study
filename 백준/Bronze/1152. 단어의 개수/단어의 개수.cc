#include <stdio.h>
#include <string>
#include <iostream>
#include <iostream>
#include <sstream>
#include <vector>

int main()
{
    std::string text = "";
    std::getline(std::cin, text);
    
    std::istringstream iss(text);
    std::vector<std::string> tokens;
    std::string word;
    while (iss >> word)
    {
        tokens.push_back(word);
    }
    
    std::cout << tokens.size() << "\n";
}