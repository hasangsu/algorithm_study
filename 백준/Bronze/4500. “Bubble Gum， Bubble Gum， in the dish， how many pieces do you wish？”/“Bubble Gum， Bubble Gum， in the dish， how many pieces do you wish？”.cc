#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

std::string getResult(const std::vector<std::string> &names, const std::string &selector, int count)
{
    std::string result = "";
    
    // selector부터 시작
    std::vector<std::string>::const_iterator it = std::find(names.begin(), names.end(), selector);
    int startIndex = std::distance(names.begin(), it);
    
    // 결과 찾기
    int targetIndex = (startIndex + count - 1) % names.size();
    result = names[targetIndex];
    
    return result;
}

int main()
{
    // 테스트케이스 갯수 입력받고 마지막 개행을 제거한다.
    int testcase = 0;
    std::cin >> testcase;
    std::cin.ignore();
    
    while (testcase--)
    {
        // 다음 한줄 입력에서 사람들의 이름(p) 목록
        std::string name = "";
        std::getline(std::cin, name);
        
        std::istringstream iss(name);
        std::vector<std::string> names;
        while (iss >> name) 
        {
            names.push_back(name);
        }
        
        // 풍선껌 조각의 개수를 선택하는 사람의 이름
        std::string selector = "";
        std::cin >> selector;
        
        // 풍선껌 조각의 개수 n
        int count = 0;
        std::cin >> count;
        std::cin.ignore();
        
        std::string result = getResult(names, selector, count);
        std::cout << result << "\n";
    }
}