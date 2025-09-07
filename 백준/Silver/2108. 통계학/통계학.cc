#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

int getArithmetic(const std::vector<int> &numbers)
{
    int size = numbers.size();
    if (size <= 0)
    {
        return 0;
    }
    
    double sum = 0;
    for (int number : numbers)
    {
        sum += number;
    }
    
    double arithmetic = sum / size;
    return round(arithmetic);
}

int getMedian(const std::vector<int> &numbers)
{
    int size = numbers.size();
    if (size <= 0)
    {
        return 0;
    }
    
    return numbers[size / 2];
}

int getMode(const std::vector<int> &numbers)
{
    std::unordered_map<int, int> numberMap;
    for (int number : numbers)
    {
        numberMap[number]++;  
    }
    
    // 최빈값 찾기
    int mode = 0;
    int maxCount = -1;
    for (const std::pair<const int, int> &entry : numberMap)
    {
        if (entry.second > maxCount)
        {
            maxCount = entry.second;
            mode = entry.first;
        }
    }
    
    // 최빈값 모으기
    std::vector<int> modes;
    for (const auto &entry : numberMap)
    {
        if (entry.second == maxCount)
        {
            modes.push_back(entry.first);
        }
    }

    // 최빈값 정렬
    std::sort(modes.begin(), modes.end());
    int modeSize = modes.size();
    if (modeSize <= 0)
    {
        return 0;
    }
    else if (modes.size() == 1)
    {
        return modes[0];
    }
    else
    {
        return modes[1];
    }
}

int getRange(const std::vector<int> &numbers)
{
    if (numbers.empty())
    {
        return 0;
    }
    
    return numbers.back() - numbers.front();
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int count = 0;
    std::cin >> count;
    
    std::vector<int> numbers;
    while (count--)
    {
        int number = 0;
        std::cin >> number;
        
        numbers.push_back(number);
    }
    
    // 정렬
    std::sort(numbers.begin(), numbers.end());
    
    // 산술평균
    int arithmetic = getArithmetic(numbers);
    // 중앙값
    int median = getMedian(numbers);
    // 최빈값
    int mode = getMode(numbers);
    // 범위
    int range = getRange(numbers);
    
    std::cout << arithmetic << "\n"
              << median << "\n"
              << mode << "\n"
              << range;
}