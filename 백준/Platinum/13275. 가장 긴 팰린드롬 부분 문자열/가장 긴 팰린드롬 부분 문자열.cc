#include <iostream>
#include <string>
#include <vector>

int manacher(const std::string &s)
{
    std::string temp = "#";
    for (const char &c : s)
    {
        temp += c;
        temp += "#";
    }
    
    int length = temp.length();
    std::vector<int> r(length, 0);
    int center = 0;
    int right = 0;
    
    for (int i = 0; i < length; i++)
    {
        if (i <= right)
        {
            // 팰린드롬 영역 안에 있다면 재사용할수도?
            // 현재 내 위치에서 중앙기준으로 정반대편에 있는 인덱스
            int mirror = 2 * center - i;
            r[i] = std::min(r[mirror], right - i);
        }
        
        // 현재 내 위치 기준으로 팰린드롬 확장
        while (i - r[i] - 1 >= 0 &&
               i + r[i] + 1 < length &&
               temp[i - r[i] - 1] == temp[i + r[i] + 1]) 
       {
           r[i]++;
       }
       
       // 새로운 팰린드롬
       if (i + r[i] > right) 
       {
            center = i;
            right = i + r[i];
        }
    }
    
    int max = 0;
    for (const int i : r)
    {
        max = std::max(max, i);
    }
    
    return max;
}

int main()
{
    std::string s = "";
    std::cin >> s;
    
    int result = manacher(s);
    std::cout << result;
}