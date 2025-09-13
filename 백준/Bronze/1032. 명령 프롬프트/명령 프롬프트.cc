#include <iostream>
#include <vector>
#include <set>

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<std::string> files;
    while (count--)
    {
        std::string file = "";
        std::cin >> file;
        
        files.push_back(file);
    }
    
    // 대표 파일명 & 길이
    std::string baseFile = "";
    int length = 0;
    if (!files.empty())
    {
        baseFile = files[0];
        length = files[0].length();
    }
    
    std::set<int> diffSet;
    int size = files.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            std::string file1 = files[i];
            std::string file2 = files[j];
            
            for (int k = 0; k < length; k++)
            {
                if (file1[k] != file2[k])
                {
                    diffSet.insert(k);
                }
            }
        }
    }
    
    for (int i : diffSet)
    {
        if (baseFile != "")
        {
            baseFile[i] = '?';
        }
    }
    
    std::cout << baseFile;
}