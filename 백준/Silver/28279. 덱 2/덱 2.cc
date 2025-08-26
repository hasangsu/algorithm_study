#include <iostream>
#include <deque>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    std::deque<int> deques;
    while (count--)
    {
        int command = 0;
        std::cin >> command;
        
        switch (command)
        {
            case 1:
            {
                // 덱의 맨 앞에 삽입
                int number = 0;
                std::cin >> number;
                
                deques.push_front(number);
                break;
            }
            case 2:
            {
                // 덱의 맨 뒤에 삽입
                int number = 0;
                std::cin >> number;
                
                deques.push_back(number);
                break;
            }
            case 3:
            {
                // 덱이 비어있지 않다면 맨 앞 엘리먼트 팝하고 출력
                bool isEmpty = deques.empty();
                if (isEmpty)
                {
                    std::cout << "-1" << "\n";
                }
                else
                {
                    int number = deques.front();
                    deques.pop_front();
                    
                    std::cout << number << "\n";
                }
                break;
            }
            case 4:
            {
                // 덱이 비어있지 않다면 맨 뒤 엘리먼트 팝하고 출력
                bool isEmpty = deques.empty();
                if (isEmpty)
                {
                    std::cout << "-1" << "\n";
                }
                else
                {
                    int number = deques.back();
                    deques.pop_back();
                    
                    std::cout << number << "\n";
                }
                break;
            }
            case 5:
            {
                // 덱의 사이즈 출력
                int size = deques.size();
                std::cout << size << "\n";
                break;
            }
            case 6:
            {
                // 덱이 비어있는지 여부 출력
                bool isEmpty = deques.empty();
                if (isEmpty)
                {
                    std::cout << 1 << "\n";
                }
                else
                {
                    std::cout << 0 << "\n";
                }
                break;
            }
            case 7:
            {
                // 덱이 비어있지 않다면 맨 앞 엘리먼트 출력
                bool isEmpty = deques.empty();
                if (isEmpty)
                {
                    std::cout << "-1" << "\n";
                }
                else
                {
                    int number = deques.front();
                    
                    std::cout << number << "\n";
                }
                break;
            }
            case 8:
            {
                // 덱이 비어있지 않다면 맨 뒤 엘리먼트 출력
                bool isEmpty = deques.empty();
                if (isEmpty)
                {
                    std::cout << "-1" << "\n";
                }
                else
                {
                    int number = deques.back();
                    
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