#include <iostream>
#include <vector>

void printPreOrder(const std::vector<int> &inOrder, const std::vector<int> &postOrder, const std::vector<int> &pos, int startInOrder, int endInOrder, int startPostOrder, int endPostOrder)
{
    if (endInOrder < startInOrder ||
        endPostOrder < startPostOrder)
    {
        return;
    }
    
    int root = postOrder[endPostOrder];
    std::cout << root << " ";

    // inOrder에서 root의 index    
    int rootIndex = pos[root];
    
    // 왼쪽 - 루트 - 오른쪽
    // 루트 인덱스에서 왼쪽 시작을 빼면 크기
    int size = rootIndex - startInOrder;
    
    // 왼쪽 노드 뭉치에서 순회
    printPreOrder(inOrder, postOrder, pos, startInOrder, rootIndex - 1, startPostOrder, startPostOrder + size - 1);
    // 오른쪽 노드 뭉치에서 순회
    printPreOrder(inOrder, postOrder, pos, rootIndex + 1, endInOrder, startPostOrder + size, endPostOrder - 1); 
}

int main()
{
    int n = 0;
    std::cin >> n;
    
    std::vector<int> inOrder(n);
    std::vector<int> postOrder(n);
    std::vector<int> pos(n + 1);
    
    // inOrder 입력
    for (int i = 0; i < n; i++)
    {
        std::cin >> inOrder[i];
    }
    // postOrder 입력
    for (int i = 0; i < n; i++)
    {
        std::cin >> postOrder[i];
    }
    // 인덱스 판단
    for (int i = 0; i < n; i++)
    {
        pos[inOrder[i]] = i;
    }
    
    printPreOrder(inOrder, postOrder, pos, 0, n - 1, 0, n - 1);
}