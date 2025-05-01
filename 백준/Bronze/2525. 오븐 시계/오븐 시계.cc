#include <iostream>

int main()
{
    int hour;
    int minute;
    int need;
    scanf("%d %d", &hour, &minute);
    scanf("%d", &need);

    minute += need;
    if (59 < minute)
    {
        hour += (minute / 60);
        if (24 <= hour)
        {
            hour -= 24;
        }
        minute = (minute % 60);
    }
    
    printf("%d %d", hour, minute);
}