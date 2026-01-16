#include <iostream>
#include <stack>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    
    // 수열
    std::vector<int> numbers(N);
    // 숫자의 갯수
    std::vector<int> counts(1000001);
    // 결과
    std::vector<int> result(N, -1);
    std::stack<int> s;
    for (int i = 0; i < N; i++)
    {
        std::cin >> numbers[i];
        counts[numbers[i]]++;
    }
        
    for (int i = 0; i < N; i++)
    {
        while (!s.empty() &&
                counts[numbers[s.top()]] < counts[numbers[i]])
        {
            // 오등큰수
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