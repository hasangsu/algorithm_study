#include <iostream>
#include <climits>

int main()
{
    int count = 0;
    int number = 0;
    std::cin >> count >> number;
    
    int cards[count];
    for (int index = 0; index < count; index++)
    {
        int card = 0;
        std::cin >> card;
        
        cards[index] = card;
    }
    
    int minDiff = INT_MAX;
    int result = 0;
    for (int selectA = 0; selectA < count; selectA++)
    {
        for (int selectB = selectA + 1; selectB < count; selectB++)
        {
            for (int selectC = selectB + 1; selectC < count; selectC++)
            {
                int sum = cards[selectA] + cards[selectB] + cards[selectC];
                if (number < sum)
                {
                    continue;
                }
                
                int diff = std::abs(number - sum);
                if (diff < minDiff)
                {
                    minDiff = diff;
                    result = sum;
                }
            }
        }
    }
    
    std::cout << result;
}