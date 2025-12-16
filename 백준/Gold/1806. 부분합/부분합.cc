#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int twoPointers(const std::vector<int> &sequence, int target)
{
    int start = 0;
    int end = 0;
    
    int result = INT_MAX;
    int sum = 0;
    
    while (true)
    {
        if (target <= sum)
        {
            result = std::min(result, end - start);
            sum -= sequence[start];
            start++;
        }
        else if (end == sequence.size())
        {
            break;
        }
        else
        {
            sum += sequence[end];
            end++;
        }
    }
    
    if (result == INT_MAX)
    {
        return 0;
    }
    else
    {
        return result;
    }
    
    return result;
}

int main()
{
    int N = 0;
    int S = 0;
    std::cin >> N >> S;
    
    std::vector<int> sequence(N);
    for (int i = 0; i < N; i++)
    {
        int number = 0;
        std::cin >> number;
        
        sequence[i] = number;
    }
    
    int result = twoPointers(sequence, S);
    std::cout << result;
}