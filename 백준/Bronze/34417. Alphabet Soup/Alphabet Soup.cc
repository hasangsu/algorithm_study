#include <iostream>
#include <bitset>

int main()
{
    const int count = 26;
    std::bitset<count> alpabets;
        
    std::string soup = "";
    std::cin >> soup;
    
    bool isFull = false;
    for (const char &elemnet : soup)
    {
        int n = elemnet - 'A';
        if (0 <= n && n < count)
        {
            alpabets.set(n);    
        }
        
        if (alpabets.all())
        {
            isFull = true;
            break;
        }
    }
    
    if (isFull)
    {
        std::cout << "Alphabet Soup!";
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            if (!alpabets[i])
            {
                std::cout << static_cast<char>('A' + i);
            }
        }
    }
}