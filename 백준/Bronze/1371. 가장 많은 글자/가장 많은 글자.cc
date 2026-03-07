#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string line;
    std::map<char, int> counts;
    int max = 0;

    while (std::getline(std::cin, line))
    {
        for (char c : line)
        {
            if (c >= 'a' && c <= 'z')
            {
                counts[c]++;
                if (counts[c] > max)
                {
                    max = counts[c];
                }
            }
        }
    }

    for (std::pair<char, int> const &pair : counts)
    {
        if (pair.second == max)
        {
            std::cout << pair.first;
        }
    }
}