#include <stdio.h>
int reverse(int number)
{
    int temp;
    while (number)
    {
        temp =(temp + number % 10)*10;
        number /= 10;
    }
    return temp/10;
}