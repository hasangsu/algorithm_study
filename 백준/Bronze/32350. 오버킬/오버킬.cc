#include <iostream>
#include <vector>

int main()
{
    int count = 0;
    int damage = 0;
    int percent = 0;
    std::cin >> count >> damage >> percent;
    
    std::vector<int> hps;
    for (int i = 0; i < count; i++)
    {
        int hp = 0;
        std::cin >> hp;
        
        hps.push_back(hp);
    }
    
    int turn = 0;
    for (int i = 0; i < count; i++)
    {
        if (hps[i] <= 0)
        {
            continue;
        }
        
        int hit = (hps[i] + damage - 1) / damage;
        turn += hit;
        
        int overkill = (hit * damage) - hps[i];
        if ((i + 1 < count) &&
            (0 < overkill))
        {
            int append_damage = (overkill * percent) / 100;
            hps[i + 1] -= append_damage;
        }
    }
    
    std::cout << turn;
}