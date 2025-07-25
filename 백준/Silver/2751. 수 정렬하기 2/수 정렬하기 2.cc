#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<int> numbers;
    numbers.reserve(count);
    for (int index = 0; index < count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        numbers.push_back(number);
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    for (int index = 0; index < count; index++)
    {
        std::cout << numbers[index] << "\n";
    }
}