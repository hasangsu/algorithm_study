#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    std::cin >> n;
    
    std::unordered_map<int, int> n_map;
    int n_c = 0;
    while (n--)
    {
        std::cin >> n_c;
        n_map[n_c] = 1;
    }
    
    int m = 0;
    std::cin >> m;
    int m_c = 0;
    while (m--)
    {
        std::cin >> m_c;
        if (n_map.find(m_c) != n_map.end()) 
        {
            std::cout << 1 << "\n";
        } 
        else
        {
            std::cout << 0 << "\n";
        }
    }
}