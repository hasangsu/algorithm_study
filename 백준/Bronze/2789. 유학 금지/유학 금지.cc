#include <iostream>
#include <algorithm>

int main()
{
    std::string s = "";
    std::cin >> s;
    
    std::string cambridge = "CAMBRIDGE";
    s.erase(std::remove_if(s.begin(), s.end(),
        [&cambridge](char c) {
            return cambridge.find(c) != std::string::npos;
        }),
        s.end());
        
    std::cout << s;
}