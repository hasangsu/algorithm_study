#include <iostream>
#include <vector>

void solve(int start, int end, const std::vector<int> &nodes)
{
    if (end <= start)
    {
        return;
    }
    
    int root = nodes[start];
    int index = start + 1;
    while (index < end)
    {
        if (root < nodes[index])
        {
            break;
        }
        
        index++;
    }
    
    solve(start + 1, index, nodes);
    solve(index, end, nodes);
    std::cout << root << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::vector<int> nodes;
    
    int node = 0;
    while (std::cin >> node)
    {
        nodes.push_back(node);
    }
    
    solve(0, nodes.size(), nodes);
}