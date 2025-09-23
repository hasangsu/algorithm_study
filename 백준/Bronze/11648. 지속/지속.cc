#include <iostream>

int getMulti(int number)
{
    int result = 1;
    while (number > 0)
    {
        int digit = number % 10;
        result *= digit;
        number /= 10;    
    }
    
    return result;
}

int getKipa(int number)
{
    int count = 0;
    int multi = 1;
    int tmp = number;
    while (true)
    {
        if (tmp < 9)
        {
            break;
        }
        
        count++;
        tmp = getMulti(tmp);
    }
    
    return count;
}

int main()
{
    int number = 0;
    std::cin >> number;
    
    int result = getKipa(number);
    std::cout << result;
}