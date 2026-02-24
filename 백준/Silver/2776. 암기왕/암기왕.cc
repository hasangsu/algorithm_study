#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int T = 0;
    std::cin >> T;
    
    while (T--)
    {
        // note1 구성
        int N = 0;
        std::cin >> N;
        
        std::map<int, int> note1;
        for (int i = 0; i < N; i++)
        {
            int n = 0;
            std::cin >> n;
            
            note1[n]++;
        }
        
        // note2 구성
        int M = 0;
        std::cin >> M;
        for (int i = 0; i < M; i++)
        {
            int m = 0;
            std::cin >> m;
            
            if(note1.find(m) != note1.end()) 
            {
                std::cout << "1" << "\n";
            }
            else
            {
                std::cout << "0" << "\n";
            }
        }
    }
}