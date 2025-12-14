#include <iostream>
#include <vector>
#include <algorithm>

int twoPointers(const std::vector<int> &sequence, int target)
{
    int start = 0;
    int end = sequence.size() - 1;
    
    int result = 0;
    
    while (start < end)
    {
        int sum = sequence[start] + sequence[end];
        if (sum == target)
        {
            result++;
            start++;
        }
        else if (sum < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    
    return result;
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++)
    {
        int number = 0;
        std::cin >> number;
        
        sequence[i] = number;
    }
    
    int x = 0;
    std::cin >> x;
    
    std::sort(sequence.begin(), sequence.end());
    
    int result = twoPointers(sequence, x);
    std::cout << result;
}