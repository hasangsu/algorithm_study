#include <iostream>
#include <string>
#include <stack>

int main()
{
    while (true)
    {
        std::string text = "";
        getline(std::cin, text);
        
        if (text == ".")
        {
            // 입력 종료
            break;
        }
        
        // 균형 확인
        std::stack<char> stacks;
        
        for (char c : text)
        {
            switch (c)
            {
                case '(':
                case '[':
                {
                    stacks.push(c);
                    break;
                }
                case ')':
                {
                    if ((!stacks.empty()) && 
                        (stacks.top() == '('))
                    {
                        stacks.pop();
                    }
                    else
                    {
                        stacks.push(c);
                    }
                    break;
                }
                case ']':
                {
                    if ((!stacks.empty()) && 
                        (stacks.top() == '['))
                    {
                        stacks.pop();
                    }
                    else
                    {
                        stacks.push(c);
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
        
        stacks.empty() ? std::cout << "yes" << "\n"
                        : std::cout << "no" << "\n";
    }
}