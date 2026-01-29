#include <iostream>
#include <queue>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    std::queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        q.push(i);
    }
    
    while (!q.empty())
    {
        // 버리기
        int t1 = q.front();
        q.pop();
        
        std::cout << t1 << " ";
        
        if (q.empty())
        {
            break;
        }
        
        // 바닥으로
        int t2 = q.front();
        q.pop();
        q.push(t2);
    }
}