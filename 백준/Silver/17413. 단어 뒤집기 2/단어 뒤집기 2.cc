#include <iostream>
#include <stack>

void print(std::stack<char> &stack)
{
    while (!stack.empty()) 
    {
        std::cout << stack.top();
        stack.pop();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s = "";
    std::getline(std::cin, s);
    
    bool isTag = false;
    std::stack<char> stack;
    for (const char &c : s)
    {
        if (c == '<')
        {
            print(stack);
            
            std::cout << '<';
            isTag = true;
        }
        else if (c == '>')
        {
            std::cout << '>';
            isTag = false;
        }
        else if (isTag)
        {
            std::cout << c;
        }
        else
        {
            if (c == ' ')
            {
                // 하나의 단어 완성
                print(stack);
                std::cout << " ";
            }
            else
            {
                stack.push(c);
            }
        }
    }
    
    print(stack);
}