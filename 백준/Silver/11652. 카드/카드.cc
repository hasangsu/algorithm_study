#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    std::map<long long, int> cards;
    for (int i = 0; i < N; i++)
    {
        long long card  = 0;
        std::cin >> card;
        
        cards[card]++;
    }
    
    int max = 0;
    long long number = 0;
    for (const std::pair<long long, int> &card : cards)
    {
        if (max < card.second)
        {
            number = card.first;
            max = card.second;
        }
    }
    
    std::cout << number;
}