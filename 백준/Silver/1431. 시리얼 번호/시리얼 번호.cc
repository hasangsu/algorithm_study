#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int get_digit_sum(const std::string &s)
{
    int sum = 0;
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            sum += c - '0';
        }
    }
    
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    std::vector<std::string> serials(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> serials[i];
    }

    std::sort(serials.begin(), serials.end(), [](const std::string& a, const std::string& b) 
    {
        
        // 길이 비교
        if (a.length() != b.length())
        {
            return a.length() < b.length();
        }

        // 숫자의 합 비교
        int sum_a = get_digit_sum(a);
        int sum_b = get_digit_sum(b);
        if (sum_a != sum_b)
        {
            return sum_a < sum_b;
        }

        // 사전순 비교
        return a < b;
    });

    for (const std::string &s : serials)
    {
        std::cout << s << "\n";
    }
}