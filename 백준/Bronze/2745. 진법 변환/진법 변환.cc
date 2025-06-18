#include <iostream>
#include <cctype>

int main()
{
    std::string number = "";
    int base = 0;
    std::cin >> number >> base;
    
    int decimal = 0;
    for (char &c : number)
    {
        int tempDeciaml = 0;
        if (std::isdigit(c))
        {
            tempDeciaml = c - '0';
        }
        else if (std::isalpha(c))
        {
            char upper = std::toupper(c);
            tempDeciaml = upper - 'A' + 10;
        }
        
        decimal = decimal * base + tempDeciaml;
    }
    
    std::cout << decimal;
}