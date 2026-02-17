#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        std::string K = "";
        std::cin >> K;
        
        (K.back() % 2 == 0) ? std::cout << "even" << "\n":
                        std::cout << "odd" << "\n";
    }
}