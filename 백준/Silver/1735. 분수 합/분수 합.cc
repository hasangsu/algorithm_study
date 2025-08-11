#include <iostream>

struct Fraction {
    int numerator = 0;   // 분자
    int denominator = 0; // 분모
};

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

long long lcm(long long a, long long b)
{
    return a * b / (gcd(a,b));
}

int main()
{
    Fraction fractionA;
    Fraction fractionB;
    std::cin >> fractionA.numerator >> fractionA.denominator;
    std::cin >> fractionB.numerator >> fractionB.denominator;

    // 공통 분모
    long long commonDenominator = lcm(fractionA.denominator, fractionB.denominator);
    
    // 공통 분자
    long long commonNumerator = (fractionA.numerator * (commonDenominator / fractionA.denominator)) +
                                (fractionB.numerator * (commonDenominator / fractionB.denominator));
                                
    // 기약 분수
    Fraction result;
    result.numerator = commonNumerator / gcd(commonDenominator, commonNumerator);
    result.denominator = commonDenominator / gcd(commonDenominator, commonNumerator);
    
    std::cout << result.numerator << " " << result.denominator;
}