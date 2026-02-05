#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N = 0;
    std::cin >> N;
    
    bool connected[6][6] = { false, };
    for (int i = 1; i <= N; i++)
    {
        int s = 0;
        int e = 0;
        std::cin >> s >> e;
        
        connected[s][e] = true;
        connected[e][s] = true;
    }
    
    if (N != 3)
    {
        // 여우 사인은 엄지손가락, 중지, 약지 세 손가락을 서로 끝이 맞닿도록 모으고, 검지와 새끼손가락은 다른 손가락과 닿지 않도록 곧게 펴서 여우의 얼굴과 두 귀를 표현한 손 모양'
        // 서로 닿아 있는 손가락 쌍의 개수 3개면 충분하다.
        std::cout << "Woof-meow-tweet-squeek";
    }
    else
    {
        // 여우의 입 부분 (엄지1, 중지3, 약지4)이 서로 연결되어 있는지 확인
        bool isFox = connected[1][3] && connected[3][4] && connected[4][1];
        if (isFox)
        {
            std::cout << "Wa-pa-pa-pa-pa-pa-pow!";
        }
        else
        {
            std::cout << "Woof-meow-tweet-squeek";
        }
    }
}