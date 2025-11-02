#include <iostream>
#include <vector>
#include <algorithm>

int getMinimumTime(const std::vector<int> &ps)
{
   int result = 0;
   int prefix = 0;
   for (const int p : ps)
   {
       prefix += p;
       result += prefix;
   }
   
   return result;
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    std::vector<int> ps;
    ps.reserve(n);
    while (n--)
    {
        int p = 0;
        std::cin >> p;
        
        ps.push_back(p);
    }
    
    // ATM 인출하는데 필요한 시간이 빠른것부터 오름차순 정렬
    std::sort(ps.begin(), ps.end());
    
    int result = getMinimumTime(ps);
    std::cout << result;
}