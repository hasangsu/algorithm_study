#include <iostream>
#include <climits>

int check(int nKg, int mainKg, int subKg)
{
    int result = INT_MAX;
    bool isFind = false;
    for (int mainKgIndex = 0; mainKgIndex <= INT_MAX; mainKgIndex++)
    {
        // mainKg로만 바구니 구성시 초과했는지?
        if (nKg < (mainKgIndex * mainKg))
        {
            break;
        }
        
        for (int subKgIndex = 0; subKgIndex <= INT_MAX; subKgIndex++)
        {
            int sumKg = (mainKgIndex * mainKg) + (subKgIndex * subKg);
            
            // 무게 부족
            if (sumKg < nKg)
            {
                continue;
            }
            
            // 무게 초과 (조합 못찾음)
            if (nKg < sumKg)
            {
                break;
            }
            
            // 적정 무게
            int count = mainKgIndex + subKgIndex;
            if (count < result)
            {
                isFind = true;
                result = count;
            }
        }
    }
    
    return isFind ? result : -1;
}

int main()
{
    int nKg = 0;
    std::cin >> nKg;
    
    int count = check(nKg, 3, 5);
    std::cout << count;
}