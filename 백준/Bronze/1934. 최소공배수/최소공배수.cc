#include <iostream>

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    for (int index = 0; index < count; index++)
    {
        int number1 = 0;
        int number2 = 0;
        std::cin >> number1 >> number2;
        std::cout << lcm(number1, number2) << "\n";
    }
}