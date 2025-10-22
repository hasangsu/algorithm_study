#include <iostream>

// 재귀함수
int count_fib = 0;
// 동적 프로그래밍
int count_fibonacci = 0;
int f[41] = {0};

int fib(int n)
{
    if ((n == 1) ||
        (n == 2))
    {
        count_fib++;
        return 1;
    }
    
    return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n)
{
    for (int i = 3; i <= n; i++)
    {
        count_fibonacci++;
        f[i] = f[i - 1] + f[i - 2];
    }
    
    return f[n];
}

int main()
{
    int number = 0;
    std::cin >> number;
    
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    
    fib(number);
    fibonacci(number);
    
    std::cout<< count_fib << " " << count_fibonacci;
}