#include <iostream>

int main()
{
    int length = 0;
    std::cin >> length;
    
    while (length--)
    {
        char ch = ' ';
        std::cin >> ch;
        
        if (ch == 'I') 
        {
            std::cout << "i";
        } 
        else if (ch == 'l') 
        {
            std::cout << "L";
        }
    }
}