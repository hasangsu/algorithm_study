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

    int N = 0;
    int M = 0;
    std::cin >> N >> M;

    std::vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) 
    {
        for (int j = 1; j <= N; j++) 
        {
            int connected;
            std::cin >> connected;
            
            if (connected == 1) 
            {
                unionParent(i, j, parent);
            }
        }
    }

    int startNode;
    std::cin >> startNode;
    
    int root = findParent(startNode, parent);
    
    bool possible = true;
    
    for (int i = 1; i < M; i++) 
    {
        int nextNode;
        std::cin >> nextNode;
        
        if (root != findParent(nextNode, parent)) 
        {
            possible = false;
            break;
        }
    }

    if (possible)
    {
        std::cout << "YES";
    }
    else
    {
        std::cout << "NO";
    }
}