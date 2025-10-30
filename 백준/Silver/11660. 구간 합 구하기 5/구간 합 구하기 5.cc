#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 행렬 및 테스트케이스 갯수 입력
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    
    int array[n + 1][n + 1] = {0, };
    int sum[n + 1][n + 1] = {0, };
    for (int i = 1; i <= n; i++)
    {
        int prefix = 0;
        for (int j = 1; j <= n; j++)
        {
            int element = 0;
            std::cin >> element;
            
            array[i][j] = element;
            sum[i][j] = prefix + element;
            
            prefix = sum[i][j];
        }
    }

    // 테스트 케이스 입력
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    while (m--)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;
        
        int min_row = x1;
        int max_row = x2;
        int min_column = y1;
        int max_column = y2;
        
        long long result = 0;
        for (int i = min_row; i <= max_row; i++)
        {
            result += ((sum[i][max_column]) - (sum[i][min_column - 1]));
        }
        
        std::cout << result << "\n";
    }
}