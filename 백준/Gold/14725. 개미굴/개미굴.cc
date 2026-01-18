#include <iostream>
#include <vector>
#include <map>
#include <string>

struct Trie
{
    std::map<std::string, Trie *> nodes;
};

void insert(Trie *t, const std::vector<std::string> &p)
{
    if (t == nullptr)
    {
        return;
    }
    
    Trie *curr = t;
    for (const std::string &s : p)
    {
        if (curr->nodes.find(s) == curr->nodes.end())
        {
            // 새로운 방
            curr->nodes[s] = new Trie();
        }
        
        curr = curr->nodes[s];
    }
}

void print(const Trie &t, int d)
{   
    for (const std::pair<std::string, Trie *> &p : t.nodes)
    {
        for (int i = 0; i < d; i++) 
        {
            std::cout << "--";
        }
        
        std::cout << p.first;
        std::cout << "\n";
        
        Trie *next = p.second;
        print(*next, d + 1);
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    
    Trie root;
    for (int i = 0; i < N; i++)
    {
        int c = 0;
        std::cin >> c;
        
        std::vector<std::string> p(c);
        for (int j = 0; j < c; j++)
        {
            std::cin >> p[j];
        }
        
        insert(&root, p);
    }
    
    print(root, 0);
}