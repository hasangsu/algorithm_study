#include <iostream>
#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(const char *s, int l, int r)
{
    count++;
    
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main()
{
    int testcase = 0;
    std::cin >> testcase;
    
    while (testcase--)
    {
        std::string text = "";
        std::cin >> text;
        
        count = 0;
        
        int r_palindrome = isPalindrome(text.c_str());
        int r_count = count;
        
        std::cout << r_palindrome << " " << r_count << "\n";
    }
}