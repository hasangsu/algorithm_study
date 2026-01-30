#include <iostream>
#include <vector>

int main()
{
    // 참여 인원
    int N = 0;
    // 보성이
    int K = 0;
    std::cin >> N >> K;
    
    std::vector<bool> visited(N, false);
    std::vector<int> targets(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> targets[i];
    }
    
    int current = 0;
    int result = 1;
    while (true)
    {
        if (visited[current])
        {
            result = -1;
            break;
        }
        
        // 보성이를 가리키면
        if (targets[current] == K)
        {
            break;
        }
        
        // 방문 확인
        visited[current] = true;
        
        // 다음 지목 확인
        int next = targets[current];
        current = next;
        result++;
    }
    
    std::cout << result;
}