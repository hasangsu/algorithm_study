#include <iostream>

int main()
{
    std::string text = "";
    std::cin >> text;
    
    bool isPalindrome = true;
    for (int index = 0; index < text.length(); index++)
    {
        char front = text[index];
        char end = text[text.length() - 1 - index];
        if (front != end)
        {
            isPalindrome = false;
        }
    }
    
    std::cout << static_cast<int> (isPalindrome);
}