#include <iostream>
#include <algorithm>
#include<cmath>
#include <vector>
 
int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<int> numbers;
    while (count--)
    {
        int number = 0;
        std::cin >> number;
        
        numbers.push_back(number);
    }
    
    int result = 0;
    int front = 0;
    int back = 0;
    
    // 약수의 갯수 짝수, 홀수 비교
    sort(numbers.begin(), numbers.end());
    int size = numbers.size();
    
    if (size < 0)
    {
        result = 0;
    }
    else if (size == 1)
    {
        int front = numbers.front();
        result = pow(front, 2);
    }
    else
    {
        front = numbers.front();
        back = numbers.back();
        result = front * back;
    }
    
    std::cout << result;
}