#include <iostream>
#include <stack>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::stack<int> sticks;
    for (int i = 0; i < N; i++)
    {
        int h;
        std::cin >> h;
        sticks.push(h);
    }

    int count = 1;
    int max_height = sticks.top();
    sticks.pop();

    while (!sticks.empty())
    {
        int current_height = sticks.top();
        sticks.pop();

        if (current_height > max_height)
        {
            count++;
            max_height = current_height;
        }
    }

    std::cout << count;
}