#include <iostream>

int main()
{
    int hour;
    int minute;
    scanf("%d", &hour);
    scanf("%d", &minute);

    minute -= 45;
    if (minute < 0)
    {
        hour -= 1;
        if (hour < 0)
        {
            hour = 23;    
        }
        
        minute += 60;
    }
    
    printf("%d %d", hour, minute);
}