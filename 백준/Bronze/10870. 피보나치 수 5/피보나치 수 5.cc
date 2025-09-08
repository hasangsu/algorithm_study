#include <iostream>
#include <vector>

int main()
{
    int order = 0;
    std::cin >> order;
    
    // 피보나치 초기값
    std::vector<int> fibonaccis;
    fibonaccis.push_back(0);
    fibonaccis.push_back(1);
    
    int loop = order;
    while (loop--)
    {
        int size = fibonaccis.size();
        
        int n2 = fibonaccis.at(size - 2);
        int n1 = fibonaccis.at(size - 1);
        int n = n2 + n1;
        
        fibonaccis.push_back(n);
    }
    
    std::cout << fibonaccis.at(order);
}