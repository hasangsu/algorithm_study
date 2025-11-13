#include <iostream>
#include <vector>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int t = 0;
    std::cin >> t;
    
    while (t--)
    {
        int m = 0;
        std::cin >> m;
    
        int count = 0;
        std::vector<int> results;
        
        std::priority_queue<int, std::vector<int>, std::less<int>> left;
        std::priority_queue<int, std::vector<int>, std::greater<int>> right;
        for (int i = 1; i <= m; i++)
        {
            int e = 0;
            std::cin >> e;
            
            // 삽입
            if ((left.empty()) || (e <= left.top()))
            {
                left.push(e);
            }
            else
            {
                right.push(e);
            }
            
            // 정렬
            if (left.size() > right.size() + 1)
            {
                int left_top = left.top();
                left.pop();
                
                right.push(left_top);
            }
            
            if (right.size() > left.size())
            {
                int right_top = right.top();
                right.pop();
                
                left.push(right_top);
            }
            
            // 결과 저장
            if (i % 2 != 0)
            {
                count++;
                results.push_back(left.top());
            }
        }
        
        // 결과 출력
        std::cout << count << "\n";
        for (int i = 0; i < results.size(); i++)
        {
            if ((i > 0) && (i % 10 == 0))
            {
                std::cout << "\n";
            }
            
            std::cout << results[i] << " ";
        }
        std::cout << "\n";
    }
}