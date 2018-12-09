#include <stdio.h>
#include <cs50.h>
#include <math.h>

float greedy(float n);

int main (void)
{
    //get input
    float c;
    do 
    {
        printf("How much change is owed?\n");
        c = get_float();
    }
    while(c < 0);
    
    greedy(c);
}

//Greedy Functions
float greedy(float dollars)
{
    float cent; 
    int coins = 0;
    
    cent = round (dollars*100.0);
    
    while(cent >= 25)
    {
        coins++;
        cent = cent - 25;
    }
    
    while(cent >= 10)
    {
        coins++;
        cent = cent - 10;
    }
    
    while(cent >= 5)
    {
        coins++;
        cent = cent - 5;
    }
    
    while(cent >= 1)
    {
        coins++;
        cent = cent - 1;
    }
    printf("%i\n", coins);
    
     return 0;
}