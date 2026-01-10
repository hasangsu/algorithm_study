#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<int> permutation(N);
    int left = 1;
    int right = N;
    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0)
        {
            // 작은수
            permutation[i] = left;
            left++;
        }
        else
        {
            // 큰수
            permutation[i] = right;
            right--;
        }
    }
    
    for (const int n : permutation)
    {
        std::cout << n << " ";
    }
}