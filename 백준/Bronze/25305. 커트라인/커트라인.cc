#include <iostream>

int main()
{
    int count = 0;
    int prize = 0;
    std::cin >> count >> prize;
    
    int examinees[count] = { 0, };
    for (int index = 0; index < count; index++)
    {
        int examinee = 0;
        std::cin >> examinee;
        
        examinees[index] = examinee;
    }
    
    // 내림차순 정렬
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (examinees[j] < examinees[j + 1])
            {
                std::swap(examinees[j], examinees[j + 1]);
            }
        }
    }
    
    int cutOff = examinees[prize - 1];
    std::cout << cutOff;
}