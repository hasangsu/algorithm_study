#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    
    int sum[100001] = {0, };
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        std::cin >> number;
        
        sum[i + 1] = sum[i] + number;
    }
    
    while (m--)
    {
        int start = 0;
        int end = 0;
        std::cin >> start >> end;
        
        int result = sum[end] - sum[start - 1];
        std::cout << result << "\n";
    }
}