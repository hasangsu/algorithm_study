#include <iostream>

void pop(int *heap, int &index)
{
    if (index == 0)
    {
        std::cout << 0 << "\n";
        return;
    }
    
    int max = heap[1];
    heap[1] = heap[index--];
    
    int parent = 1;
    int child = parent * 2;
    while (child <= index)
    {
        if (child + 1 <= index && heap[child] < heap[child + 1])
        {
            child++;
        }

        if (heap[parent] >= heap[child])
        {
            break;
        }
        
        std::swap(heap[parent], heap[child]);
        parent = child;
        child = parent * 2;
    }
    
    std::cout << max << "\n";
}

void push(int *heap, int x, int &index)
{
    heap[++index] = x;
    
    int child = index;
    int parent = child / 2;
    
    while (child > 1 && heap[parent] < heap[child]) 
    {
		std::swap(heap[parent], heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n = 0;
    std::cin >> n;
    
    int current_index = 0;
    int heap[n];
    while (n--)
    {
        int x = 0;
        std::cin >> x;
        
        if (x == 0)
        {
            // pop
            pop((int *) heap, current_index);
        }
        else
        {
            // push
            push((int *) heap, x, current_index);
        }
    }
}