#include <iostream>
#include <vector>
#include <deque>

int main()
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
    int count = 0;
    std::cin >> count;
    
    std::vector<int> types(count);
    for (int index = 0; index < count; index++)
    {
        int type = 0;
        std::cin >> type;
        
        types[index] = type;
    }
    
    std::deque<int> deques;
    for (int index = 0; index < count; index++)
    {
        int data = 0;
        std::cin >> data;
        
        if (types[index] == 0)
        {
            deques.push_front(data);
        }
    }
    
    int insertCount = 0;
    std::cin >> insertCount;
    for (int index = 0; index < insertCount; index++)
    {
        int insertNumber = 0;
        std::cin >> insertNumber;
        
        deques.push_back(insertNumber);
    }
    
    for (int index = 0; index < insertCount; index++)
    {
        std::cout << deques[index] << " ";
    }
}