#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int whitePaperX = 100;
    int whitePaperY = 100;
    int whitePaper[whitePaperX][whitePaperY] = {0, };
    for (int countIndex = 0; countIndex < count; countIndex++)
    {
        int colorPaperX = 0;
        int colorPaperY = 0;
        std::cin >> colorPaperX >> colorPaperY;
        
        for (int colorPaperXIndex = (colorPaperX - 1); colorPaperXIndex < (colorPaperX - 1 + 10); colorPaperXIndex++)
        {
            for (int colorPaperYIndex = (colorPaperY - 1); colorPaperYIndex < (colorPaperY - 1 + 10); colorPaperYIndex++)
            {
                whitePaper[colorPaperXIndex][colorPaperYIndex] = 1;
            }
        }
    }
    
    int result = 0;
    for (int whitePaperXIndex = 0; whitePaperXIndex < whitePaperX; whitePaperXIndex++)
    {
        for (int whitePaperYIndex = 0; whitePaperYIndex < whitePaperY; whitePaperYIndex++)
        {
            if (whitePaper[whitePaperXIndex][whitePaperYIndex] == 1)
            {
                result++;
            }
        }
    }
    
    std::cout << result;
}