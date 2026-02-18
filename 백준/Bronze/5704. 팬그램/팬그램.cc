#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    
    while (true)
    {
        std::string s = "";
        std::getline(std::cin, s);
        if (s == "*")
        {
            break;
        }
        
        std::vector<bool> checks(26, false);
        for (const char &c : s)
        {
            checks[c - 97] = true;
        }
        
        bool result = true;
        for (int i = 0; i < 26; i++)
        {
            if (!checks[i])
            {
                result = false;
                break;
            }
        }
        
        (result == true) ? std::cout << "Y\n" :
                            std::cout << "N\n";
    }
}