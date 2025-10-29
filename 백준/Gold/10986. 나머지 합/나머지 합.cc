#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    long long n = 0;
    int m = 0;
    std::cin >> n >> m;
    
    long long numbers[n + 1] = {0, };
    long long mods[n + 1] = {0, };
    long long count[m] = {0, };
    for (int i = 1; i <= n; i++)
    {
        int number = 0;
        std::cin >> number;
        
        numbers[i] = number;
        mods[i] = (mods[i - 1] + numbers[i]) % m;
        count[mods[i]]++;
    }
    
    long long result = 0;
    for (int r = 0; r < m; r++)
    {
        result += count[r] * (count[r] - 1);
    }
    result /= 2;
    result += count[0];
    
    std::cout << result;
    
}