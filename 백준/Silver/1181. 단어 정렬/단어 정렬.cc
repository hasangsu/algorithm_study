#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

bool compare(const std::string &a, const std::string &b)
{
    if (a.length() != b.length()) 
    {
        return a.length() < b.length();
    }
    else
    {
        return a < b;
    }
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    // unordered_map으로 단어 중복 제거
    std::unordered_map<std::string, int> wordMap;
    for (int index = 0; index < count; index++)
    {
        std::string word = "";
        std::cin >> word;
        
        wordMap[word] = word.length();
    }
    
    // unordered_map을 vector로 변경
    std::vector<std::string> wordList;
    for (const std::pair<const std::string, int> &word : wordMap)
    {
        wordList.push_back(word.first);
    }
    
    std::sort(wordList.begin(), wordList.end(), compare);
    for(const std::string &word : wordList)
    {
        std::cout << word << "\n";
    }
}