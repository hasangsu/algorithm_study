#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<int> counts(10, 0);
    int temp = N;
    while (0 < temp)
    {
        int d = temp % 10;
        counts[d]++;
        
        temp = temp / 10;
    }
    
    // 6, 9 합치기
    counts[6] = (counts[6] + counts[9] + 1) / 2;
    counts[9] = 0;
    int set = 0;
    
    for (int i = 0; i < 10; i++)
    {
        if (set <= counts[i])
        {
            set = counts[i];
        }
    }
    
    std::cout << set;
}