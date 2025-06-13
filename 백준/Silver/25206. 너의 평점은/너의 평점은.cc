#include <iostream>

double getSubjectEvaluation(const std::string &grade)
{
    double result = 0.0;
    if (grade == "A+")
    {
        result = 4.5;
    }
    else if (grade == "A0")
    {
        result = 4.0;
    }
    else if (grade == "B+")
    {
        result = 3.5;
    }
    else if (grade =="B0")
    {
        result = 3.0;
    }
    else if (grade == "C+")
    {
        result = 2.5;
    }
    else if (grade == "C0")
    {
        result = 2.0;
    }
    else if (grade == "D+")
    {
        result = 1.5;
    }
    else if (grade == "D0")
    {
        result = 1.0;
    }
    else
    {
        result = 0.0;
    }
    
    return result;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    double totalSum = 0.0;
    double totalCredit = 0.0;
    for (int index = 0; index < 20; index++)
    {
        std::string subject = "";
        double credit = 0.0;
        std::string grade = "";
        
        std::cin >> subject >> credit >> grade;
        if (grade == "P")
        {
            continue;
        }
        
        totalSum = totalSum + (credit * getSubjectEvaluation(grade));
        totalCredit = totalCredit + credit;
    }
    
    double majorGrade = totalSum / totalCredit;
    std::cout << std::fixed;
    std::cout.precision(6);
    std::cout << majorGrade;
}