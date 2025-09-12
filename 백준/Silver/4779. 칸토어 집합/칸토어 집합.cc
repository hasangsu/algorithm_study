#include <iostream>
#include <cmath>

void cantor(int number) 
{
	if (number == 0)
	{
		std::cout << "-";
		return;
	}

    cantor(number - 1);
    
    int size = pow(3, number - 1);
	for (int i = 0; i < size; i++)
	{
	    std::cout << " ";
	}
	
	cantor(number - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int number = 0;
    while (std::cin >> number) 
    {
        cantor(number);
        std::cout << "\n";
    }
}