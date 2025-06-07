#include <iostream>

int main()
{
    int king = 0;
    int queen = 0;
    int rocks = 0;
    int bishops = 0;
    int knights = 0;
    int pawns = 0;
    std::cin >> king >> queen >> rocks >> bishops >> knights >> pawns;
    
    int requireKing = 1 - king;
    int requireQueen = 1 - queen;
    int requireRocks = 2 - rocks;
    int requireBishops = 2 - bishops;
    int requireKnights = 2 - knights;
    int requirePawns = 8 - pawns;
    std::cout << requireKing << " "
                << requireQueen << " "
                << requireRocks << " "
                << requireBishops << " "
                << requireKnights << " "
                << requirePawns;
}