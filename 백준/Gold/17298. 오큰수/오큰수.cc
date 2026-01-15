#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<int> numbers(N);
    std::vector<int> result(N, -1);
    std::stack<int> s;
    for (int i = 0; i < N; i++)
    {
        std::cin >> numbers[i];
        
        while (!s.empty() &&
                numbers[s.top()] < numbers[i])
        {
            // 오큰수
            result[s.top()] = numbers[i];
            s.pop();
        }
        
        s.push(i);
    }
    
    for (const int i : result)
    {
        std::cout << i << " ";
    }
}