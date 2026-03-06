#include <iostream>
#include <vector>

int yongsikCharge(const std::vector<int> &times)
{
    int charge = 0;
    for (const int time : times)
    {
        if (time < 30)
        {
            charge += 10;
            continue;
        }
        
        int number = (time / 30) + 1;
        charge += (number * 10);
    }
    
    return charge;
}

int minsikCharge(const std::vector<int> &times)
{
    int charge = 0;
    for (const int time : times)
    {
        if (time < 60)
        {
            charge += 15;
            continue;
        }
        
        int number = (time / 60) + 1;
        charge += (number * 15);
    }
    
    return charge;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    std::vector<int> times(N, 0);
    for (int i = 0; i < N; i++)
    {
        std::cin >> times[i];
    }
    
    int yongsik = yongsikCharge(times);
    int minsik = minsikCharge(times);
    if (minsik < yongsik)
    {
        std::cout << "M" << " " << minsik;
    }
    else if (yongsik < minsik)
    {
        std::cout << "Y" << " " << yongsik;
    }
    else
    {
        std::cout << "Y M" << " " << minsik;
    }
}