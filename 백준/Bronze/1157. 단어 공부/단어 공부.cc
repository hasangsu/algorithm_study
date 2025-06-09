#include <iostream>
#include <vector>

int main()
{
    std::string text = "";
    std::cin >> text;
    
    int maxUse = 0;
    int alpabets[26] = {0};
    for (int index = 0; index < text.length(); index++)
    {
        char upper = std::toupper(text[index]);
        
        int alpabetIndex = upper - 'A';
        alpabets[alpabetIndex]++;
        
        if (maxUse < alpabets[alpabetIndex])
        {
            maxUse = alpabets[alpabetIndex];
        }
    }
    
    std::vector<int> findIndexList;
    for (int index = 0; index < 26; index++)
    {
        if (maxUse == alpabets[index])
        {
            findIndexList.push_back(index);
        }
    }
    
    if (findIndexList.size() == 1)
    {
        std::cout << static_cast<char> (findIndexList[0] + 'A');
    }
    else if (1 < findIndexList.size())
    {
        std::cout << "?";
    }
}