#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Project
{
    std::string name;
    int score;
    int risk;
    int cost;
    long long scholarship;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 학생수
    int n = 0;
    std::cin >> n;
    
    std::vector<Project> projects(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> projects[i].name >> projects[i].score >> projects[i].risk >> projects[i].cost;
        
        long long numerator = (long long)projects[i].score * projects[i].score * projects[i].score;
        long long denominator = (long long)projects[i].cost * (projects[i].risk + 1);
        projects[i].scholarship = numerator / denominator;
    }
    
    std::sort(projects.begin(), projects.end(), [](const Project& a, const Project& b) 
    {
        // 장학 점수 내림차순
        if (a.scholarship != b.scholarship) 
        {
            return a.scholarship > b.scholarship; 
        }
        
        // 프로젝트 비용 오름차순
        if (a.cost != b.cost) 
        {
            return a.cost < b.cost;
        }
        
        // 이름 사전 순 오름차순
        return a.name < b.name;
    });
    
    std::cout << projects[1].name;
}