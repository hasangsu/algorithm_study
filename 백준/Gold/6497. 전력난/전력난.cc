#include <iostream>
#include <vector>
#include <algorithm>

struct edge
{
    int s;
    int e;
    int w;
};

bool compare(const edge &a, const edge &b)
{
    return a.w < b.w;
}

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
    
    while (true)
    {
        int m = 0;
        int n = 0;
        std::cin >> m >> n;
        if (m == 0 && n == 0)
        {
            break;
        }
        
        std::vector<edge> edges;
        std::vector<int> parent(m + 1);
        for (int i = 0; i <= m; i++)
        {
            parent[i] = i;
        }
        
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            int s = 0;
            int e = 0;
            int w = 0;
            std::cin >> s >> e >> w;
            
            total += w;
            edges.push_back({s, e, w});
        }
        
        std::sort(edges.begin(), edges.end(), compare);
        
        int cost = 0;
        for (const edge &target : edges)
        {
            int s = target.s;
            int e = target.e;
            int w = target.w;
            
            int p1 = findParent(s, parent);
            int p2 = findParent(e, parent);
            if (p1 != p2)
            {
                unionParent(p1, p2, parent);
                cost += w;
            }
        }
        
        std::cout << (total - cost) << "\n";
    }
}