#include <iostream>

int main()
{
    int number = 0;
    std::cin >> number;
    
    int count = 0;
    int value = number;
    while (true)
    {
        count++;
        
        int target1 = 0;
        int target2 = 0;
        
        // 앞의 수 구하기
        target1 = (value / 10) % 10;
        
        // 뒤의 수 구하기
        target2 = value % 10;
        
        // 두 수의 합
        int sum = target1 + target2;
        
        // 새로운 수
        value = (target2 * 10) + (sum % 10);
        if (value == number)
        {
            break;
        }
    }
    
    std::cout << count;
}