#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct memberInfo
{
    int age;
    std::string name;
    
    memberInfo(int age, const std::string &name)
    {
        this->age = age;
        this->name = name;
    }
};

bool compare(const memberInfo &a, const memberInfo &b)
{
    return a.age < b.age;
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<memberInfo> memberList;
    for (int index = 0; index < count; index++)
    {
        int age = 0;
        std::string name = "";
        std::cin >> age >> name;
        
        memberList.emplace_back(age, name);
    }
    
    std::stable_sort(memberList.begin(), memberList.end(), compare);
    
    for (const memberInfo &member : memberList)
    {
        std::cout << member.age << " " << member.name << "\n";
    }
}