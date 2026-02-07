#include <iostream>
#include <vector>
#include <algorithm>

struct Log
{
    // 로그 시간
    int t;
    // 신청 좌석 번호
    int s;
    // 학번
    int n;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 학생수
    int X = 0;
    // 좌석수
    int C = 0;
    // 로그수
    int K = 0;
    std::cin >> X >> C >> K;
    
    std::vector<int> seat(C + 1, 0);
    std::vector<int> student(X + 1, 0);
    
    std::vector<Log> logs;
    for (int i = 0; i < K; i++)
    {
        Log l;
        std::cin >> l.t >> l.s >> l.n;
        
        logs.push_back(l);
    }
    
    // 로그 순서로 오름차순
    std::sort(logs.begin(), logs.end(), [](const Log& a, const Log& b) {
        return a.t < b.t;
    });
    
    for (const Log &l : logs)
    {
        int t = l.t;
        int s = l.s;
        int n = l.n;
        
        // 이미 앉아있는 좌석이라면 지정 불가
        if (seat[s] != 0)
        {
            continue;
        }
        
        // 이미 학생이 어디 앉아 있다면 변경 필요
        if (student[n] != 0)
        {
            int oldS = student[n];
            seat[oldS] = 0;
        }
        
        // 새로 갱신
        seat[s] = n;
        student[n] = s;
    }
    
    for (int i = 1; i <= X; i++)
    {
        int s = student[i];
        if (s != 0)
        {
            std::cout << i << " " << s << "\n";
        }
    }
}