#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string S = "";
    int q = 0;
    std::cin >> S >> q;
    
    std::unordered_map<char, std::vector<int>> countMap;
    for (int i = 0; i < S.length(); i++)
    {
        char c = S[i];
        countMap[c].push_back(i);
    }
    
    char a = ' ';
    int l = 0;
    int r = 0;
    while (q--)
    {
        std::cin >> a >> l >> r;
        std::unordered_map<char, std::vector<int>>::const_iterator it = countMap.find(a);
        if (it != countMap.end())
        {
            const std::vector<int> &indexs = it->second;
            
            std::vector<int>::const_iterator lb = std::lower_bound(indexs.begin(), indexs.end(), l);
            std::vector<int>::const_iterator ub = std::upper_bound(indexs.begin(), indexs.end(), r);
            
            int count = (ub - lb);
            std::cout << count << '\n';
        }
        else
        {
            std::cout << 0 << "\n";
        }
    }
}