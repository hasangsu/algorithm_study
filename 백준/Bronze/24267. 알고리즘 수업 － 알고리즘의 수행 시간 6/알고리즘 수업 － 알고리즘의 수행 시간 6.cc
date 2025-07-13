#include <iostream>

int main()
{
    long long input = 0;
    std::cin >> input;
    std::cout << (input * (input - 1) * (input -2)) / 6 << "\n" << 3;
}