#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;
    
    int result = 0;
    for (int i = 1; i <= N; i*=10)
    {
        result += (N - i + 1);
    }
    
    std::cout << result;
}