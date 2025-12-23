#include <iostream>
#include <vector>

struct Node
{
    std::string n = "";
    std::string l = "";
    std::string r = "";
};

void getPre(int index, const std::vector<Node> &nodes, std::vector<std::string> &result)
{
    result.push_back(nodes[index].n);
    
    if (nodes[index].l != ".")
    {
        int leftIndex = nodes[index].l[0] - 'A';
        getPre(leftIndex, nodes, result);
    }
    
    if (nodes[index].r != ".")
    {
        int rightIndex = nodes[index].r[0] - 'A';
        getPre(rightIndex, nodes, result);
    }
}

void getInorder(int index, const std::vector<Node> &nodes, std::vector<std::string> &result)
{
    if (nodes[index].l != ".")
    {
        int leftIndex = nodes[index].l[0] - 'A';
        getInorder(leftIndex, nodes, result);
    }
    
    result.push_back(nodes[index].n);
    
    if (nodes[index].r != ".")
    {
        int rightIndex = nodes[index].r[0] - 'A';
        getInorder(rightIndex, nodes, result);
    }
}

void getPost(int index, const std::vector<Node> &nodes, std::vector<std::string> &result)
{
    if (nodes[index].l != ".")
    {
        int leftIndex = nodes[index].l[0] - 'A';
        getPost(leftIndex, nodes, result);
    }
    
    
    if (nodes[index].r != ".")
    {
        int rightIndex = nodes[index].r[0] - 'A';
        getPost(rightIndex, nodes, result);
    }
    
    result.push_back(nodes[index].n);
}

void print(const std::vector<std::string> &result)
{
    for (std::string r : result)
    {
        std::cout << r;
    }
    std::cout << "\n";
}

int main()
{
    int N = 0;
    std::cin >> N;
    
    std::vector<Node> nodes(26, Node());
    for (int i = 0; i < N; i++)
    {
        std::string n = "";
        std::string l = "";
        std::string r = "";
        std::cin >> n >> l >> r;
        
        int index = n[0] - 'A';
        nodes[index].n = n;
        nodes[index].l = l;
        nodes[index].r = r;
    }
    
    std::vector<std::string> pre;
    std::vector<std::string> inorder;
    std::vector<std::string> post;
    
    // 순회
    getPre(0, nodes, pre);
    getInorder(0, nodes, inorder);
    getPost(0, nodes, post);
    
    // 출력
    print(pre);
    print(inorder);
    print(post);
}