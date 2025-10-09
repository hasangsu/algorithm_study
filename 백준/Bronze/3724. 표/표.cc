#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int testcase = 0;
    std::cin >> testcase;
    
    while (testcase--)
    {
        int column = 0;
        int row = 0;
        std::cin >> column >> row;
        
        std::vector<double> logSum(column, 0.0);
        std::vector<int> negCount(column, 0);
        std::vector<int> zeroCount(column, 0);

        for (int i = 0; i < row; ++i) 
        {
            for (int j = 0; j < column; ++j) 
            {
                long long x;
                std::cin >> x;

                if (x == 0) 
                {
                    zeroCount[j]++;
                } 
                else 
                {
                    logSum[j] += std::log(std::abs((double)x));
                    if (x < 0) 
                    {
                        negCount[j]++;
                    }
                }
            }
        }
        
        int max_column = 0;
        for (int i = 0; i < column; i++) 
        {
            // status: 양수=2, 0=1, 음수=0
            int maxStatus = (zeroCount[max_column] > 0) ? 1 : ((negCount[max_column] % 2 == 0) ? 2 : 0);
            int curStatus = (zeroCount[i] > 0) ? 1 : ((negCount[i] % 2 == 0) ? 2 : 0);

            if (curStatus > maxStatus) 
            {
                max_column = i;
            } 
            else if (curStatus == maxStatus) 
            {
                if (curStatus == 2) 
                {
                    // 양수 vs 양수: 크기가 큰 쪽 (logSum 큰 쪽)
                    if (logSum[max_column] <= logSum[i]) 
                    {
                        max_column = i;
                    }
                } 
                else if (curStatus == 0) 
                {
                    // 음수 vs 음수: 0에 더 가까운 쪽 (logSum 작은 쪽)
                    if (logSum[max_column] >= logSum[i]) 
                    {
                        max_column = i;
                    }
                }
                else 
                {
                    // 0 vs 0: 오른쪽(큰 인덱스) 우선
                    max_column = i;
                }
            }
        }
        
        std::cout << (max_column + 1) << "\n";
    }
}
