#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int count = 0;
    std::cin >> count;
    
    // stack
    std::stack<int> intStack;
    
    for (int index = 0; index < count; index++)
    {
        int menu = 0;
        std::cin >> menu;
        
        switch (menu)
        {
            case 1:
            {
                // 정수를 스택에 넣는다.
                int number = 0;
                std::cin >> number;
                
                intStack.push(number);
                break;
            }
            case 2:
            {
                // 스택에 정수가 있는지 확인(pop yes)하고 출력한다.
                bool isEmpty = intStack.empty();
                if (isEmpty)
                {
                    std::cout << "-1" << "\n";
                }
                else
                {
                    int number = intStack.top();
                    intStack.pop();
                    
                    std::cout << number << "\n";
                }
                break;
            }
            case 3:
            {
                // 스택의 사이즈를 출력한다.
                int size = intStack.size();
                std::cout << size << "\n";
                break;
            }
            case 4:
            {
                // 스택 비어있는지 확인한다.
                bool isEmpty = intStack.empty();
                if (isEmpty)
                {
                    std::cout << "1" << "\n";
                }
                else
                {
                    std::cout << "0" << "\n";
                }
                break;
            }
            case 5:
            {
                // 스택에 정수가 있는지 확인(pop no)하고 출력한다.
                bool isEmpty = intStack.empty();
                if (isEmpty)
                {
                    std::cout << "-1" << "\n";
                }
                else
                {
                    int number = intStack.top();
                    std::cout << number << "\n";
                }
                break;
            }
            default:
            {
                break;
            }
        }
    }
}