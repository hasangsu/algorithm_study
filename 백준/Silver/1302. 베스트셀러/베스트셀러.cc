#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    std::map<std::string, int> books;
    for (int i = 0; i < N; i++)
    {
        std::string book = "";
        std::cin >> book;
        
        books[book]++;
    }
    
    int count = 0;
    std::string best = "";
    
    for (const std::pair<std::string, int> &info : books)
    {
        if (count < info.second)
        {
            best = info.first;
            count = info.second;
        }
    }
    
    std::cout << best;
}