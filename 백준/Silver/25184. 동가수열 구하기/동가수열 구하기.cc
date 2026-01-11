#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    int mid = N / 2;

    for (int i = 1; i <= mid; i++) 
    {
        std::cout << mid + i << " " << i << " ";
    }

    if (N % 2 != 0) 
    {
        std::cout << N;
    }

    return 0;
}