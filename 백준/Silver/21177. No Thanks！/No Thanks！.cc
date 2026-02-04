#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    std::cin >> n;
    
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    int result = numbers[0];
    for (int i = 1; i < n; i++)
    {
        // 이전숫자와 현재숫자를 비교한다.
        // 이전숫자 + 1이 현재숫자면 연속된 숫자이다.
        // 연속된 숫자가 아니라면 결과에 더하기
        if (numbers[i - 1] + 1 != numbers[i])
        {
            result += numbers[i];
        }
    }
    
    std::cout << result;
}