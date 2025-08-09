#include <iostream>
#include <set>

int main()
{
    int setACount = 0;
    int setBCount = 0;
    std::cin >> setACount >> setBCount;
    
    // 집합 A 만들기
    std::set<int> setA;
    for (int index = 0; index < setACount; index++)
    {
        int number = 0;
        std::cin >> number;
        
        setA.insert(number);
    }
    
    // 집합 B 만들기
    std::set<int> setB;
    for (int index = 0; index < setBCount; index++)
    {
        int number = 0;
        std::cin >> number;
        
        setB.insert(number);
    }
    
    // A-B 집합 만들기
    std::set<int> differenceAB = setA;
    for (int number : setB) {
        differenceAB.erase(number);
    }
    
    // B-A 집합 만들기
    std::set<int> differenceBA = setB;
    for (int number : setA) {
        differenceBA.erase(number);
    }
    
    int result = differenceAB.size() + differenceBA.size();
    std::cout << result;
}