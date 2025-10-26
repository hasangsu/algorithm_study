#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    int k = 0;
    std::cin >> n >> k;

    std::vector<int> temperatures;
    temperatures.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int temperature = 0;
        std::cin >> temperature;
        
        temperatures[i] = temperature;
    }
    
    int max = 0;
    for (int i = 0; i < k; i++)
    {
        max += temperatures[i];
    }
    
    int current = max;
    for (int i = k; i < n; i++)
    {
        current += temperatures[i];
        current -= temperatures[i - k];
        if (max < current)
        {
            max = current;
        }
    }
    
    std::cout << max << "\n";
}