#include <iostream>
#include <vector>

int main()
{
    int count = 0;
    std::cin >> count;
    
    int result = 0;
    for (int index = 0; index < count; index++)
    {
        std::string text = "";
        std::cin >> text;
        
        if (text.length() <= 2)
        {
            result++;
            continue;
        }
        
        bool isGroup = false;
        for (int sourceIndex = 0; sourceIndex < text.length(); sourceIndex++)
        {
            // aazz
            bool hasCompare = false;
            bool isFindOther = false;
            bool isTempGroup = false;
            char source = text[sourceIndex];
            for (int targetIndex = sourceIndex + 1; targetIndex < text.length(); targetIndex++)
            {
                hasCompare = true;
                char target = text[targetIndex];
                if (source == target)
                {
                    isTempGroup = true;
                    if (isFindOther)
                    {
                        isTempGroup = false;
                        break;
                    }
                }
                else
                {
                    isTempGroup = true;
                    isFindOther = true;
                }
            }
            
            if (!hasCompare)
            {
                isTempGroup = true;
            }
            
            if (isTempGroup)
            {
                isGroup = true;
            }
            else
            {
                isGroup = false;
                break;
            }
        }
        
        if (isGroup)
        {
            result++;
        }
    }
    
    std::cout << result;
}