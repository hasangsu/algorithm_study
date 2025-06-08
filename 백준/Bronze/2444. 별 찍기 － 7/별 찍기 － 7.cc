#include <iostream>

int main()
{
    int input = 0;
    std::cin >> input;
    
    int max = (2 * input) - 1;
    
    // 별 증가
    for (int line = 1; line <= input; line++)
    {
        int star = (2 * line) - 1;
        int space = max - star;
        
        for (int index = 0; index < (space / 2); index++)
        {
            std::cout << " ";
        }
        
        for (int index = 0; index < star; index++)
        {
            std::cout << "*";
        }
        
        std::cout << " "<< "\n";
    }
    
    // 별 감소
    for (int line = input - 1; 1 <= line; line--)
    {
        int star = (2 * line) - 1;
        int space = max - star;
        
        for (int index = 0; index < (space / 2); index++)
        {
            std::cout << " ";
        }
        
        for (int index = 0; index < star; index++)
        {
            std::cout << "*";
        }
        
        if (line != 1)
        {
            std::cout << " " << "\n";    
        }
    }
}