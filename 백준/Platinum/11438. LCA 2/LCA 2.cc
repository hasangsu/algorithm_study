#include <iostream>
#include <vector>

const int max_node = 100001;

std::vector<std::vector<int>> adj(max_node, std::vector<int>());
int parent[20][max_node];
int depth[max_node];
    
void dfs(int current, int prev)
{
    // current : 현재 노드
    // prev : 부모 노드
    depth[current] = depth[prev] + 1;
    parent[0][current] = prev;
    
    // 현재 노드에서 연결
    for (int next : adj[current])
    {
        // 나와 연결된것중에 내 부모면 진행하지 않음
        if (next == prev)
        {
            continue;
        }
        
        // 부모가 아니라면 모두 자식이므로 dfs
        dfs(next, current);
    }
}

int lca(int n1, int n2)
{
    // 펀의상 depth n1이 더 크게
    if (depth[n1] < depth[n2])
    {
        std::swap(n1, n2);
    }
    
    int diff = depth[n1] - depth[n2];
    for (int k = 0;  0 < diff; k++) 
    {
        if (diff % 2 == 1) 
        {
            n1 = parent[k][n1];
        }
        
        diff /= 2;
    }
    
    if (n1 == n2)
    {
        return n1;
    }
    
    for (int k = 19; 0 <= k; k--) 
    {
        // 2^k 번째 조상이 다를 때만 위로 이동!
        if (parent[k][n1] != parent[k][n2]) 
        {
            n1 = parent[k][n1];
            n2 = parent[k][n2];
        }
    }
    
    return parent[0][n1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0;
    std::cin >> N;
    
    for (int i = 0; i < N - 1; i ++)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        adj[s].push_back(e);
        adj[e].push_back(s);
    }
    
    // 트리의 깊이 설정
    // 트리의 부모 설정
    depth[0] = 0;
    dfs(1, 0);
    
    for (int k = 1; k < 20; k++) 
    {
        for (int i = 1; i <= N; i++) 
        {
            if (parent[k - 1][i] != 0) 
            {
                // parent[1][2] = parent[0][parent[0][2]];
                // 2번노드의 조부모 = 2번노드 부모의 부모
                parent[k][i] = parent[k - 1][parent[k - 1][i]];
            }
        }
    }
    
    int M = 0;
    std::cin >> M;
    while (M--)
    {
        int n1 = 0;
        int n2 = 0;
        std::cin >> n1 >> n2;
        
        int result = lca(n1, n2);
        std::cout << result << "\n";
    }
}