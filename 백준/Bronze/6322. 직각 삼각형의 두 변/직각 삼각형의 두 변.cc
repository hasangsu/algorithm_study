#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    int testcase = 1;
    std::cout << std::fixed << std::setprecision(3);
    while (true)
    {
        double lineA = 0;
        double lineB = 0;
        double lineC = 0;
        std::cin >> lineA >> lineB >> lineC;
        
        if ((lineA == 0) &&
            (lineB == 0) &&
            (lineC == 0))
        {
            break;
        }
        
        std::string line = "";
        double length = 0.0;
        
        if ((lineA != -1) &&
            (lineB != -1))
        {
            // A, B가 주어졌을때 C를 구하기
            line = "c";
            length = std::sqrt((lineA * lineA) + (lineB * lineB));
            lineC = length;
        }
        else if ((lineA != -1) &&
            (lineC != -1))
        {
            // A, C가 주어졌을때 B를 구하기
            line = "b";
            length = std::sqrt((lineC * lineC) - (lineA * lineA));
            lineB = length;
        }
        else if ((lineB != -1) &&
            (lineC != -1))
        {
            // B, C가 주어졌을때 A를 구하기
            line = "a";
            length = std::sqrt((lineC * lineC) - (lineB * lineB));
            lineA = length;
        }
        
        std::cout << "Triangle #" << testcase << "\n";
        if ((lineC <= lineA) || (lineC <= lineB))
        {
            std::cout << "Impossible." << "\n\n";
        }
        else
        {
            std::cout << line << " = " << length << "\n\n";
        }
        
        testcase++;
    }
}