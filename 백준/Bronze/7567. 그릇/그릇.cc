#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string n = "";
    std::cin >> n;
    
    // 처음 그릇과 바닥
    int sum = 10;
    for (int i = 1; i < n.length(); i++)
    {
        if (n[i] == n[i - 1])
        {
            // 그릇이 같을때
            sum += 5;
        }
        else
        {
            // 그릇이 다를때
            sum += 10;
        }
    }
    
    std::cout << sum;
}