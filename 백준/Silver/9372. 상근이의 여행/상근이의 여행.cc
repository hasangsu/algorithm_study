#include <iostream>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;

    while (T--) 
    {
        int N = 0;
        int M = 0;
        std::cin >> N >> M;
        
        for (int i = 0; i < M; i++) 
        {
            int s = 0;
            int e = 0;
            std::cin >> s >> e;
        }

        // 모든 국가(N)를 방문하는 최소 비행기 수는 무조건 N-1
        std::cout << N - 1 << "\n";
    }
}