#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Point 
{
    long long x;
    long long y;
};

struct Edge 
{
    int s;
    int e;
    double w;
};

bool compareEdges(const Edge &a, const Edge &b) 
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

    int N = 0;
    int M = 0;
    std::cin >> N >> M;

    std::vector<int> parent(N + 1);
    std::vector<Point> gods(N + 1);
    for (int i = 1; i <= N; i++) 
    {
        std::cin >> gods[i].x >> gods[i].y;
        parent[i] = i;
    }

    // 이미 연결되어있는것들 (비용 0)
    for (int i = 0; i < M; i++) 
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        unionParent(s, e, parent);
    }

    std::vector<Edge> edges;
    for (int i = 1; i <= N; i++) 
    {
        for (int j = i + 1; j <= N; j++) 
        {
            double dx = (double)(gods[i].x - gods[j].x);
            double dy = (double)(gods[i].y - gods[j].y);
            double dist = sqrt(dx * dx + dy * dy);

            edges.push_back({i, j, dist});
        }
    }

    // 크루스칼 사전 필요 (오름차순 정렬)
    sort(edges.begin(), edges.end(), compareEdges);
    
    double cost = 0.0;
    for (int i = 0; i < edges.size(); i++) 
    {
        int s = edges[i].s;
        int e = edges[i].e;
        double w = edges[i].w;
        
        if (findParent(s, parent) != findParent(e, parent)) 
        {
            unionParent(s, e, parent);
            cost += w;
        }
    }

    std::cout << std::fixed << std::setprecision(2) << cost << "\n";
}