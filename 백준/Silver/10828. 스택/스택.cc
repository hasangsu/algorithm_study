#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    std::stack<int> s;
    std::unordered_map<std::string, int> commandMap;
    commandMap["push"] = 0;
    commandMap["pop"] = 1;
    commandMap["size"] = 2;
    commandMap["empty"] = 3;
    commandMap["top"] = 4;
    
    while (N--)
    {
        std::string command = "";
        std::cin >> command;
        
        std::unordered_map<std::string, int>::const_iterator it = commandMap.find(command);
        if (it != commandMap.end())
        {
            switch (it->second)
            {
                case 0:
                {
                    // push
                    int n = 0;
                    std::cin >> n;
                    
                    s.push(n);
                    break;
                }
                case 1:
                {
                    // pop
                    if (s.empty())
                    {
                        std::cout << -1 << "\n";
                    }
                    else
                    {
                        int top = s.top();
                        s.pop();
                        
                        std::cout << top << "\n";
                    }
                    break;
                }
                case 2:
                {
                    // size
                    std::cout << s.size() << "\n";
                    break;
                }
                case 3:
                {
                    // empty
                    if (s.empty())
                    {
                        std::cout << 1 << "\n";
                    }
                    else
                    {
                        std::cout << 0 << "\n";
                    }
                    break;
                }
                case 4:
                {
                    // top
                    if (s.empty())
                    {
                        std::cout << -1 << "\n";
                    }
                    else
                    {
                        int top = s.top();
                        std::cout << top << "\n";
                    }
                    break;
                }
                default:
                {
                    break;
                }
            }
        }
    }
}