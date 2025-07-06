#include <iostream>

std::string getTypeOfTriangle(int degree1, int degree2, int degree3)
{
    std::string result = "";
    
    if ((degree1 + degree2 + degree3) != 180)
    {
        // 모든 각의 합이 180도가 아닐경우에
        result = "Error";
    }
    else
    {
        // 모든 각의 합이 180도일 경우에
        if ((degree1 == 60) &&
            (degree2 == 60) &&
            (degree3 == 60))
        {
            // 각각의 각이 60일 경우에
            result = "Equilateral";
        }
        else if ((degree1 != degree2) &&
                (degree1 != degree3) &&
                (degree2 != degree3))
        {
            // 각각의 각이 모두 다를 경우에
            result = "Scalene";
        }
        else
        {
            // 두개의 각이 같을 경우에
            result = "Isosceles";
        }
    }
    
    return result;
}

int main()
{
    int degree1 = 0;
    int degree2 = 0;
    int degree3 = 0;
    std::cin >> degree1 >> degree2 >> degree3;
    
    std::string result = getTypeOfTriangle(degree1, degree2, degree3);
    std::cout << result;
}