#include <iostream>
#include <algorithm>

int main()
{
    int count = 5;
    int numbers[count] = { 0, };
    int sum = 0;
    for (int index = 0; index < count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        numbers[index] = number;
        sum += number;
    }
    
    // 오름차순 정렬
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (numbers[j + 1] < numbers[j])
            {
                std::swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    
    
    int average = sum / 5;
    int median = numbers[2];
    std::cout << average << "\n" << median;
}