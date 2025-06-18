#include <iostream>
#include <algorithm>

int main()
{
    int number = 0;
    int base = 0;
    std::cin >> number >> base;
    
    std::string result = "";
    while (0 < number)
    {
        int quotient = number / base;
        int remainders = number % base;
        number = quotient;
        result += (remainders < 10) ? (remainders + '0') : (remainders + 'A' - 10);
    }
    
    std::reverse(result.begin(), result.end());
    std::cout << result;
}