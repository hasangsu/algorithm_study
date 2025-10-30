#include <iostream>
#include <vector>

int getMinimumCoin(int k, const std::vector<int> &coins)
{
    int result = 0;
    for (std::vector<int>::const_reverse_iterator it = coins.rbegin(); it != coins.rend(); ++it)
    {
        const int coin = *it;
        
        int count = (k / coin);
        k -= (count * coin);
        result += count;
    }
    
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    
    // 동전 입력
    std::vector<int> coins;
    coins.reserve(n);
    
    int coin = 0;
    while (n--)
    {
        std::cin >> coin;
        coins.push_back(coin);
    }
    
    // 최소한의 동전 탐색
    int result = getMinimumCoin(k, coins);
    std::cout << result;
}