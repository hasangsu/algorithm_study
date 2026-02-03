#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

struct Student
{
    // 학번
    std::string id;
    // 중간고사 점수
    long long midterm;
    // 기말고사 점수
    long long final;
    // 중간고사 + 기말고사를 합계가 총점이 된다.
    long long total;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // N = 학생 수
    // M = A+ 가능한 학생 수
    // X = 중간고사 만점 점수
    // Y = 기말고사 만점 점수
    int N = 0;
    int M = 0;
    long long X = 0;
    long long Y = 0;
    std::cin >> N >> M >> X >> Y;
    
    // 김한양의 학번과 중간고사 점수를 입력받는다.
    Student hanyang;
    hanyang.final = 0;
    hanyang.total = 0;
    std::cin >> hanyang.id >> hanyang.midterm;
    
    // 학생들의 학번과 중간고사 점수를 입력받는다.
    std::vector<long long> totals;
    for (int i = 0; i < N - 1; i++)
    {
        Student s;
        
        std::cin >> s.id >> s.midterm;
        int year = std::stoi(s.id.substr(0, 4));
        if (year != 2024)
        {
            continue;
        }
        
        // 기말고사 점수 = 기말고사 만점 점수 - (중간고사 만점 점수 - 중간고사 점수)
        // 기말고사 점수가 0 보다 작으면 0점으로 처리한다.
        long long final = Y - (X - s.midterm);
        if (final <= 0)
        {
            final = 0;
        }
        // 나머지 학생들의 중간고사 점수 + 기말고사 점수
        s.final = final;
        s.total = s.midterm + s.final;
        
        totals.push_back(s.total);
    }
    
    if (totals.size() < M)
    {
        std::cout << "YES" << "\n";
        std::cout << 0;
        return 0;
    }
    
    std::sort(totals.begin(), totals.end(), std::greater<long long>());
    
    long long cut_line = totals[M - 1];
    long long needed_final = cut_line - hanyang.midterm;
    if (needed_final > Y)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES" << "\n";
        if (needed_final <= 0)
        {
            std::cout << 0;
        }
        else
        {
            std::cout << needed_final;
        }
    }
}