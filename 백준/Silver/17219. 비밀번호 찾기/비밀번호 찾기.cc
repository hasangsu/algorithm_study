#include <iostream>
#include <unordered_map>

int main()
{
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    
    std::unordered_map<std::string, std::string> info;
    for (int i = 0; i < N; i++)
    {
        std::string address = "";
        std::string pw = "";
        std::cin >> address >> pw;
        
        info[address] = pw;
    }
    
    for (int i = 0; i < M; i++)
    {
        std::string address = "";
        std::cin >> address;
        
        std::cout << info[address] << "\n";
    }

    return 0;
}