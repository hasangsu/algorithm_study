#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    
    std::unordered_map<std::string, int> wordMap;
    std::string word = "";
    while (n--)
    {
        std::cin >> word;
        if (word.length() < m)
        {
            continue;
        }
        
        wordMap[word]++;
    }
    
    // map to vector
    std::vector<std::string> wordVector;
    wordVector.reserve(wordMap.size());
    for (const std::pair<const std::string, int> &wordPair : wordMap)
    {
        wordVector.push_back(wordPair.first);
    }
    
    // sort
    std::sort(wordVector.begin(), wordVector.end(), 
                [&wordMap](const std::string &a, const std::string &b) 
                {
                  if (wordMap[a] != wordMap[b]) 
                  {
                      return wordMap[a] > wordMap[b];
                  }
                  
                  if (a.size() != b.size()) 
                  {
                      return a.size() > b.size();
                  }
                  
                  return a < b;
                });
                
    // print
    for (const std::string &word : wordVector)
    {
        std::cout << word << "\n";
    }
}