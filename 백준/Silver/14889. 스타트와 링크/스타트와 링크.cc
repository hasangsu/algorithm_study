#include <iostream>
#include <climits>
#include <vector>

void updateTeamAttributes(int m, const std::vector<int> &used, const std::vector<int> attributes, int &min)
{
    int teamStart = 0;
    int teamLink = 0;
    
    for (int i = 0; i < m; ++i) 
    {
        for (int j = i + 1; j < m; ++j) 
        {
            if (used[i] == used[j]) 
            {
                int val = attributes[i * m + j] + attributes[j * m + i];
                if (used[i] == 1)
                {
                    teamStart += val;
                }
                else
                {
                    teamLink  += val;
                }
            }
        }
    }

    int diff = std::abs(teamStart - teamLink);
    if (diff < min) 
    {
        min = diff;
    }
}

void dfs(int n, int m, std::vector<int> &path, std::vector<int> &used, const std::vector<int> attributes, int &min)
{
    if (path.size() == (m / 2))
    {
        // update min
        updateTeamAttributes(m, used, attributes, min);
        return;
    }
    
    int need = (m / 2) - (path.size());
    int last = m - need;
    
    for (int i = n; i <= last; i++)
    {
        if (used[i] == 1)
        {
            // 이미 뽑은 사람
            continue;
        }
        
        used[i] = 1;
        path.push_back(i);
        
        dfs(i + 1, m, path, used, attributes, min);
        
        path.pop_back();
        used[i] = 0;
    }
}

int backtracking_dfs(int count, const std::vector<int> attributes)
{
    int min = INT_MAX;
    std::vector<int> path;
    std::vector<int> used(count + 1, 0);
    
    dfs(0, count, path, used, attributes, min);
    
    return min;
}

int main()
{
    int count = 0;
    std::cin >> count;
    
    std::vector<int> attributes;
    for (int i = 0; i < count * count; i++)
    {
        int attribute = 0;
        std::cin >> attribute;
        
        attributes.push_back(attribute);
    }
    
    int min = backtracking_dfs(count, attributes);
    std::cout << min;
}