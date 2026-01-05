#include <iostream>
#include <string>

int main()
{
    int N = 0;
    std::cin >> N;
    
    for (int i = N; 0 < i; i--)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << "*";
        }
        
        std::cout << "\n";
    }
}