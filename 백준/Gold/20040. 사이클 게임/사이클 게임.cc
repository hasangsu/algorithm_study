#include <iostream>
#include <vector>

int findParent(int x, std::vector<int> &parent) 
{
    if (parent[x] == x) 
    {
        return x;
    }
    
    return parent[x] = findParent(parent[x], parent);
}

void unionParent(int a, int b, std::vector<int> &parent) 
{
    a = findParent(a, parent);
    b = findParent(b, parent);
    
    if (a < b) 
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    
    // 부모 설정
    std::vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    
    // 간선 설정 및 판단
    for (int i = 0; i < m; i++)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        // 각각의 노드의 부모 찾기
        int sParent = findParent(s, parent);
        int eParent = findParent(e, parent);
        if (sParent == eParent)
        {
            std::cout << i + 1;
            return 0;
        }
        
        unionParent(s, e, parent);
    }
    
    std::cout << 0;
    return 0;
}