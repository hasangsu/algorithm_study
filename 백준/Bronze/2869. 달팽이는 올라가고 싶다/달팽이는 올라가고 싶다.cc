#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int up = 0;
    int down = 0;
    int height = 0;
    std::cin >> up >> down >> height;
    
    int dayMove = (up - down);
    
    // 올림 처리
    int day = (height - up + dayMove - 1) / dayMove + 1;
    std::cout << day;
}