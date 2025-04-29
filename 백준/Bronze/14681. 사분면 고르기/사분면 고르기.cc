#include <iostream>

int main()
{
    int pointX;
    int pointY;
    scanf("%d", &pointX);
    scanf("%d", &pointY);

    if ((0 < pointX) && (0 < pointY))
    {
        printf("1\n");
    }
    else if ((pointX < 0) && (0 < pointY))
    {
        printf("2\n");
    }
    else if ((pointX < 0) && (pointY < 0))
    {
        printf("3\n");
    }
    else
    {
        printf("4\n");
    }
}