#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<char> result;
    std::stack<int> s;
    int current = 1;
    for (int i = 0; i < N; i++)
    {
        int number = 0;
        std::cin >> number;
        
        // 만들어야 하는 수열 4 3 6 8 7 5 2 1
        while (current <= number)
        {
            s.push(current);
            current++;
            
            result.push_back('+');
        }
        
        if (s.top() == number)
        {
            s.pop();
            result.push_back('-');
        }
        else
        {
            result.clear();
            break;
        }
    }
    
    if (result.empty())
    {
        std::cout << "NO";
    }
    else
    {
        for (char c : result) 
        {
            std::cout << c << "\n";
        }
    }
}