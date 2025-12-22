#include <iostream>
#include <vector>

int main()
{
    int A = 0;
    int B = 0;
    int C = 0;
    std::cin >> A >> B >> C;
    
    int result = A * B * C;
    
    std::vector<int> numbers(10, 0);
    while (0 < result)
    {
        int number = result % 10;
        numbers[number]++;
        
        result /= 10;
    }

    for (int i = 0; i <= 9; i++)
    {
        std::cout << numbers[i] << "\n";
    }
}