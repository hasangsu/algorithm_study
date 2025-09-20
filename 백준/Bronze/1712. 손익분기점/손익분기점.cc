#include <iostream>

int main()
{
    long long fixedCosts = 0;
    long long variableCosts = 0;
    long long notebookCosts = 0;
    std::cin >> fixedCosts >> variableCosts >> notebookCosts;
    
    if (notebookCosts <= variableCosts) 
    {
        std::cout << -1;
    } 
    else 
    {
        long long result = (fixedCosts / (notebookCosts - variableCosts)) + 1;
        std::cout << result;
    }
}