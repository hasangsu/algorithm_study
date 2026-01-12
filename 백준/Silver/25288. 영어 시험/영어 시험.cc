#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::string R = "";
    std::cin >> R;
    
    for (int i = 0; i < N; i++)
    {
        std::cout << R;
    }
}