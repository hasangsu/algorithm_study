#include <iostream>
#include <vector>

int main()
{
    int count = 0;
    int target = 0;
    std::cin >> count >> target;
    
    std::vector<int> people;
    for (int index = 1; index <= count; index++)
    {
        people.push_back(index);
    }
    
    std::vector<int> josephus;
    std::vector<int>::iterator it = people.begin();
    while (!people.empty())
    {
        // 삭제 대상 선정
        for (int i = 1; i < target; i++) 
        {
            it++;
            
            if (it == people.end()) 
            {
                it = people.begin();
            }
        }
        
        // 삭제
        josephus.push_back(*it);
        it = people.erase(it);
        if (it == people.end())
        {
            it = people.begin();
        }
    }
    
    std::cout << "<";
    for (size_t i = 0; i < josephus.size(); i++) 
    {
        std::cout << josephus[i];
        if (i != josephus.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ">" << std::endl;
}