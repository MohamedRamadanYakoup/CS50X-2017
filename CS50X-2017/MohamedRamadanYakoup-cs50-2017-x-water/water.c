#include <stdio.h>
#include <cs50.h>

int main (void)
{
    // get input
    int minutes;
    do
    {
        printf("Minutes: ");
        minutes = get_int();
    }
    while(minutes < 0);
    
    //calculates bottels
    int bottels = minutes*192/16;
    
    printf("Bottels: %i\n", bottels);
}