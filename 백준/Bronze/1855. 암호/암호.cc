#include <iostream>
#include <algorithm>

int main()
{
    int column = 0;
    std::string ciphertext = "";
    std::cin >> column >> ciphertext;
    
    std::string plainText = "";
    bool isReverse = false;
    for (int i = 0; i < ciphertext.length(); i+=column)
    {
        if (isReverse)
        {
            // 오른쪽 → 왼쪽
            std::string chunk = ciphertext.substr(i, column);
            std::reverse(chunk.begin(), chunk.end());
            plainText.append(chunk);
        }
        else
        {
            // 왼쪽 → 오른쪽
            std::string chunk = ciphertext.substr(i, column);
            plainText.append(chunk);
        }
        
        isReverse = !isReverse;
    }
    
    std::string result = "";
    int plainTextRow = plainText.length() / column;
    int plainTextColumn = column;
    for (int i = 0; i < plainTextColumn; i++)
    {
        for (int j = 0; j < plainTextRow; j++)
        {
            result += (plainText[j * column + i]);
        }
    }
    
    std::cout << result;
}