#include <iostream>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int testcase = 0;
    while (count--)
    {
        testcase++;
        
        int expect = 0;
        int real = 0;
        std::cin >> expect >> real;
    
        std::string drought = "";
        if (expect <= real)
        {
            drought = "no drought";
        }
        else
        {
            long long threshold = real * 5LL;
            while (expect > threshold) 
            {
                drought += "mega ";
                threshold *= 5LL;
            }
            
            drought += "drought";
        }
        
        std::cout << "Data Set " << testcase << ":\n";
        std::cout << drought << "\n\n";
    }
}