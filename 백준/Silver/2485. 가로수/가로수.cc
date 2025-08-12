#include <iostream>
#include <vector>

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 가로수 갯수
    int count = 0;
    std::cin >> count;
    
    // 가로수 위치
    std::vector<int> posList;
    for (int index = 0; index < count; index++)
    {
        int pos = 0;
        std::cin >> pos;
        
        posList.push_back(pos);
    }
    
    // 가로수들 간의 간격
    std::vector<int> diffList;
     for (int index = 1; index < count; index++) 
     {
         diffList.push_back(posList[index] - posList[index - 1]);
     }
    
    long long gcdResult = diffList[0];
    for (int index = 1; index < diffList.size(); index++)
    {
        gcdResult = gcd(gcdResult, diffList[index]);
    }
    
    int first = posList[0];
    int last = posList[count - 1];
    int result = (last - first) / gcdResult + 1 - count;
    
    // 결과
    std::cout << result;
}