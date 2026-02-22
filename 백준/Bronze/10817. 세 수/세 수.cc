#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> numbers;
    
    for (int i=0; i < 3; i++)
    {
        int n = 0;
        std::cin >> n;
        
        numbers.push_back(n);
    }
    
    std::sort(numbers.begin(), numbers.end());
    std::cout << numbers[1];
}