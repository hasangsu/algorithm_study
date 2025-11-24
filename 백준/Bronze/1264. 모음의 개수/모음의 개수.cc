#include <iostream>

int main()
{
    while (true)
    {
        std::string text = "";
        std::getline(std::cin, text);
        
        if (text == "#")
        {
            break;
        }
        
        int count = 0;
        for (const char &c : text)
        {
            switch (std::tolower(c))
            {
                case 'a' :
                case 'e' :
                case 'i' :
                case 'o' :
                case 'u' :
                {
                    count++;
                    break;
                }
                default :
                {
                    break;
                }
            }
        }
        
        std::cout << count << "\n";
    }
}