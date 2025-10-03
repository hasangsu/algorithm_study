#include <iostream>
#include <string>
#include <algorithm>

std::string stripLeadingZeros(std::string s) 
{
    while (s.size() > 1 && s[0] == '0')
    {
        s.erase(s.begin());
    }
    
    return s;
}

std::string addStrings(const std::string &a, const std::string &b) 
{
    std::string a_ = a;
    std::string b_ = b;
    reverse(a_.begin(), a_.end());
    reverse(b_.begin(), b_.end());

    std::string result = "";
    int carry = 0;

    for (size_t i = 0; i < std::max(a_.size(), b_.size()) || carry; i++) 
    {
        int digitA = (i < a_.size() ? a_[i] - '0' : 0);
        int digitB = (i < b_.size() ? b_[i] - '0' : 0);

        int sum = digitA + digitB + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return stripLeadingZeros(result);
}

std::string subtractStrings(const std::string &a, const std::string &b) 
{
    std::string a_ = a;
    std::string b_ = b;
    reverse(a_.begin(), a_.end());
    reverse(b_.begin(), b_.end());

    std::string result = "";
    int borrow = 0;

    for (size_t i = 0; i < a_.size(); i++) 
    {
        int digitA = a_[i] - '0';
        int digitB = (i < b_.size() ? b_[i] - '0' : 0);

        int diff = digitA - digitB - borrow;
        if (diff < 0) 
        {
            diff += 10;
            borrow = 1;
        } 
        else 
        {
            borrow = 0;
        }
        
        result.push_back(diff + '0');
    }

    while (result.size() > 1 && result.back() == '0')
    {
        result.pop_back();
    }
        
    reverse(result.begin(), result.end());
    return stripLeadingZeros(result);
}

std::string divideBy2(const std::string &a) 
{
    std::string result = "";
    int carry = 0;

    for (size_t i = 0; i < a.size(); i++) 
    {
        int current = carry * 10 + (a[i] - '0');
        result.push_back((current / 2) + '0');
        carry = current % 2;
    }

    return stripLeadingZeros(result);
}

int main() 
{
    std::string a, b;
    std::cin >> a >> b;

    std::string sumAB = addStrings(a, b);
    std::string diffAB = subtractStrings(a, b);

    std::string K = divideBy2(sumAB);
    std::string N = divideBy2(diffAB);

    std::cout << K << "\n" << N << "\n";
}