#include <iostream>
#include <stack>

int main()
{
    int count = 0;
    std::cin >> count;
    
    for (int index = 0; index < count; index++)
    {
        std::string text = "";
        std::cin >> text;
        
        std::stack<char> stacks;
        for (char c : text)
        {
            if (c == '(')
            {
                stacks.push('(');
            }
            else if (c == ')')
            {
                if (!stacks.empty())
                {
                    char top = stacks.top();
                    if (top == '(')
                    {
                        stacks.pop();
                    }
                    else
                    {
                        stacks.push(')');
                    }
                }
                else
                {
                    stacks.push(')');
                }
            }
            else
            {
                // 아무것도 하지 않는다.
                continue;
            }
        }
        
        stacks.empty() ? std::cout << "YES" << "\n"
                        : std::cout << "NO" << "\n";
    }
}