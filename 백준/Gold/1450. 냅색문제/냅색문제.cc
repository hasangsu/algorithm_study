#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int start, int end, long long sum, const std::vector<int> &objects, std::vector<long long> &partialSum)
{
    if (start == end)
    {
        partialSum.push_back(sum);
        return;
    }
    
    dfs(start + 1, end, sum, objects, partialSum);
    dfs(start + 1, end, sum + objects[start], objects, partialSum);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    int C = 0;
    std::cin >> N >> C;
    
    std::vector<int> objects(N, 0);
    for (int i = 0; i < N; i++)
    {
        int weight = 0;
        std::cin >> weight;
        
        objects[i] = weight;
    }
    
    // 절반 나누기
    std::vector<long long> partialSumA;
    std::vector<long long> partialSumB;
    dfs(0, N / 2, 0, objects, partialSumA);
    dfs(N / 2, N, 0, objects, partialSumB);
    
    // 정렬
    std::sort(partialSumB.begin(), partialSumB.end());
    
    long long count = 0;
    for (const long long sumA : partialSumA)
    {
        // B에서 넣을수있는 최대 무게
        long long target = C - sumA;
        count += std::upper_bound(partialSumB.begin(), partialSumB.end(), target) - partialSumB.begin();
    }
    
    std::cout << count;
}