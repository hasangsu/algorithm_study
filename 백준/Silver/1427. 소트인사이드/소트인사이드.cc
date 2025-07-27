#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int number = 0;
    std::cin >> number;
    
    std::vector<int> numbers;
    while (number > 0)
    {
        numbers.push_back(number % 10);
        number = number / 10;
    }
    
    std::sort(numbers.rbegin(), numbers.rend());
    for (int n : numbers)
    {
        std::cout << n;
    }
}