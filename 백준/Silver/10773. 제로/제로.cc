#include <iostream>
#include <stack>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::stack<int> numbers;
    for (int index = 0; index < count; index++)
    {
        int number = 0;
        std::cin >> number;
        
        switch (number)
        {
            case 0:
            {
                // stack pop
                if (!numbers.empty())
                {
                    numbers.pop();
                }
                break;
            }
            default:
            {
                // stack push
                numbers.push(number);
                break;
            }
        }
    }
    
    int result = 0;
    while (!numbers.empty()) 
    {
        result += numbers.top();
        numbers.pop();
    }
    
    std::cout << result;
}