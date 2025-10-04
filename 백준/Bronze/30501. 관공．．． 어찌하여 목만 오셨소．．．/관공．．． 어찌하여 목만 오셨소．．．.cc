#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    while (count--)
    {
        std::string name = "";
        std::cin >> name;
        
        if (name.find('S') != std::string::npos) 
        {
            std::cout << name;
            break;
        }
    }
}