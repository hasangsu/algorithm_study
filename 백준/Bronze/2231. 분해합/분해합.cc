#include <iostream>
#include <climits>

int main()
{
    int number = 0;
    std::cin >> number;
    
    bool isFind = false;
    int result = INT_MAX;
    for (int index = 1; index <= number; index++)
    {
        // 생성자
        int constructor = index;
        
        // 분해합 생성
        int sum = constructor;
        int tmp = constructor;
        while (tmp > 0)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        
        // 분해합 확인
        if (sum != number)
        {
            continue;
        }
        
        if (constructor < result)
        {
            isFind = true;
            result = constructor;
        }
    }
    
    if (isFind)
    {
        std::cout << result;
    }
    else
    {
        std::cout << 0;
    }
        
}