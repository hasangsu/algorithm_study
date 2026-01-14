#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s = "";
    std::string c4 = "";
    std::cin >> s >> c4;
    
    std::string result = "";
    for (const char &c : s)
    {
        result.push_back(c);
        if (c4.length() <= result.length())
        {
            bool isC4 = true;
            for (int i = 0; i < c4.length(); i++) 
            {
                if (c4[i] != result[result.length() - c4.length() + i])
                {
                    isC4 = false;
                    break;
                }
            }
            
            if (isC4)
            {
                for (int i = 0; i < c4.length(); i++)
                {
                    result.pop_back();
                }
            }
        }
    }
    
    result.empty() ? std::cout << "FRULA" :
                     std::cout << result;
}