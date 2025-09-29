#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    while (count--)
    {
        int number = 0;
        std::cin >> number;
        
        std::string number_str = std::to_string(number);
        std::string square_str = std::to_string(number * number);
        
        const size_t start = square_str.size() - number_str.size();
        const size_t end = number_str.size();
        if (square_str.compare(start, end, number_str) == 0)
        {
            std::cout << "YES" << "\n";
        }
        else
        {
            std::cout << "NO" << "\n";
        }
    }
}