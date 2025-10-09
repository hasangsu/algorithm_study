#include <iostream>

bool isArithmeticNumber(int number)
{
    std::string s = std::to_string(number);
    if (s.size() <= 2)
    {
        return true;
    }
    
    int diff = (s[1] - '0') - (s[0] - '0');
    for (int i = 1; i < s.size() - 1; i++) 
    {
        if ((s[i+1] - '0') - (s[i] - '0') != diff)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int number = 0;
    std::cin >> number;
    
    int result = 0;
    for (int i = 1; i <= number; i++)
    {
        if (isArithmeticNumber(i))
        {
            result++;
        }
    }
    
    std::cout << result;
}