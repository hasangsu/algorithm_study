#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<int> posVector;
    for (int index = 0; index < count; index++)
    {
        int pos = 0;
        std::cin >> pos;
        
        posVector.push_back(pos);
    }
    
    // 중복제거 및 정렬
    std::set<int> posSet(posVector.begin(), posVector.end());
    
    // 압축 정보 저장
    std::unordered_map<int, int> posMap;
    int temp = 0;
    for (int pos : posSet)
    {
        posMap[pos] = temp;
        temp++;
    }

    // 압축 정보 출력
    for (int pos : posVector)
    {
        std::cout << posMap[pos] << " ";
    }
}