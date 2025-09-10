#include <iostream>

int inputcnt = 0;

void merge(int* A, int p, int q, int r, int K){
    int tmp[r+2];
    int i = p;
    int j = q + 1;
    int t = 1;
    
    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
        {
            tmp[t++] = A[i++];
        }
        else
        {
            tmp[t++] = A[j++];
        }
    }
    
    while (i <= q)
    {
        tmp[t++] = A[i++];
    }
        
    while(j <= r)
    {
        tmp[t++] = A[j++];
    }
        
    i = p;
    t = 1;
    
    while (i<=r)
    {
        A[i++] = tmp[t++];
        if (++inputcnt==K)
        {
            std::cout << tmp[t-1];
        }
    }
}

void merge_sort(int* A, int start, int end, int K)
{
    int p = start;
    int r = end;
    
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q, K);
        merge_sort(A, q+1, r, K);
        merge(A, p, q, r, K);
    }
}

int main()
{
    int N = 0;
    int K = 0;
    std::cin >> N >> K;
    
    int *A = new int[N];
    for (int i=0; i < N; i++)
    {
        int number = 0;
        std::cin >> number;
        
        A[i] = number;
    }
    
    merge_sort(A, 0, N-1, K);
    if (inputcnt < K)
    {
        std::cout << -1;
    }
}