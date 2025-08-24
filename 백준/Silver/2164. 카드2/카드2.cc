#include <iostream>
#include <queue>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::queue<int> queues;
    for (int index = 1; index <= count; index++)
    {
        queues.push(index);
    }
    
    // flag가 false이면 맨 위 숫자를 버린다.
    // flag가 true이면 맨 위 숫자를 마지막으로 옮긴다.
    bool flag = false;
    while (!queues.empty() &&
           !(queues.size() == 1))
    {
        int number = queues.front();
        queues.pop();
        
        if (flag)
        {
            queues.push(number);
        }
        
        flag = !flag;
    }
    
    std::cout << queues.front();
}