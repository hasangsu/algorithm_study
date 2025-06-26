#include <iostream>
#include <vector>

int main()
{
    while (true)
    {
        int number = 0;
        std::cin >> number;
        
        // 종료 조건
        if (number == -1)
        {
            break;
        }
        
        // 약수 구하기
        std::string correct = std::to_string(number) + " = ";
        bool isFirst = true;
        
        int sum = 0;
        for (int index = 1; index <= (number / 2); index++)
        {
            if (number % index == 0)
            {
                if (index * index == number)
                {
                    sum += (index * 2);
                }
                else
                {
                    sum += index;
                }
                
                if (!isFirst)
                {
                    correct += " + ";
                }
                correct += std::to_string(index);
                isFirst = false;
            }
        }
        
        if (sum == number)
        {
            std::cout << correct << "\n";
        }
        else
        {
            std::cout << std::to_string(number) + " is NOT perfect." << "\n";
        }
    }
}