#include <iostream>

int main()
{
    int numberA;
    int numberB;
    int numberC;
    scanf("%d", &numberA);
    scanf("%d", &numberB);
    scanf("%d", &numberC);

    printf("%d\n", (numberA + numberB) % numberC);
    printf("%d\n", ((numberA % numberC) + (numberB % numberC)) % numberC);
    printf("%d\n", (numberA * numberB) % numberC);
    printf("%d\n", ((numberA % numberC) * (numberB % numberC)) % numberC);
}