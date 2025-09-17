#include <iostream>

long long getSumElements(const std::string &number)
{
    long long result = 0;
    for (char element : number)
    {
        result += (element - '0');
    }
    
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string number1 = "";
    std::string number2 = "";
    std::cin >> number1 >> number2;
    
    long long number1_elements = getSumElements(number1);
    long long number2_elements = getSumElements(number2);
    
    long long result = number1_elements * number2_elements;
    std::cout << result;
}