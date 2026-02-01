#include <iostream>
#include <unordered_map>

int main()
{
    std::string s = "";
    std::cin >> s;
    
    for (const char &c : s)
    {
        char convert = (c - 3);
        if (convert < 'A')
        {
            convert += 26;
        }
        
        std::cout << convert;
    }
}