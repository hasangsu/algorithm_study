#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::unordered_map<std::string, char> mos;
    mos[".-"] = 'A';
    mos["-..."] = 'B';
    mos["-.-."] = 'C';
    mos["-.."] = 'D';
    mos["."] = 'E';
    mos["..-."] = 'F';
    mos["--."] = 'G';
    mos["...."] = 'H';
    mos[".."] = 'I';
    mos[".---"] = 'J';
    mos["-.-"] = 'K';
    mos[".-.."] = 'L';
    mos["--"] = 'M';
    mos["-."] = 'N';
    mos["---"] = 'O';
    mos[".--."] = 'P';
    mos["--.-"] = 'Q';
    mos[".-."] = 'R';
    mos["..."] = 'S';
    mos["-"] = 'T';
    mos["..-"] = 'U';
    mos["...-"] = 'V';
    mos[".--"] = 'W';
    mos["-..-"] = 'X';
    mos["-.--"] = 'Y';
    mos["--.."] = 'Z';
    mos[".----"] = '1';
    mos["..---"] = '2';
    mos["...--"] = '3';
    mos["....-"] = '4';
    mos["....."] = '5';
    mos["-...."] = '6';
    mos["--..."] = '7';
    mos["---.."] = '8';
    mos["----."] = '9';
    mos["-----"] = '0';
    mos["--..--"] = ',';
    mos[".-.-.-"] = '.';
    mos["..--.."] = '?';
    mos["---..."] = ':';
    mos["-....-"] = '-';
    mos[".--.-."] = '@';

    int N = 0;
    std::cin >> N;
    
    while (N--)
    {
        std::string i = "";
        std::cin >> i;
        std::cout << mos[i];
    }
}