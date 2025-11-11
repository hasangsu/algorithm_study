#include <iostream>
#include <vector>
#include <queue>
#include <functional>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    std::cin >> n;
    
    int t = n * n;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    while (t--)
    {
        int e = 0;
        std::cin >> e;
        
        if (pq.size() < n)
        {
            pq.push(e);
        }
        else
        {
            int top = pq.top();
            if (e < top)
            {
                continue;
            }
            else
            {
                pq.pop();
                pq.push(e);
            }
        }
    }
    
    int result = pq.top();
    std::cout << result;
}