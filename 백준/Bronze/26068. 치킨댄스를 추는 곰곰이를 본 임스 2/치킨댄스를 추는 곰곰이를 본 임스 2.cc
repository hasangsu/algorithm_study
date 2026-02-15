#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        std::string s = "";
        std::cin >> s;
        
        size_t dashPos = s.find('-');
        if (dashPos != std::string::npos)
        {
            std::string dayString  = s.substr(dashPos + 1);
            int day = std::stoi(dayString);
            if (day <= 90)
            {
                count++;
            }
        }
    }
    
    std::cout << count;
}