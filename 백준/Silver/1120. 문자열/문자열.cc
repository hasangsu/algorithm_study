#include <iostream>

int getDiff(const std::string &x, const std::string &y)
{
    int result = 0;
    int x_size = x.size();
    int y_size = y.size();
    if (x_size == y_size)
    {
        // 두 글자의 길이가 같을 때
        for (int i = 0; i < x_size; i++)
        {
            if (x[i] != y[i])
            {
                result++;
            }
        }
    }
    else
    {
        // 두 글자의 길이가 다를 때 (x는 y보다 작거나 같다)
        int maxMatch = 0;
        int maxIndex = 0;
        for (int i = 0; i <= y_size - x_size; ++i)
        {
            int matchCount = 0;
            for (int j = 0; j < x_size; ++j)
            {
                if (x[j] == y[i + j])
                    matchCount++;
            }
    
            if (matchCount > maxMatch || 
                (matchCount == maxMatch && i > maxIndex))
            {
                maxMatch = matchCount;
                maxIndex = i;
            }
        }
        
        result = x_size - maxMatch;
    }
    
    return result;
}

int main()
{
    std::string x = "";
    std::string y = "";
    std::cin >> x >> y;
    
    int result = getDiff(x, y);
    std::cout << result;
}