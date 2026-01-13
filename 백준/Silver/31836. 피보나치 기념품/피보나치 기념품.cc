#include <iostream>
#include <vector>

void result_print(const std::vector<int> result)
{
    int count = result.size();
    std::cout << count << "\n";
    
    for (int i : result)
    {
        std::cout << i << " ";
    }
    
    std::cout << "\n";
}

int main()
{
    int N = 0;
    std::cin >> N;

    std::vector<int> serim;
    std::vector<int> seonju;
    int start = 0;
    int m = N % 3;
    if (m == 0)
    {
        // ex, N = 3
        // 0 1 1 2
        int index = 3;
        start = 4;
        seonju.push_back(index);
        serim.push_back(index - 1);
        serim.push_back(index - 2);
    }
    else if (m == 1)
    {
        // ex, N = 4
        // 0 1 1 2 3
        int index = 4;
        start = 5;
        seonju.push_back(index);
        serim.push_back(index - 1);
        serim.push_back(index - 2);
    }
    else if (m == 2)
    {
        // ex, N = 2
        // 0 1 1
        int index = 2;
        start = 3;
        seonju.push_back(index);
        serim.push_back(index - 1);
    }
    else
    {
        return 0;
    }
    
    for (int i = start; i <= N; i+=3)
    {
        seonju.push_back(i + 2);
        serim.push_back(i);
        serim.push_back(i + 1);
    }
    
    result_print(serim);
    result_print(seonju);
}