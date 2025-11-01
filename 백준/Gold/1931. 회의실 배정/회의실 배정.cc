#include <iostream>
#include <vector>
#include <algorithm>

int getMaximumMeeting(const std::vector<std::pair<int, int>> &meetings)
{
    int start = meetings[0].second;
    int end = meetings[0].first;
    
    int result = 1;
    for (int i = 1; i < meetings.size(); i++)
    {
        int next_start = meetings[i].second;
        int next_end = meetings[i].first;
        
        if (end <= next_start)
        {
            end = next_end;
            result++;
        }
    }
    
    return result;
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    std::vector<std::pair<int, int>> meetings;
    meetings.reserve(n);
    int start = 0;
    int end = 0;
    while (n--)
    {
        std::cin >> start >> end;
        meetings.emplace_back(end, start);
    }
    
    // 끝나는 시간이 빠른것부터 오름차순 정렬
    std::sort(meetings.begin(), meetings.end());
    
    // 결과
    int result = getMaximumMeeting(meetings);
    std::cout << result;
}