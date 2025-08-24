#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    std::queue<int> queues;
    while (count--)
    {
        std::string command = "";
        std::cin >> command;
        
        if (command.compare("push") == 0)
        {
            // 정수를 삽입한다.
            int number = 0;
            std::cin >> number;
            
            queues.push(number);
        }
        else if (command.compare("pop") == 0)
        {
            if (queues.empty())
            {
                // 큐가 비어있으면 -1을 출력한다.
                std::cout << "-1" << "\n";
            }
            else
            {
                // 큐가 비어있지 않으면 맨 앞 정수를 출력한다.
                int number = queues.front();
                queues.pop();
                std::cout << number << "\n";
            }
        }
        else if (command.compare("size") == 0)
        {
            // 사이즈를 출력한다.
            int size = queues.size();
            std::cout << size << "\n";
        }
        else if (command.compare("empty") == 0)
        {
            // 큐가 비었으면 1, 아니면 0을 출력한다.
            bool isEmpty = queues.empty();
            isEmpty ? std::cout << "1" << "\n" :
                      std::cout << "0" << "\n";
        }
        else if (command.compare("front") == 0)
        {
            if (queues.empty())
            {
                // 큐가 비어있으면 -1을 출력한다.
                std::cout << "-1" << "\n";
            }
            else
            {
                // 큐가 비어있지 않으면 맨 앞 정수를 출력한다.
                int number = queues.front();
                std::cout << number << "\n";
            }
        }
        else if (command.compare("back") == 0)
        {
            if (queues.empty())
            {
                // 큐가 비어있으면 -1을 출력한다.
                std::cout << "-1" << "\n";
            }
            else
            {
                // 큐가 비어있지 않으면 맨 뒤 정수를 출력한다.
                int number = queues.back();
                std::cout << number << "\n";
            }
        }
        else
        {
            continue;
        }
    }
}