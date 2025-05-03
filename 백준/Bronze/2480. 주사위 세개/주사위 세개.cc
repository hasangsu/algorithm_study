#include <iostream>

int main()
{
    int dice1;
    int dice2;
    int dice3;
    scanf("%d %d %d", &dice1, &dice2, &dice3);
    
    int prize = 0;
    if ((dice1 == dice2) && (dice1 == dice3))
    {
        prize = 10000 + (dice1 * 1000);
    }
    else if (((dice1 == dice2) && (dice1 != dice3)) || 
            ((dice1 == dice3) && (dice1 != dice2)))
    {
        prize = 1000 + (dice1 * 100);
    }
    else if ((dice2 == dice3) && (dice1 != dice3))
    {
        prize = 1000 + (dice2 * 100);
    }
    else 
    {
        int most = dice1 < dice2 ? (dice2 < dice3 ?  dice3 : dice2) : (dice1 < dice3 ? dice3 : dice1);
        prize = most * 100;;
    }
    
    printf("%d", prize);
}