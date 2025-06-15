#include <iostream>

int main()
{
    int row = 9;
    int column = 9;
    int max = 0;
    int maxRow = 0;
    int maxColumn = 0;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            int element = 0;
            std::cin >> element;
            
            if (max <= element)
            {
                max = element;
                maxRow = rowIndex + 1;
                maxColumn = columnIndex + 1;
            }
        }
    }
    
    std::cout << max << "\n";
    std::cout << maxRow << " " << maxColumn;
}