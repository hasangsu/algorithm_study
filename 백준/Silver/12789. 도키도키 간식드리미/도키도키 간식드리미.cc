#include <iostream>
#include <stack>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::stack<int> orderStacks;
    int current = 1;
    while (count--)
    {
        int number = 0;
        std::cin >> number;
        
        if (number == current)
        {
            // 순번이 맞으면 통과
            current++;
        }
        else
        {
            // 순번이 다르면 대기라인에서 대기
            orderStacks.push(number);
        }
        
        // 그다음 순번이 대기에 있는지 확인
        while ((!orderStacks.empty() &&
                (orderStacks.top() == current)))
        {
            // 대기에 그다음 순번이 있으므로 통과
            orderStacks.pop();
            current++;
        }
    }
    
    orderStacks.empty() ? std::cout << "Nice" << "\n"
                        : std::cout << "Sad" << "\n";
}