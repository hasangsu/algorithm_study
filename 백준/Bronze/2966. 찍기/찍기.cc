#include <iostream>
#include <vector>

int getCorrect(const std::string &text, const std::string &pattern)
{
    int count = 0;
    
    for (size_t i = 0; i < text.size(); i++) 
    {
        size_t j = i % pattern.size();
        if (text[i] == pattern[j]) 
        {
            count++;
        }
    }
    
    return count;
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::string text = "";
    std::cin >> text;
    
    int result_adrian = getCorrect(text, "ABC");
    int result_bruno = getCorrect(text, "BABC");
    int result_goran = getCorrect(text, "CCAABB");
    
    int max_result = std::max(result_adrian, std::max(result_bruno, result_goran));
    std::cout << max_result << "\n";
    if (result_adrian == max_result) std::cout << "Adrian\n";
    if (result_bruno  == max_result) std::cout << "Bruno\n";
    if (result_goran  == max_result) std::cout << "Goran\n";
}