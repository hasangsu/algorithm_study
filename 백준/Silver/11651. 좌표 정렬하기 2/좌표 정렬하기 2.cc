#include <iostream>
#include <vector>
#include <algorithm>

struct Position
{
    int posX = 0;
    int posY = 0;
};

bool compare(const Position &a, const Position &b)
{
    if (a.posY != b.posY)
    {
        return a.posY < b.posY;
    }
    else
    {
        return a.posX < b.posX;
    }
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<Position> positionList;
    for (int index = 0; index < count; index++)
    {
        int posX = 0;
        int posY = 0;
        std::cin >> posX >> posY;
        
        Position position;
        position.posX = posX;
        position.posY = posY;
        
        positionList.push_back(position);
    }
    
    std::sort(positionList.begin(), positionList.end(), compare);
    for(const Position &position : positionList)
    {
        std::cout << position.posX << " " << position.posY << "\n";
    }
}