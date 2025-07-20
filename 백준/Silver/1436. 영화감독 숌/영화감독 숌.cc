#include <iostream>

bool check(int source, int number)
{
    // source에 number가 3회이상 연속하는지 확인
    int findCount = 0;
    while (0 < source) 
    {
        int digit = source % 10;
        if (digit == number) 
        {
            findCount++;
            if (3 <= findCount)
            {
                return true;
            }
        }
        else 
        {
            findCount = 0;
        }

        source /= 10;
    }
    
    return false;
}

int main()
{
    int nth = 0;
    std::cin >> nth;
    
    int findNth = 0;
    int count = 666;
    while (true)
    {
        bool result = check(count, 6);
        if (result)
        {
            findNth++;
            if (findNth == nth)
            {
                std::cout << count;
                break;
            }
        }
        
        count++;
    }
}