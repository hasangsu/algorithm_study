#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    // 각 게임마다 결과 담기 [사람][게임 1 ~ 3]
    std::vector<std::vector<int>> score(N, std::vector<int>(3));
    
    // 최종 점수 담기
    std::vector<int> result(N, 0);
    
    for (int i = 0; i < N; i++)
    {
        // 각 사람별 게임 점수
        for (int j = 0; j < 3; j++)
        {
            std::cin >> score[i][j];
        }
    }
    
    // 점수 확인
    for (int i = 0; i < 3; i++)
    {
        std::vector<int> counts(101, 0);
        for (int j = 0; j < N; j++)
        {
            int num = score[j][i];
            counts[num]++;
        }

        for (int k = 0; k < N; k++)
        {
            int num = score[k][i];
            if (counts[num] == 1)
            {
                result[k] += num;
            }
        }
    }
        
    for (const int r : result)
    {
        std::cout << r << "\n";
    }
}