#include <iostream>

int main()
{
    double N = 0.0; // 원금
    double B = 0.0; // 이자
    double M = 0.0; // 목표
    while (std::cin >> N >> B >> M)
    {
        int years = 0;
        double amount = N;

        while (amount < M)
        {
            amount += amount * (B / 100.0);
            years++;
        }
        
        std::cout << years << "\n";
    }
}