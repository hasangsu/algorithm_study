#include <iostream>

int main()
{
    int count = 10;
    int sum = 0;
    while (count--)
    {
        int point = 0;
        std::cin >> point;
        
        // 100점에 가까워야되고
        // 기존점수와 새로운점수 가까운지?
        int near1 = std::abs(100 - sum);
        int near2 = std::abs(100 - (sum + point));
        if (near2 <= near1)
        {
            sum += point;
        }
        else
        {
            break;
        }
    }
    
    std::cout << sum;
}