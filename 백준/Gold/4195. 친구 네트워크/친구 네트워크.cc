#include <iostream>
#include <vector>
#include <unordered_map>

int findParent(int x, std::vector<int> &parent) 
{
    if (parent[x] == x) 
    {
        return x;
    }
    
    return parent[x] = findParent(parent[x], parent);
}

int unionParent(int a, int b, std::vector<int> &parent, std::vector<int> &count)
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a == b)
    {
        return count[a];
    }
    
    parent[b] = a;
    count[a] += count[b];
    
    return count[a];
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int testcase = 0;
    std::cin >> testcase;
    
    int size = 200001;
    std::vector<int> parent(size);
    std::vector<int> count(size);
    
    while (testcase--)
    {
        int F = 0;
        std::cin >> F;
        
        std::unordered_map<std::string, int> nameMap;
        int id = 0;
        
        for (int i = 0; i < F; i++)
        {
            std::string name1 = "";
            std::string name2 = "";
            std::cin >> name1 >> name2;
            
            if (nameMap.find(name1) == nameMap.end()) 
            {
                nameMap[name1] = id;
                parent[id] = id;
                count[id] = 1;
                id++;
            }
            if (nameMap.find(name2) == nameMap.end()) 
            {
                nameMap[name2] = id;
                parent[id] = id;
                count[id] = 1;
                id++;
            }
            
            int id1 = nameMap[name1];
            int id2 = nameMap[name2];
            int result = unionParent(id1, id2, parent, count);
            std::cout << result << "\n";
        }
    }
}