#include <iostream>

int main()
{
    int row = 0;
    int column = 0;
    std::cin >> row >> column;
    
    int matrixA[row][column] = {0, };
    int matrixB[row][column] = {0, };

    // set matrixA 
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            int element = 0;
            std::cin >> element;
            
            matrixA[rowIndex][columnIndex] = element;
        }
    }
    
    // set matrixB
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            int element = 0;
            std::cin >> element;
            
            matrixB[rowIndex][columnIndex] = element;
        }
    }
    
    // sum matrix
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        for (int columnIndex = 0; columnIndex < column; columnIndex++)
        {
            std::cout << (matrixA[rowIndex][columnIndex] + matrixB[rowIndex][columnIndex]) << " ";
        }
        std::cout << "\n";
    }
}