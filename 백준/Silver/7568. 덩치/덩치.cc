#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    // 몸무게, 키
    std::vector<std::pair<int, int>> bigs(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> bigs[i].first >> bigs[i].second;
    }
    
    for (int i = 0; i < N; i++)
    {
        int rank = 1;
        
        for (int j = 0; j < N; j++)
        {
            if ((bigs[i].first < bigs[j].first) &&
                (bigs[i].second < bigs[j].second))
            {
                rank++;
            }
        }
        
        std::cout << rank << " ";
    }
}