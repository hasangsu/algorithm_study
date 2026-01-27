#include <iostream>
#include <vector>

int main()
{
    int A = 0;
    int B = 0;
    std::cin >> A >> B;
    
    std::vector<int> v;
    v.push_back(0);
    
    int num = 1;
    while (v.size() <= 1000)
    {
        for (int i = 0; i < num; i++)
        {
            v.push_back(num);
        }
        num++;
    }
    
    int result = 0;
    for (int i = A; i <= B; i++)
    {
        result += v[i];
    }
    
    std::cout << result;
}