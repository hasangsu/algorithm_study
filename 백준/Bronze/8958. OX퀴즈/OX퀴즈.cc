#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T = 0;
    std::cin >> T;
    
    while (T--)
    {
        std::string p = "";
        std::cin >> p;
        
        int result = 0;
        int point = 1;
        for (const char &c : p)
        {
            // OOXXOXXOOO = 10
            if (c == 'X')
            {
                point = 1;
            }
            else
            {
                result += point;
                point++;
            }
        }
        
        std::cout << result << "\n";
    }

    return 0;
}