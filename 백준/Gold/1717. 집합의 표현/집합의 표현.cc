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

    if (a != b) 
    {
        if (a < b)
        {
            parent[b] = a;
        }
        else
        {
            parent[a] = b;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        // 자기자신을 일단 자기가 부모
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) 
    {
        int op = 0;
        int a = 0;
        int b = 0;
        std::cin >> op >> a >> b;

        if (op == 0) 
        {
            // 합집합
            unionParent(a, b, parent);
        } 
        else if (op == 1)
        {
            // 확인
            if (findParent(a, parent) == findParent(b, parent))
            {
                std::cout << "YES" << "\n";
            } 
            else 
            {
                std::cout << "NO" << "\n";
            }
        }
    }
}