#include <iostream>
#include <unordered_map>
#include <cctype>
#include <algorithm>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // 도감수
    int countN = 0;
    // 문제수
    int countM = 0;
    std::cin >> countN >> countM;
    
    std::unordered_map<std::string, int> nameMonsterMap;
    std::unordered_map<int, std::string> numberMonsterMap;
    for (int index = 0; index < countN; index++)
    {
        std::string monster = "";
        std::cin >> monster;
        
        nameMonsterMap[monster] = index + 1;
        numberMonsterMap[index + 1] = monster;
    }
    
    // 문제입력
    for (int index = 0; index < countM; index++)
    {
        std::string question = "";
        std::cin >> question;
        
        // 몬스터 이름인지, 번호인지 판단
        bool isNumber = std::all_of(question.begin(), question.end(), ::isdigit);
        if (isNumber)
        {
            // 번호로 몬스터 이름 찾기
            std::cout << numberMonsterMap[std::stoi(question)] << "\n";
        }
        else
        {
            // 이름으로 몬스터 번호 찾기
            std::cout << nameMonsterMap[question] << "\n";
        }

    }
}