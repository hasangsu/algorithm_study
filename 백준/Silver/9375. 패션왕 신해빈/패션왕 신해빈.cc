#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T = 0;
    std::cin >> T;
    
    while (T--)
    {
        int n = 0;
        std::cin >> n;
        
        int result = 1;
        std::map<std::string, std::vector<std::string>> clothes;
        for (int i = 0; i < n; i++)
        {
            std::string item = "";
            std::string category = "";
            std::cin >> item >> category;
            
            clothes[category].push_back(item);
        }
        
        for (const std::pair<std::string, std::vector<std::string>> &p : clothes)
        {
            int count = p.second.size();
            result *= (count + 1);
        }
        
        std::cout << result - 1 << "\n";
    }
}