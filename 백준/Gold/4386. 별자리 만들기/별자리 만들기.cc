#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct star
{
    double x;
    double y;
};

struct edge
{
    int s;
    int e;
    double w;
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
    int n = 0;
    std::cin >> n;
    
    std::vector<int> parent(n + 1);
    std::vector<star> stars(n);
    std::vector<edge> edges;
    
    for (int i = 0; i <=  n; i++)
    {
        parent[i] = i;
    }
    
    for (int i = 0; i < n; i++)
    {
        std::cin >> stars[i].x >> stars[i].y; 
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dx = stars[i].x - stars[j].x;
            double dy = stars[i].y - stars[j].y;
            double dist = sqrt(pow(dx, 2) + pow(dy, 2));

            edges.push_back({i, j, dist});
        }
    }
    
    std::sort(edges.begin(), edges.end(), compare);
    
    double cost;
    for (const edge &target : edges)
    {
        int s = target.s;
        int e = target.e;
        double w = target.w;
        
        int p1 = findParent(s, parent);
        int p2 = findParent(e, parent);
        if (p1 != p2)
        {
            unionParent(p1, p2, parent);
            cost += w;
        }
    }
    
    std::cout << std::fixed << std::setprecision(2) << cost;
}