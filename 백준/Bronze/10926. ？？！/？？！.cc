#include <string>
#include <iostream>

int main()
{
    std::string id;
    std::cin >> id;
    id.append("\?\?\!");
    std::cout << id << std::endl;
}