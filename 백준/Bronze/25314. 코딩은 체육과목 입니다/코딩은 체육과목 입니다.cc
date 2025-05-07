#include <iostream>
#include <string>

int main()
{
    int nByte = 0;
    scanf("%d", &nByte);
    
    if (nByte % 4 == 0)
    {
        std::string result = "";    
        int count = nByte / 4;
        for (int index = 0; index < count; index++)
        {
            if (index == 0)
            {
                result.append("long");
            }
            else
            {
                result.append(" long");
            }
        }
        result.append(" int");
        
        printf("%s\n", result.c_str());
    }
}