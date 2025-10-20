#include <iostream>
#include <climits>
#include <vector>

int max = INT_MIN;
int min = INT_MAX;

void dfs(int index, int accumulate, std::vector<int> numbers, int plus, int minus, int mul, int div_)
{
    if (index == numbers.size())
    {
        // 마지막 연산자까지 사용하여 모든 계산을 완료하였을때
        if (accumulate >= max)
        {
            max = accumulate;
        }
        
        if (accumulate <= min)
        {
            min = accumulate;
        }
        return;
    }
    
    // 경로수집
    int number = numbers[index];
    if (0 < plus)
    {
        dfs(index + 1, accumulate + number, numbers, plus - 1, minus, mul, div_);
    }
    if (0 < minus)
    {
        dfs(index + 1, accumulate - number, numbers, plus, minus - 1, mul, div_);
    }
    if (0 < mul)
    {
        dfs(index + 1, accumulate * number, numbers, plus, minus, mul - 1, div_);
    }
    if (0 < div_)
    {
        dfs(index + 1, accumulate / number, numbers, plus, minus, mul, div_ - 1);
    }
}

void backtracking_dfs(int index, int accumulate, std::vector<int> numbers, int plus, int minus, int mul, int div_)
{
    dfs(index, accumulate, numbers, plus, minus, mul, div_);
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<int> numbers;
    for (int i = 0; i < count; i++)
    {
        int number = 0;
        std::cin >> number;
        
        numbers.push_back(number);
    }
    
    int plus = 0;
    int minus = 0;
    int mul = 0;
    int div_ = 0;
    std::cin >> plus >> minus >> mul >> div_;
    
    backtracking_dfs(1, numbers[0], numbers, plus, minus, mul, div_);
    
    std::cout << max << "\n" << min;
}