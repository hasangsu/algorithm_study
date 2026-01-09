#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<int> permutation(N);
    
    // 중간에 큰수가 들어가도록
    int left = 0;
    int right = N - 1;
    for (int i = 1; i <= N; i++)
    {
        if (i % 2 == 0)
        {
            // 짝수
            permutation[right] = i;
            right--;
        }
        else
        {
            // 홀수
            permutation[left] = i;
            left++;
        }
    }
    
    for (const int n : permutation)
    {
        std::cout << n << " ";
    }
}