#include <iostream>

int main()
{
    std::string croatiaAlpabets[8] = {
      "c=",
      "c-",
      "dz=",
      "d-",
      "lj",
      "nj",
      "s=",
      "z="
    };
    std::string text = "";
    std::cin >> text;
    for (const std::string &alpabet : croatiaAlpabets)
    {
        size_t count = 0;
        size_t pos = 0;
        while ((pos = text.find(alpabet, pos)) != std::string::npos)
        {
            text.replace(pos, alpabet.length(), "?");
        }
    }
    
    std::cout << text.length() << "\n";
}