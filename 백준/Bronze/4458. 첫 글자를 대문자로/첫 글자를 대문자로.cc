#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N  = 0;
    std::cin >> N;
    std::cin.ignore();
    
    for (int i = 0; i < N; i++)
    {
        std::string s = "";
        std::getline(std::cin, s);
        
        s[0] = std::toupper(s[0]);
        
        std::cout << s << "\n";
    }
}