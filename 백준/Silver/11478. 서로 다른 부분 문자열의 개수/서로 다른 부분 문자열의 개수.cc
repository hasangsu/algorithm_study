#include <iostream>
#include <set>

int main()
{
    std::string word;
    std::cin >> word;
    
    std::set<std::string> wordSet;
    int size = word.size();
    for (int index = 0; index < size; index++)
    {
        for (int len = 1; len <= size - index; len++) 
        {
            wordSet.insert(word.substr(index, len));
        }
    }
    
    std::cout << wordSet.size();
}