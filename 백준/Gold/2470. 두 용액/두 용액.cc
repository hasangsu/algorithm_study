#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

void twoPointers(const std::vector<int> &solution, int &result1, int &result2)
{
    int start = 0;
    int end = solution.size() - 1;
    
    int min = INT_MAX;
    while (start < end)
    {
        int sum = solution[start] + solution[end];
        if (std::abs(sum) < min)
        {
            min = std::abs(sum);
            result1 = solution[start];
            result2 = solution[end];
            
            if (sum == 0)
            {
                break;
            }
        }
        else if (sum < 0)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    std::vector<int> solution(n);
    for (int i = 0; i < n; i++)
    {
        int v = 0;
        std::cin >> v;
        
        solution[i] = v;
    }
    
    std::sort(solution.begin(), solution.end());
    
    int result1 = 0;
    int result2 = 0;
    twoPointers(solution, result1, result2);
    
    std::cout << result1 << " " << result2;
}