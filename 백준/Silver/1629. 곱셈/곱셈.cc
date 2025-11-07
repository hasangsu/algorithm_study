#include <iostream>

long long multiplication(int a, int b, int c)
{
    if (b == 0)
    {
        return 1;
    }
    
    long long temp = multiplication(a, (b / 2), c);
    long long result = (temp * temp) % c;
    
    if (b % 2 == 1)
    {
        result = (result * a) % c;
    }
    
    return result;
}

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    std::cin >> a >> b >> c;
    
    long long result = multiplication(a, b, c);
    std::cout << result;
}