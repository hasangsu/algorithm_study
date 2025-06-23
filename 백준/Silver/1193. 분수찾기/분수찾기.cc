#include <iostream>

int main()
{
    int order = 0;
    std::cin >> order;
    
    std::string result = "";
    int accumulate = 0;
    int tmp = 0;
    while (true)
    {
        int count = tmp + 1;
        tmp++;
        accumulate += count;
        if (order <= accumulate)
        {
            // 분자 초기화
            int numerator = count;
            
            // 분모 초기화
            int denominator = 1;
            
            
            int select = accumulate;
            while (select)
            {
                if (select == order)
                {
                    break;
                }
                else
                {
                    select--;
                    numerator--;
                    denominator++;
                }
            }
            
            if (count % 2 != 0)
            {
                int reverse = numerator;
                numerator = denominator;
                denominator = reverse;
            }
            
            result = std::to_string(numerator) + "/" + std::to_string(denominator);
            break;
        }
    }
    
    std::cout << result;
}