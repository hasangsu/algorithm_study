#include <iostream>
#include <vector>

int main()
{
    int T = 0;
    std::cin >> T;
    
    while (T--)
    {
        int N = 0;
        std::cin >> N;
        
        // 부모 설정
        std::vector<int> p(N + 1, 0);
        // 방문 설정
        std::vector<bool> v(N + 1, false);
        for (int i = 1; i < N; i++)
        {
            int s = 0;
            int e = 0;
            std::cin >> s >> e;
            p[e] = s;
        }
        
        // 목표 노드
        int n1 = 0;
        int n2 = 0;
        std::cin >> n1 >> n2;
        
        // 공통 부모 노드 탐색
        int result = 0;
        v[n1] = true;
        while (n1 != 0)
        {
            n1 = p[n1];
            v[n1] = true;
        }
        
        while (true)
        {
            if (v[n2] == true)
            {
                // 처음 공통 부모 발견
                result = n2;
                break;
            }
            
            n2 = p[n2];
        }
        
        std::cout << n2 << "\n";
    }
}