#include <iostream>
#include <vector>

long long getMinimumPrice(int n, long long td, const std::vector<int> &ds, const std::vector<int> &ps)
{
    long long result = 0;
    
    int current_city = 0;
    int next_city = 1;
    int current_p = 0;
    int next_p = 0;
    while (true)
    {
        if (td <= 0)
        {
            break;
        }
        
        int current_p = ps[current_city];
        int next_p = ps[next_city];
        if (next_p <= current_p)
        {
            // 다음 도시의 가격이 더 쌀때
            int d = ds[next_city];
            result += (d * current_p);
            td -= d;
            current_city += 1;
            next_city += 1;
        }
        else
        {
            // 다음 도시의 가격이 더 비쌀때
            int d = ds[next_city];
            result += (d * current_p);
            td -= d;
            next_city += 1;
        }
    }
    
    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 도시 수
    int n = 0;
    std::cin >> n;
    
    std::vector<int> ds;
    ds.reserve(n);
    ds.push_back(1);
    
    std::vector<int> ps;
    ps.reserve(n);
    
    // 도시간 거리
    long long td = 0;
    int d = 0;
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> d;
        
        td += d;
        ds.push_back(d);
    }
    
    // 주윺소의 리터당 가격
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> p;
        ps.push_back(p);
    }
    
    long long result = getMinimumPrice(n, td, ds, ps);
    std::cout << result;
}