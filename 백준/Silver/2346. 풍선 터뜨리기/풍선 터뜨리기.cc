#include <iostream>
#include <deque>

int main()
{
    int count = 0;
    std::cin >> count;
    
    // 풍선 & 종이만들기
    std::deque<std::pair<int, int>> balloons;
    for (int index = 1; index <= count; index++)
    {
        int paper = 0;
        std::cin >> paper;
        
        balloons.push_back(std::make_pair(index, paper));
    }
    
    // 풍선 & 종이 확인
    while (!balloons.empty())
    {
        // 맨 앞 풍선 떠뜨리기
        std::pair<int, int> balloon = balloons.front();
        balloons.pop_front();
        
        int number = balloon.first;
        int paper = balloon.second;
        std::cout << number << " ";
        
        if (0 < paper)
        {
            for (int index = 0; index < paper - 1; index++)
            {
                // 다음 대상을 맨 앞으로 이동시키기
                balloons.push_back(balloons.front());
                balloons.pop_front();
            }
        }
        else
        {
            for (int index = 0; index < (paper * -1); index++)
            {
                // 다음 대상을 맨 앞으로 이동시키기
                balloons.push_front(balloons.back());
                balloons.pop_back();
            }
        }
    }
}