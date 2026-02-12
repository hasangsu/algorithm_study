#include <iostream>
#include <vector>

int main()
{
    std::string S = "";
    std::cin >> S;
    
    std::vector<int> counts(26, 0);
    for (const char &c : S)
    {
        counts[c - 'a']++;
    }
    
    for (const int count : counts)
    {
        std::cout << count << " ";
    }
}